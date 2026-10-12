## GXDE Archlinux Qt Probe
### Introduction
This application checks whether the Qt version it was compiled against matches
Archlinux upstream, so it can tell when packages built alongside it need a rebuild.
`gxde_arch_qt_probe` checks `qt6-base`, `gxde_arch_qt5_probe` checks `qt5-base`.
- If your Qt version is newer than remote then this program returns 100.
- If your Qt version is older than remote then this program returns 101.
- If your Qt version matches remote version then this program returns 0.

### License
*GXDE Archlinux Qt Probe* is licensed under *[GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007](./LICENSE)*.