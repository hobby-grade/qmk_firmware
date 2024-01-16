/*
Copyright 2024 Stefan Hancock

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    _______, KC_MPLY, KC_MNXT,
    _______, KC_MSTP, KC_MPRV
)

};

#ifdef OLED_ENABLE


bool oled_task_user(void) {
    oled_write_P(PSTR("nullbitsco/scramble\n"), false);
    oled_write_P(PSTR("stop        play\n"), false);
    oled_write_P(PSTR("back        forward\n"), false);
    return false;
}
#endif

void matrix_init_user(void) {
  set_scramble_LED(LED_OFF);
}
