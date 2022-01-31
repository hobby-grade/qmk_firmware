/*
Copyright 2021 Stefan Hancock

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

enum custom_keycodes {
 JOY = SAFE_RANGE,
};

#define _BASE 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    _______,KC_VOLU, KC_HOME,
    _______,KC_VOLD, KC_END
)

};
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case JOY:
            if (record->event.pressed) {
                SEND_STRING(":joy:");
                oled_write_P(PSTR("JOY"), false);
                break;
            }
        break;
    }
    return true;
}
*/

#ifdef OLED_ENABLE

// Rotate the OLED 270 degrees
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_0;
}

static void costanza(void) {
    static const char PROGMEM shiggy[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,190,224,  0,144,136,138,138,146,146,146,131,193, 97, 33,  1,  1,  1,  1,  0, 16, 16, 16, 32, 32,160,160,160,160,160,160,160,160,160, 32,128,192, 96, 32, 48, 16,  8, 12,  6,  2,  3,  1,  0,  0,158,243,  0,  0,  0,  0,248, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60, 39,255,126,130, 15,  9,  9, 13,  5,  7,  6,  2,  6, 28,252,  4,  4,  4, 12,124,198,  3,  1,  1,  3,  2,  2,  2,  2,  2,  3,  1,129,207,121,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  8,  8, 12,230, 31,  7, 12, 24,112,224, 32,160, 96,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  2,  7, 60,248,144, 16, 16, 24,  8, 12,  6,  3,121,192,128,  0,  0,128, 33, 33, 35, 98, 66,  2,  2,  2,  2,  2, 50,227,193,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224, 60,  7,  1,  0,  0,128,192, 96, 25, 15,  3,  0,  0,  1,  7, 13,  9,  1,  1,  3,  2,  2,  6,  4,  4,  4,  8,  8, 16, 16,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7, 28, 48,192,128,128, 12,  8,  8, 25, 17, 17, 17, 24,  8,  8,  8,  4,  4,  4,  6,  2,  3,  1,  1,  3, 14,  0,  0,  0,  0,  0,  0,  0,  0,128,192, 96, 48, 28,  6,  3,  1,  0,  0,224, 48, 30,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(shiggy, sizeof(shiggy));
}

void oled_task_user(void) {
    costanza();
}
#endif

void matrix_init_user(void) {
  set_scramble_LED(LED_DIM);
}


/*
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
*/
