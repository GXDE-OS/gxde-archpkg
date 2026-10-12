/*
 * Copyright (C) 2026 CharOfString <root@charofstring.cc>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLibraryInfo>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSysInfo>
#include <QTextStream>
#include <QUrl>
#include <QVersionNumber>

#include <iostream>

#include <qbytearrayview.h>
#include <qcontainerfwd.h>
#include <qjsonobject.h>
#include <qlibraryinfo.h>
#include <qnetworkaccessmanager.h>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include <qstringliteral.h>
#include <qsysinfo.h>
#include <sysexits.h>
#include <archive.h>
#include <archive_entry.h>

// Exit statuses are truncated to 8 bits, keep these within 0-255 and clear of
// the sysexits.h range (64-78).
#define EX_LOCAL_VERSION_NEWER 100
#define EX_LOCAL_VERSION_OLDER 101

namespace {

enum class ExtractionMethod {
  kFromArchJson = 0,
  kFromPacmanDatabase = 1
};

struct OnlineUpstream {
  QString distro_info;
  QUrl upstream_url;
  ExtractionMethod preferred_approach;
};

QString PraseField(const QByteArray& desc, const char* key) {
  const QList<QByteArray> lines = desc.split('\n');
  const qsizetype i = lines.indexOf(QByteArray(key));
  if (i >= 0 && i + 1 < lines.size()) {
    return QString::fromUtf8(lines.at(i + 1).trimmed());
  }

  return QString();
}

QString SanitizeVersionString(QString full) {
  full = full.mid(full.indexOf(QLatin1Char(':')) + 1);
  const qsizetype dash = full.lastIndexOf(QLatin1Char('-'));
  return dash > 0 ? full.left(dash) : full;
}

}  // namespace

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  std::cout << "[I] (Main) Init: Welcome! This application checks "
    << "whether your Qt version matches Archlinux upstream." << std::endl;
  std::cout << "[I] (Main) Init: If your Qt version is newer than remote "
    << "then this program returns " << EX_LOCAL_VERSION_NEWER << '.'
    << std::endl;
  std::cout << "[I] (Main) Init: If your Qt version is older than remote "
    << "then this program returns " << EX_LOCAL_VERSION_OLDER << '.'
    << std::endl;
  std::cout << "[I] (Main) Init: If your Qt version matches remote version "
    << "then this program returns " << EX_OK << '.'
    << std::endl;
  std::cout << "[I] (Main) Init: Any other return codes indicates an error."
    << std::endl;

  const QVersionNumber linked_qt_runtime_ver = QLibraryInfo::version();
  const QString cpu_arch = QSysInfo::buildCpuArchitecture();
  const QString pkg_base = QStringLiteral("qt%1-base").arg(
    linked_qt_runtime_ver.majorVersion());

  OnlineUpstream query_gen;
  if (cpu_arch == QLatin1String("x86_64")) {
    query_gen = {
      QStringLiteral("Arch Linux x86_64"),
      QUrl(QStringLiteral(
        "https://archlinux.org/packages/extra/x86_64/%1/json/").arg(pkg_base)),
      ExtractionMethod::kFromArchJson
    };
  } else if (cpu_arch == QLatin1String("arm64")) {
    query_gen = {
      QStringLiteral("Arch Linux ARM aarch64"),
      QUrl(QStringLiteral(
        "http://mirror.archlinuxarm.org/aarch64/extra/extra.db")),
      ExtractionMethod::kFromPacmanDatabase
    };
  } else {
    // We don't support other archtectures other than amd64 & aarch64.
    std::cerr << "[E] (Main) Init: Unsupportted archtecture, HALTED!"
      << std::endl;
    exit(EX_UNAVAILABLE);
  }

  QNetworkAccessManager network_access_manager_gen;
  QNetworkRequest request_gen(query_gen.upstream_url);
  request_gen.setHeader(QNetworkRequest::UserAgentHeader,
    QStringLiteral("qtver/1.0"));
  request_gen.setAttribute(QNetworkRequest::RedirectPolicyAttribute,
    QNetworkRequest::NoLessSafeRedirectPolicy);
  request_gen.setTransferTimeout(30000);

  QNetworkReply* reply_gen = network_access_manager_gen.get(request_gen);
  QObject::connect(reply_gen, &QNetworkReply::finished, &app, [&]() {
    reply_gen->deleteLater();
    if (reply_gen->error() != QNetworkReply::NoError) {
      std::cerr
        << "[E] (Query) NetworkQuery: An error occurred while accessing "
        << "upstream.\n"
        << "                             >> " << "Upstream: "
        << query_gen.upstream_url.toString().toStdString() << '\n'
        << "                             >> " << "Error: "
        << reply_gen->errorString().toStdString() << std::endl;
      std::cerr << "[E] (Main) Query: Halted due to network issue."
        << std::endl;
      exit(EX_IOERR);
    }

    QString reply_read;
    if (query_gen.preferred_approach == ExtractionMethod::kFromArchJson) {
      const QJsonObject obj = QJsonDocument::fromJson(reply_gen->readAll())
        .object();
      const QString version = obj.value(QLatin1String("pkgver")).toString();
      const QString pkgrel = obj.value(QLatin1String("pkgrel")).toString();

      if (version.isEmpty() || pkgrel.isEmpty()) {
        reply_read = version;
      } else {
        reply_read = version + QLatin1Char('-') + pkgrel;
      }
    } else {
      archive* archive_gen = archive_read_new();
      archive_read_support_filter_all(archive_gen);  // gzip, zstd, whatever.
      archive_read_support_format_tar(archive_gen);

      // libarchive reads from this buffer lazily, so it must outlive
      // archive_gen.
      const QByteArray reply_body = reply_gen->readAll();
      if (archive_read_open_memory(archive_gen, reply_body.constData(),
          size_t(reply_body.size())) == ARCHIVE_OK) {
        const QByteArray prefix = pkg_base.toUtf8() + '-';
        archive_entry* entry_gen = nullptr;
        while (archive_read_next_header(archive_gen,
            &entry_gen) == ARCHIVE_OK) {
          QByteArray path(archive_entry_pathname(entry_gen));
          if (path.startsWith("./")) {
            path.remove(0, 2);
          }

          if (!path.startsWith(prefix) || !path.endsWith("/desc")) {
            continue;
          }

          QByteArray desc(qsizetype(archive_entry_size(entry_gen)),
            Qt::Uninitialized);
          const la_ssize_t n = archive_read_data(archive_gen, desc.data(),
            size_t(desc.size()));
          if (n < 0) {
            break;
          }
          desc.truncate(n);

          if (PraseField(desc, "%NAME%") == pkg_base) {
            reply_read = PraseField(desc, "%VERSION%");
            break;
          }
        }
      }
      archive_read_free(archive_gen);
    }

    const QVersionNumber upstream_version = QVersionNumber::fromString(
      SanitizeVersionString(reply_read));
    if (upstream_version.isNull()) {
      std::cerr << "[E] (Main) Compare: Could not compare version due to "
        << "upstream version read is null, halted." << std::endl;
      exit(EX_DATAERR);
    }

    const int comparation_result = QVersionNumber::compare(
      linked_qt_runtime_ver, upstream_version);
    if (comparation_result > 0) {
      std::cout << "[I] (Main) Compare: Local version is newer than upstream."
        << std::endl;
      std::cout << "[I] (Main) LifeCycle: Exiting normally..." << std::endl;
      exit(EX_LOCAL_VERSION_NEWER);
    } else if (comparation_result < 0) {
      std::cout << "[I] (Main) Compare: Local version is older than upstream."
        << std::endl;
      std::cout << "[I] (Main) LifeCycle: Exiting normally..." << std::endl;
      exit(EX_LOCAL_VERSION_OLDER);
    } else {
      std::cout << "[I] (Main) Compare: Local version is the same as upstream."
        << std::endl;
      std::cout << "[I] (Main) LifeCycle: Exiting normally..." << std::endl;
      exit(EX_OK);
    }
  });

  return app.exec();
}
