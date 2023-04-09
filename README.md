# AGL-QUIZ

## Make QT Application
![image](https://user-images.githubusercontent.com/54492585/230721204-a663c9b5-f9cd-4273-8c96-29a473a377cb.png)


![image](https://user-images.githubusercontent.com/54492585/230721225-eb76a3e2-5913-46b7-8af6-22736d2e74aa.png)

## Image

Step 1: Install the necessary tools and set up the build environment

Install the build dependencies:

`sudo apt-get update
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm
`

**Install the build system:**

`
wget http://downloads.yoctoproject.org/releases/yocto/yocto-2.5/poky-sumo-19.0.0.tar.bz2
tar xvf poky-sumo-19.0.0.tar.bz2
cd poky-sumo-19.0.0
`

**Install AGL-specific tools:**

`
git clone -b zeus https://gerrit.automotivelinux.org/gerrit/AGL/agl-dev-tools
cd agl-dev-tools
sudo ./install-agl.sh

`
