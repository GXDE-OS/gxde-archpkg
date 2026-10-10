GXDE Arch Packaging
===================

.. image:: /docs/screenshot.png
    :alt: Screenshot of GXDE desktop environment on Nyarch

.. note::
   We're not planning to provide a full distro based on Arch, but we ported the desktop environment to Archlinux.

Introduction
------------

This repository contains the ``PKGBUILD`` file that we submitted to the AUR repository. Each git submodule is a package component.

Parts
-----

- **gxde-dtk2-git**: GXDE's fork of DTK2 framework.
- **gxde-dtk5-git**: GXDE's fork of DTK5 framework.
- **gxde-dtk6-git**: GXDE's fork of DTK6 framework.
- **gxde-dtk2-qt6-git**: DTK2Widget-Qt6.
- **gxde-infra-git**: Infrastructure components for GXDE.
- **gxde-core-git**: Core components for GXDE desktop.
- **flakewm-git**: GXDE's Wayland compositor.
- **gxde-display-manager-git**: GXDE's display manager (GXDM).
- **gxde-system-monitor-git**: GXDE's system monitor.
- **gxde-calculator-git**: GXDE's calculator.
- **gxde-picker-git**: GXDE's color picker.
- **gxde-music-git**: GXDE's music player.
- **gxde-log-viewer-git**: GXDE's system log viewer.
- **gxde-image-viewer-git**: GXDE's image viewer.
- **gxde-filetransfer-git**: GXDE's file transfer client.
- **gxde-voice-recorder-git**: GXDE's voice recorder.
- **gxde-reader-git**: GXDE's document viewer, forked from deepin-reader.
- **gxde-font-manager-git**: GXDE's font installer.
- **gxde-system-assistant-git**: GXDE's system assistant.
- **gxde-screen-recorder-git**: GXDE's screenshot and screen recording tool, forked from deepin-screen-recorder.
- **gxde-boot-maker-git**: GXDE's boot USB stick maker.
- **gxde-clone-git**: GXDE's backup and restore tool, forked from deepin-clone.
- **gxde-calendar-git**: GXDE's calendar.
- **gxde-hardware-viewer-git**: GXDE's hardware viewer.
- **gxde-ocr-git**: GXDE's OCR tool.
- **gxde-dict-git**: GXDE's dictionary.
- **gxde-editor-git**: GXDE's text editor.
- **gxde-dlna-caster-git**: GXDE's DLNA screen casting tool.
- **gxde-roller-git**: GXDE's archive manager, forked from deepin-compressor.
- **gxde-camera-git**: GXDE's camera, forked from deepin-camera.
- **dde-clipboard-git**: GXDE's clipboard manager, forked from dde-clipboard.
- **spark-webapp-runtime-git**: Spark WebApp runtime, required by gxde-downloader-neo-git.
- **gxde-downloader-neo-git**: GXDE's download manager.

Behavior
--------

All the PKGBUILD pulls the latest tag, so the version pulled should be the same to GXDE internal testing APT source.

Install Order
-------------

Required
~~~~~~~~
#. gxde-dtk5-git
#. gxde-dtk6-git
#. gxde-dtk2-git
#. gxde-dtk2-qt6-git
#. gxde-infra-git
#. gxde-core-git
#. flakewm-git

Optional
~~~~~~~~
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

License
-------

Those PKGBUILD files are licensed under `MIT <./LICENSE>`_, this applys only to the PKGBUILD file, not any git patch or source code of the component.