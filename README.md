ECG1 uses ESP-IDF with possible FreeRTOS usage

Install Esp-idf and configure, use this link for instructions steps 1-4
	https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#step-7-configure

add tft submodule
```
git submodule add https://github.com/jeremyjh/ESP32_TFT_library.git externals/ESP32_TFT_library
```
run in terminal to configure
```
idf.py set-target esp32
```
configure menu
```
idf.py menuconfig
```
Navigate to **Component config -> TFT Display** and set **display and pin** options or select a pre-defined display configuration for a kit.  Use TTGO T-DISPLAY for example

Build project
```
idf.py build
```	

flash project using your PORT name
```
idf.py -p PORT flash
```
monitor device
```
idf.py -p PORT monitor
```

