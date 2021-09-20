# Custom Keymap for the Reviung41 built with a BIT-C and a 128x32 OLED Display.

### WARNING: This firmware uses the ATMEL bootloader configuration for compatibility with the [BIT-C MCU](https://nullbits.co/bit-c/). If your board uses a Caterina bootloader MCU, such as a standard Pro Micro, please remove the ATMEL bootloader configuration option before flashing on your device! 

In order to enable OLED support, you will need to have the options:
```
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
```
contained in your ```rules.mk```.

To make your own pixel art:
save a png/jpeg of an 128x32 image (resource: https://www.pixilart.com/draw )
follow this guide up to and including "CONVERT YOUR IMAGE" https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display-
replace numbers in brackets with your own
if you start getting errors when compiling make sure you didn't accedentally delete a bracket
