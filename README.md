# GXDE Arch Meta Packages

Meta packages of the GXDE Arch Linux repository. They carry the same package
names and cover the same components as the AUR bundles of the same name, but
pull the individual packages from the GXDE Arch repository instead of building
everything themselves.

| Meta package | Pulls in |
| --- | --- |
| `gxde-dtk5-git` | GXDE DTK5 |
| `gxde-dtk6-git` | GXDE DTK6 and its Qt 6 platform plugins and integration |
| `gxde-dtk2-git` | GXDE DTK2 on top of DTK5 |
| `gxde-dtk2-qt6-git` | The Qt 6 port of DTK2 |
| `gxde-infra-git` | GXDE infrastructure components |
| `gxde-core-git` | GXDE desktop core components |
| `gxde-desktop-extras` | GXDE desktop applications (the optional AUR packages) |
| `gxde-desktop-full` | All of the meta packages above |

The packages are built by GitHub Actions; run the workflow by hand to publish
a new version.
