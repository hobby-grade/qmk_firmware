# Custom Keymap for the Reviung41 built with a BIT-C and a 128x32 OLED Display.

### WARNING: This firmware uses the ATMEL bootloader configuration for compatibility with the [BIT-C MCU](https://nullbits.co/bit-c/). If your board uses a Caterina bootloader MCU, such as a standard Pro Micro, please remove the ATMEL bootloader configuration option before flashing on your device! 

### Purpose:
This keymap is designed with efficiency in mind. 

### OLED Support:
In order to enable OLED support, you will need to have the options:
```
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
```
contained in your ```rules.mk```.

### Resources (images should be 128x32 pixels):
* To make your own pixel art: https://www.pixilart.com/draw
* QMK Logo Editor: https://joric.github.io/qle/
* Another way to create a byte array from your image: https://javl.github.io/image2cpp/
* Good guide to creating images for OLED: https://docs.splitkb.com/hc/en-us/articles/360013811280-How-do-I-convert-an-image-for-use-on-an-OLED-display-

