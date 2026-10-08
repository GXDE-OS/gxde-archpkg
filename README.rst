GXDE Arch Packaging
===================

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
- **flakewm-git**: GXDE's Wayland compositor.

Behavior
--------

All the PKGBUILD pulls the latest tag, so the version pulled should be the same to GXDE internal testing APT source.

Install Order
-------------

#. gxde-dtk5-git
#. gxde-dtk6-git
#. gxde-dtk2-git
#. gxde-dtk2-qt6-git
#. gxde-infra-git
#. flakewm-git

License
-------

Those PKGBUILD files are licensed under `MIT <./LICENSE>`_, this applys only to the PKGBUILD file, not any git patch or source code of the component.