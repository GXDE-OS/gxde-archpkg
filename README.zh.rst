GXDE Archlinux打包
==================

.. image:: /docs/screenshot.png
    :alt: Screenshot of GXDE desktop environment on Nyarch

.. 注意::
   我们并不打算出一个基于Archlinux的发行版，但我们计划提供Arch版本的GXDE桌面环境安装包

简介
----

本仓库含有GXDE在AUR上的所有 ``PKGBUILD`` 文件，每个Git子模块都是一个独立的部件包。

组件
----

必需组件
~~~~~~~
- **gxde-dtk2-git**: GXDE的DTK2框架。
- **gxde-dtk5-git**: GXDE的DTK5框架。
- **gxde-dtk6-git**: GXDE的DTK6框架。
- **gxde-dtk2-qt6-git**: DTK2Widget-Qt6.
- **gxde-infra-git**: GXDE的基础设施包。
- **gxde-core-git**: GXDE的桌面核心组件。
- **flakewm-git**: GXDE的Wayland合成器。

可选套件
~~~~~~~
- **gxde-display-manager-git**: GXDE的显示管理器（GXDM）。
- **gxde-system-monitor-git**: GXDE的系统监视器。
- **gxde-calculator-git**: GXDE的计算器。
- **gxde-picker-git**: GXDE的取色器。
- **gxde-music-git**: GXDE的音乐播放器。
- **gxde-log-viewer-git**: GXDE的日志查看器。
- **gxde-image-viewer-git**: GXDE的图片查看器。
- **gxde-filetransfer-git**: GXDE的文件传输客户端。
- **gxde-voice-recorder-git**: GXDE的录音工具。
- **gxde-reader-git**: GXDE的文档查看器，fork 自 deepin-reader。
- **gxde-font-manager-git**: GXDE的字体安装器。
- **gxde-system-assistant-git**: GXDE的系统助手。
- **gxde-screen-recorder-git**: GXDE的截图录屏工具，fork 自 deepin-screen-recorder。
- **gxde-boot-maker-git**: GXDE的启动盘制作工具。
- **gxde-clone-git**: GXDE的备份还原工具，fork 自 deepin-clone。
- **gxde-calendar-git**: GXDE的日历。
- **gxde-hardware-viewer-git**: GXDE的硬件查看器。
- **gxde-ocr-git**: GXDE的OCR工具。
- **gxde-dict-git**: GXDE的词典。
- **gxde-editor-git**: GXDE的文本编辑器。
- **gxde-dlna-caster-git**: GXDE的投屏工具。
- **gxde-roller-git**: GXDE的归档管理器，fork 自 deepin-compressor。
- **gxde-camera-git**: GXDE的相机，fork 自 deepin-camera。
- **dde-clipboard-git**: GXDE的剪贴板管理器，fork 自 dde-clipboard。
- **spark-webapp-runtime-git**: 星火 WebApp 运行时，下载助手依赖它。
- **gxde-downloader-neo-git**: GXDE的下载助手。

行为
----

所有PKGBUILD均会检出最新的tag，检出的版本应该与内测源的一致。

安装顺序
-------

#. gxde-dtk5-git
#. gxde-dtk6-git
#. gxde-dtk2-git
#. gxde-dtk2-qt6-git
#. gxde-infra-git
#. gxde-core-git
#. flakewm-git
#. gxde-display-manager-git
#. gxde-system-monitor-git
#. gxde-calculator-git
#. gxde-picker-git
#. gxde-music-git
#. gxde-log-viewer-git
#. gxde-image-viewer-git
#. gxde-filetransfer-git
#. gxde-voice-recorder-git
#. gxde-reader-git
#. gxde-font-manager-git
#. gxde-system-assistant-git
#. gxde-screen-recorder-git
#. gxde-boot-maker-git
#. gxde-clone-git
#. gxde-calendar-git
#. gxde-hardware-viewer-git
#. gxde-ocr-git
#. gxde-dict-git
#. gxde-editor-git
#. gxde-dlna-caster-git
#. gxde-roller-git
#. gxde-camera-git
#. dde-clipboard-git
#. spark-webapp-runtime-git
#. gxde-downloader-neo-git

许可证
-----

PKGBUILD files文件以 `MIT <./LICENSE>`_ 协议授权（仅适用于PKGBUILD文件），不适用于仓库内任何Git补丁或任何部件的源码。
