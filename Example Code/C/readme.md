Special Note:  All of the C examples were compiled on a Rasperry Pi Zero (any Raspberry Pi should work fine). Each example has a build_project.sh file in the build directory that sets the SDK directory path, does the cmake .., and make. After the initial build, the developer can just use make to rebuild.

This is taken from the Raspberry Pi "Getting Started with Raspberry Pi Pico - C/C++ Development with Raspberry Pi Pico and other RP2040-based microcontroller boards."

```
https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf
```

Quick Pico Setup

If you are developing for Raspberry Pi Pico on the Raspberry Pi 4B, or the Raspberry Pi 400, most of the installation
steps in this Getting Started guide can be skipped by running the setup script.

* NOTE
This setup script requires approximately 2.5GB of disk space on your SD card, so make sure you have enough free
space before running it. You can check how much free disk space you have with the df -h command.

You can get this script by running the following command in a terminal:

```
$ wget https://raw.githubusercontent.com/raspberrypi/pico-setup/master/pico_setup.sh ①
```

1. You should first sudo apt install wget if you don’t have wget already installed.
Then make the script executable with,

```
$ chmod +x pico_setup.sh
```

and run it with,

```
$ ./pico_setup.sh
```

The script will:

* Create a directory called pico

* Install required dependencies

* Download the pico-sdk, pico-examples, pico-extras, and pico-playground repositories

* Define PICO_SDK_PATH, PICO_EXAMPLES_PATH, PICO_EXTRAS_PATH, and PICO_PLAYGROUND_PATH in your ~/.bashrc

* Build the blink and hello_world examples in pico-examples/build/blink and pico-examples/build/hello_world

* Download and build picotool (see Appendix B), and copy it to /usr/local/bin.

* Download and build picoprobe (see Appendix A).

* Download and compile OpenOCD (for debug support)

* Download and install Visual Studio Code

* Install the required Visual Studio Code extensions (see Chapter 7 for more details)

* Configure the Raspberry Pi UART for use with Raspberry Pi Pico

Getting started with Raspberry Pi Pico

Chapter 1. Quick Pico Setup 4

* NOTE
The pico directory will be created in the folder where you run the pico_setup.sh script.

Once it has run, you will need to reboot your Raspberry Pi,

```
$ sudo reboot
```

for the UART reconfiguration to take effect. Once your Raspberry Pi has rebooted you can open Visual Studio Code in
the "Programming" menu and follow the instructions from Section 7.2.


Chapter 2. The SDK

* IMPORTANT
The following instructions assume that you are using a Raspberry Pi Pico and some details may differ if you are
using a different RP2040-based board. They also assume you are using Raspberry Pi OS running on a Raspberry Pi 4,
or an equivalent Debian-based Linux distribution running on another platform. Alternative instructions for those
using Microsoft Windows (see Section 9.2) or Apple macOS (see Section 9.1) are also provided.

The Raspberry Pi Pico is built around the RP2040 microcontroller designed by Raspberry Pi. Development on the board
is fully supported with both a C/C++ SDK, and an official MicroPython port. This book talks about how to get started
with the SDK, and walks you through how to build, install, and work with the SDK toolchain.

* TIP
For more information on the official MicroPython port see the Raspberry Pi Pico Python SDK book which documents
the port, and Get started with MicroPython on Raspberry Pi Pico by Gareth Halfacree and Ben Everard, published by
Raspberry Pi Press.

* TIP
For more information on the C/C++ SDK, along with API-level documentation, see the Raspberry Pi Pico C/C++ SDK
book.


2.1 Get the SDK and examples

The pico-examples repository (https://github.com/raspberrypi/pico-examples) provides a set of example applications
that are written using the pico-sdk (https://github.com/raspberrypi/pico-sdk). To clone these repositories start by
creating a pico directory to keep all pico related checkouts in. These instructions create a pico directory at /home/pi/pico.

```
$ cd ~/
$ mkdir pico
$ cd pico
```

Then clone the pico-sdk and pico-examples git repositories.

```
$ git clone -b master https://github.com/raspberrypi/pico-sdk.git
$ cd pico-sdk
$ git submodule update --init
$ cd ..
$ git clone -b master https://github.com/raspberrypi/pico-examples.git
```

* WARNING
If you have not initialised the tinyusb submodule in your pico-sdk checkout then USB CDC serial, and other USB
functions and example code, will not work as the SDK will contain no USB functionality.

* NOTE
There are additional repositories: pico-extras, and pico-playground that you may also be interested in.


2.2. Install the Toolchain

To build the applications in pico-examples, you’ll need to install some extra tools. To build projects you’ll need CMake, a
cross-platform tool used to build the software, and the GNU Embedded Toolchain for Arm. You can install both these via
apt from the command line. Anything you already have installed will be ignored by apt.

```
$ sudo apt update
$ sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential ①
```

1. Native gcc and g++ are needed to compile pioasm and elf2uf2.


* NOTE
Ubuntu and Debian users might additionally need to also install libstdc++-arm-none-eabi-newlib.
