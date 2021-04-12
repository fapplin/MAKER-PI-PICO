export PICO_SDK_PATH=/home/pi/pico/pico-sdk
mkdir pioasm_build
cd pioasm_build
make
cd ..
cmake ..
make
