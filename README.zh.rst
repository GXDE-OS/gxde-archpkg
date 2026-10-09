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

许可证
-----

PKGBUILD files文件以 `MIT <./LICENSE>`_ 协议授权（仅适用于PKGBUILD文件），不适用于仓库内任何Git补丁或任何部件的源码。
