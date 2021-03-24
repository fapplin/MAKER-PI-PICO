This is taken from the Raspberry Pi "Getting Started with Raspberry Pi Pico - C/C++ Development with Raspberry Pi Pico and other RP2040-based microcontroller boards."

```
https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf
```

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
