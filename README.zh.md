# GXDE Archlinux Packaging
> 欢迎来到GXDE Archlinux打包区！！我们目前正在努力让GXDE适配Archlinux！

![Screenshot](./docs/screenshots.png)

## 介绍
欢迎来到GXDE Archlinux打包区的主页，本仓库储存所有GXDE Arch相关的打包与CI脚本。

虽然我们并不打算发行一个基于Archlinux的distro，我们还是会提供GXDE的Arch打包。

## 安装
### GXDE Archlinux源
我们在 https://repo.gxde.top/gxde-arch/ 上面提供一个Archlinux源，包含 `x86_64` 与 `aarch64`（Arch Linux ARM）的预编译软件包。

将以下内容追加到 `/etc/pacman.conf` 末尾：
```ini
[gxde]
SigLevel = Optional TrustAll
Server = https://repo.gxde.top/gxde-arch/$arch
```

然后刷新数据库并更新系统：
```shell
$ sudo pacman -Syu
```

可以用以下命令列出源中的所有软件包：
```shell
$ pacman -Sl gxde
```

当前这个源没有签名，因此需要`SigLevel = Optional TrustAll`。我们计划在不久补上Arch包签名。

### 通过AUR
> 当前，AUR上的GXDE包由@CharOfString维护。
>
> AUR包会从源码编译一切，所以如果跑了三个钟头还没结束是很正常的。
>
> AUR与GXDE Archlinux源是二选一的——这些包的上游仓库是同一个。

请安装以下必要包：
```shell
$ paru -S gxde-dtk5-git gxde-dtk6-git gxde-dtk2-git gxde-dtk2-qt6-git gxde-infra-git gxde-core-git flakewm-git gxde-display-manager-git
```

以下包是可选的：
- gxde-dtk5widget-dev-git
- spark-webapp-runtime-git
- gxde-voice-recorder-git
- gxde-system-monitor-git
- gxde-system-assistant-git
- gxde-screen-recorder-git
- gxde-roller-git
- gxde-reader-git
- gxde-picker-git
- gxde-ocr-git
- gxde-music-git
- gxde-log-viewer-git
- gxde-image-viewer-git
- gxde-hardware-viewer-git
- gxde-font-manager-git
- gxde-filetransfer-git
- gxde-editor-git
- gxde-dtk2widget-dev-git
- gxde-downloader-neo-git
- gxde-dlna-caster-git
- gxde-display-manager-git
- gxde-dict-git
- gxde-clone-git
- gxde-camera-git
- gxde-calendar-git
- gxde-calculator-git
- gxde-boot-maker-git
- flakewm-git
- dde-clipboard-git

## 本仓库的分支
您可能会发现这个仓库几乎是空的。这完全正常，我们针对不同的任务使用了不同的分支，需要切换分支才能看到各个子项目。

### 活跃分支
- **master**: 本分支。
- **aur**: 储存AUR打包信息。
- **qt_version_probe**: 小型探针程序的源代码，用于检测GXDE Arch软件的Qt版本是否与Arch Linux系统中的版本不匹配。

### 不活跃分支
- **dtk5_batchbuild_arch**: DTK5的批量构建CI脚本，已移动至本分支。

## 许可证
您可以在每个分支中找到LICENSE文件，LICENSE文件仅对当前分支生效。
