# GXDE Arch Meta Packages

Meta packages of the GXDE Arch Linux repository. They cover the same
components as the `-git` AUR bundles of the same name (and replace them on
upgrade), but pull the individual packages from the GXDE Arch repository
instead of building everything themselves.

| Meta package | Pulls in |
| --- | --- |
| `gxde-dtk5` | GXDE DTK5 |
| `gxde-dtk6` | GXDE DTK6 and its Qt 6 platform plugins and integration |
| `gxde-dtk2` | GXDE DTK2 on top of DTK5 |
| `gxde-dtk2-qt6` | The Qt 6 port of DTK2 |
| `gxde-infra` | GXDE infrastructure components |
| `gxde-core` | GXDE desktop core components |
| `gxde-desktop-extras` | GXDE desktop applications (the optional AUR packages) |
| `gxde-desktop-full` | All of the meta packages above |

The packages are built by GitHub Actions; run the workflow by hand to publish
a new version.
