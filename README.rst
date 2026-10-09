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

License
-------

Those PKGBUILD files are licensed under `MIT <./LICENSE>`_, this applys only to the PKGBUILD file, not any git patch or source code of the component.