#include QMK_KEYBOARD_H
#include "sendstring_colemak.h"

enum macro_keycodes {
    cowsay,
    neofetch,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
          cowsay,
          neofetch
          )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case cowsay:
        if (record->event.pressed) {
            // when keycode cowsay is pressed
            SEND_STRING("cowsay you have a small penis"SS_TAP(X_ENT));
        } else {
            // when keycode cowsay is released
        }
        break;
    case neofetch:
        if (record->event.pressed) {
            SEND_STRING("neofetch"SS_TAP(X_ENT));
        } else {

        }
        break;
    }
    return true;
};
