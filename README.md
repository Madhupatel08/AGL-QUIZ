# AGL-QUIZ

## Make QT Application
![image](https://user-images.githubusercontent.com/54492585/230721204-a663c9b5-f9cd-4273-8c96-29a473a377cb.png)


![image](https://user-images.githubusercontent.com/54492585/230721225-eb76a3e2-5913-46b7-8af6-22736d2e74aa.png)

## Image

Step 1: Install the necessary tools and set up the build environment

Install the build dependencies:

```
sudo apt-get update
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm
```

**Install the build system:**

```
wget http://downloads.yoctoproject.org/releases/yocto/yocto-2.5/poky-sumo-19.0.0.tar.bz2
tar xvf poky-sumo-19.0.0.tar.bz2
cd poky-sumo-19.0.0
```

**Install AGL-specific tools:**

```
git clone -b zeus https://gerrit.automotivelinux.org/gerrit/AGL/agl-dev-tools
cd agl-dev-tools
sudo ./install-agl.sh
```

**Install the necessary tools and set up the build environment:**
```
sudo apt-get update
sudo apt-get install -y gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm
wget http://downloads.yoctoproject.org/releases/yocto/yocto-3.3.3/poky-gatesgarth-23.0.3.tar.bz2
tar xvjf poky-gatesgarth-23.0.3.tar.bz2
cd poky-gatesgarth-23.0.3
source oe-init-build-env
```

**Clone the AGL repositories:**

```
git clone -b v7.1.0 https://gerrit.automotivelinux.org/gerrit/AGL/AGL-repo
cd AGL-repo
repo init -u https://gerrit.automotivelinux.org/gerrit/AGL/AGL-repo -b chinook
repo sync
```

**Initialize the AGL environment:**

```
cd meta-agl
DISTRO=agl-demo MACHINE=qemux86-64 source aglsetup.sh -m qemux86-64 agl-demo agl-devel
```

**Create a new layer for your Qt5 application:**

```
cd meta-agl-demo
mkdir -p recipes-qt/my-app
```

**Create a new recipe file for your application: **

```
nano recipes-qt/qt-app/qt-app_0.1.bb
```

**Add the following content to the recipe file to define the application:**

```
DESCRIPTION = "Qt5 Application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
SECTION = "examples"
DEPENDS = "qtbase qtdeclarative"

SRC_URI = "file://main.cpp \
           file://qtapp.qrc \
           "

S = "${WORKDIR}"

do_compile() {
    ${QTDIR}/bin/qmake -makefile -o Makefile ${S}/qtapp.pro
    make
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 qtapp ${D}${bindir}
}

FILES_${PN} += "${bindir}/qtapp"
```

**Edit the local.conf file located at the top-level directory of your build to set the target hardware platform, image type, and enable Qt5 support:**

```
MACHINE ?= "qemux86-64"
DISTRO_FEATURES_append = " systemd"
IMAGE_INSTALL_append = " agl-demo-platform agl-service-ivi agl-service-framework agl-app-framework-binding agl-demo qtbase qtdeclarative qt-app"
PACKAGECONFIG_append_pn-qtbase = " accessibility gstreamer webengine"
PACKAGECONFIG_append_pn-qtdeclarative = " qml-module-qtmultimedia qml-module-qtquick2 qml-module-qtquick-controls2 qml-module-qtquick-layouts qml-module-qtquick-controls qml-module-qt-labs-folderlistmodel qml-module-qt-labs-settings qml-module-qtgraphicaleffects"
```

**Build the AGL image**
