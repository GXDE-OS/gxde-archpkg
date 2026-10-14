# GXDE Archlinux Packaging
> Welcome to GXDE on Archlinux!! We're currently trying our best effort to port GXDE on Arch!

![Screenshot](./docs/screenshots.png)

## Introduction
Welcome to the Homepage of GXDE Archlinux packaging, this repository hosts all the packaging & CI for GXDE Arch.

Although we're not planning to provide a full Archlinux-based distro, we're now working on the Archlinux packaging.

## Installation
### GXDE Archlinux Pacman Source
We provide an Archlinux pacman source at https://repo.gxde.top/gxde-arch/, with prebuilt packages for `x86_64` and `aarch64` (Arch Linux ARM).

Append the following to the end of `/etc/pacman.conf`:
```ini
[gxde]
SigLevel = Optional TrustAll
Server = https://repo.gxde.top/gxde-arch/$arch
```

Then refresh the databases and upgrade:
```shell
$ sudo pacman -Syu
```

You can list all packages in the source with:
```shell
$ pacman -Sl gxde
```

Currently the source is not signed, hence `SigLevel = Optional TrustAll`. A signing will be provided soon.

#### Installing the Desktop
Install the whole desktop with one meta package:
```shell
$ sudo pacman -S gxde-desktop-full
```

Or pick the meta packages you need; the DTK and infrastructure meta packages are pulled in automatically:

| Meta package | Contents |
| --- | --- |
| `gxde-core-git` | GXDE desktop core components, with the Flake Wayland compositor |
| `gxde-desktop-extras` | GXDE applications, the GXDE display manager (`gxdm-git`) and more |
| `gxde-desktop-full` | Everything above |

Then enable the GXDE display manager (part of `gxde-desktop-extras`; install `gxdm-git` yourself if you only installed `gxde-core-git`):
```shell
$ sudo systemctl disable display-manager.service  # only if another display manager is enabled
$ sudo systemctl enable gxdm.service
```

Reboot and choose the `GXDE` session (X11) or `gxde-flakewm` (Wayland) at the login screen.

These meta packages carry the same names as the AUR bundles below, so installing them replaces the AUR packages.

### AUR
> Currently, AUR packages are maintained by @CharOfString.
>
> The AUR packages complies everything from aource, so it is normal if the process took 3 hours.
>
> You must choose between the AUR and the GXDE Arch Linux repository —— the upstream repositories for these packages are the same.

Please install these packages:
```shell
$ paru -S gxde-dtk5-git gxde-dtk6-git gxde-dtk2-git gxde-dtk2-qt6-git gxde-infra-git gxde-core-git flakewm-git gxde-display-manager-git
```

And here is a list of optional packages:
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

## Repository Branch
You may find this repository almost empty. That's completely normal for we use branches for different tasks. You will need to switch the branches to see the sub-projects.

### Active Branches
- **master**: This branch is for this welcome message.
- **aur**: Stores the AUR packaging info.
- **qt_version_probe**: The source code of a small probe that detects if the GXDE arch software's Qt version mismatches from Archlinux.
- **meta_packages**: The Arch meta packages.

### Inactive Branch
- **dtk5_batchbuild_arch**: The batch build CI script for DTK5, now moved to this branch.

## License
You may find a license file on each branch, each license file is good for the corresponding branch only.
