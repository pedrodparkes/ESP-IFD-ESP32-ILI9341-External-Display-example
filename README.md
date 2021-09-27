This example demonstrates how to connect ILI9341-based display to modern ESP32 fork - TTGO-tDisplay in ESP-IDF.
I use [ESP32_TFT_library](https://github.com/jeremyjh/ESP32_TFT_library.git). 

Alternatively you can use [LVGL ported to ESP32 including various display and touchpad drivers](https://github.com/lvgl/lv_port_esp32) 


***1. Run in terminal to configure***
```
idf.py set-target esp32
```
***2. configure menu***
```
idf.py menuconfig
```
*Navigate to **Component config -> TFT Display** and set **display and pin** options or select a pre-defined display configuration for a kit.  
Use TTGO T-DISPLAY for example

****My example utilizes external 320x240 ili9341 display and needs next changes in menuconfig and tfspi.h:**
	
    1. // ** Set the correct configuration for ESP-WROVER-KIT v4.1 
	2. Changes in tftspi.h file done to use ready config, eg. ESP-WROVER-KIT v4.1
	3. Connect according to next scheme:
	#define PIN_NUM_MISO 27     // SPI MISO
	#define PIN_NUM_MOSI 21     // SPI MOSI
	#define PIN_NUM_CLK  22     // SPI CLOCK pin
	#define PIN_NUM_CS   15     // Display CS pin
	#define PIN_NUM_DC   32     // Display command/data pin
	#define PIN_NUM_RST  26     // GPIO used for RESET control
	#define PIN_NUM_BCKL  13     // GPIO used for backlight control
	#define PIN_BCKL_ON   1     // GPIO value for backlight ON
	#define PIN_BCKL_OFF  0     // GPIO value for backlight OFF

***3. Build project***

```idf.py -p /dev/tty.SLAB_USBtoUART clean build flash monitor```	

***4. Have fun!***

![TTGO-tDisplay PinOut](ttgo_t_display.jpeg?raw=true "TTGO-tDisplay PinOut")
![ili9341 Display PinOut](ili9341.png?raw=true "ili9341 Display PinOut")