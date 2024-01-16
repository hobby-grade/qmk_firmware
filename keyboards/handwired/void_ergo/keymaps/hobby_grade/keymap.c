/* Copyright 2021 Stefan Hancock
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version; despite the fact that you should not.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _COLEMAKWIN,
  _COLEMAKLIN,
  _MOUSE,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum layer_keycodes {
    COLEMAKWIN = SAFE_RANGE, // Colemak layout with Super key on the top right thumb for Windows
    COLEMAKLIN,              // Colemak layout with Super key on the bottom left for macOS and Linux
    MACSHT,
    WINSHT
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define MOUSE  MO(_MOUSE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BLANK TEMPLATE
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |        |        |        |        |        |  |        |        |        |        |        |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */


/* COLEMAKWIN
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |  TAB   |    Q   |    W   |    F   |    P   |    G   |                    |    J   |    L   |    U   |    Y   |    ;   |  BSPC  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |  ESC   |    A   |    R   |    S   |    T   |    D   |                    |    H   |    N   |    E   |    I   |    O   |  ENTR  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |  SHFT  |    Z   |    X   |    C   |    V   |    B   |                    |    K   |    M   |    ,   |    .   |    /   |    '   |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |  LALT  |  CTRL  |  LWER  |   DEL  |  MOUS  |  |  RGUI  |  SPCE  |  RASE  | WINSHT | MACSHT |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */
[_COLEMAKWIN] = LAYOUT_void_ergo(
    KC_TAB,     KC_Q,     KC_W,     KC_F,       KC_P,     KC_G,                     KC_J,       KC_L,     KC_U,       KC_Y,     KC_QUOT,  KC_BSPC,
    KC_ESC,     KC_A,     KC_R,     KC_S,       KC_T,     KC_D,                     KC_H,       KC_N,     KC_E,       KC_I,     KC_O,     KC_ENT,
    KC_LSFT,    KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,                     KC_K,       KC_M,     KC_COMM,    KC_DOT,   KC_SLSH,  KC_SCLN,
                KC_LALT,  KC_LCTL,  LOWER,      KC_DEL,   MOUSE,                    KC_RGUI,    KC_SPC,   RAISE,      WINSHT,   MACSHT
),


/* COLEMAKLIN
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |  TAB   |    Q   |    W   |    F   |    P   |    G   |                    |    J   |    L   |    U   |    Y   |    ;   |  BSPC  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |  ESC   |    A   |    R   |    S   |    T   |    D   |                    |    H   |    N   |    E   |    I   |    O   |  ENTR  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |  SHFT  |    Z   |    X   |    C   |    V   |    B   |                    |    K   |    M   |    ,   |    .   |    /   |    '   |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |  LALT  |  RGUI  |  LWER  |   DEL  |  MOUS  |  |  CTRL  |  SPCE  |  RASE  | WINSHT | MACSHT |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */
[_COLEMAKLIN] = LAYOUT_void_ergo(
    KC_TAB,     KC_Q,     KC_W,     KC_F,       KC_P,     KC_G,                     KC_J,       KC_L,     KC_U,       KC_Y,     KC_QUOT,  KC_BSPC,
    KC_ESC,     KC_A,     KC_R,     KC_S,       KC_T,     KC_D,                     KC_H,       KC_N,     KC_E,       KC_I,     KC_O,     KC_ENT,
    KC_LSFT,    KC_Z,     KC_X,     KC_C,       KC_V,     KC_B,                     KC_K,       KC_M,     KC_COMM,    KC_DOT,   KC_SLSH,  KC_SCLN,
                KC_LALT,  KC_RGUI,  LOWER,      KC_DEL,   MOUSE,                    KC_LCTL,    KC_SPC,   RAISE,      WINSHT,   MACSHT
),

/* MOUSE KEYS
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |        |        |        |        |        |  |        |        |        |        |        |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */
[_MOUSE] = LAYOUT_void_ergo(
    _______,    _______,  _______,  _______,    _______,  _______,                  _______,    KC_WH_U,  KC_MS_U,    _______,  _______,  _______,
    _______,    _______,  _______,  _______,    _______,  _______,                  _______,    KC_MS_L,  KC_MS_D,    KC_MS_R,  _______,  _______,
    _______,    _______,  _______,  _______,    _______,  _______,                  _______,    KC_WH_D,  _______,    _______,  _______,  _______,
                _______,  _______,  _______,    _______,  _______,                  _______,    KC_BTN1,  KC_BTN2,    _______,  _______
),

/* LOWER
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |   `    |    !   |    @   |    #   |    $   |    %   |                    |    ^   |    &   |    *   |    (   |    )   |   DEL  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |   ~    |        |        |   UP   |        |        |                    |        |    _   |    +   |    {   |    }   |    |   |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |  LEFT  |  DOWN  |  RGHT  |        |                    |        |        |        |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |        |        |  LWER  |        |        |  |        |        |  RASE  |        |        |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */
[_LOWER] = LAYOUT_void_ergo(
    KC_GRV,     KC_EXLM,  KC_AT,    KC_HASH,    KC_DLR,   KC_PERC,                  KC_CIRC,    KC_AMPR,  KC_ASTR,    KC_LPRN,  KC_RPRN,  KC_DEL,
    KC_TILD,    _______,  _______,  KC_UP,      _______,  _______,                  _______,    KC_UNDS,  KC_PLUS,    KC_LCBR,  KC_RCBR,  KC_PIPE,
    _______,    _______,  KC_LEFT,  KC_DOWN,    KC_RIGHT, _______,                  _______,    _______,  _______,    _______,  _______,  _______,
                _______,  _______,  LOWER,      _______,  _______,                  _______,    _______,   RAISE,     _______,  _______
),

/* RAISE
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |   `    |    1   |    2   |    3   |    4   |    5   |                    |    6   |    7   |    8   |    9   |    0   |   DEL  |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |   ~    |        |        |   UP   |        |        |                    |        |    -   |    =   |    [   |    ]   |    \   |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |  LEFT  |  DOWN  |  RGHT  |        |                    |        |        |        |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |        |        |  LWER  |        |        |  |        |        |  RASE  |        |        |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */
[_RAISE] = LAYOUT_void_ergo(
    KC_GRV,     KC_1,     KC_2,     KC_3,       KC_4,     KC_5,                     KC_6,       KC_7,     KC_8,       KC_9,     KC_0,     KC_DEL,
    KC_TILD,    _______,  _______,  KC_UP,      _______,  _______,                  _______,    KC_MINS,  KC_EQL,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    KC_TRNS,    _______,  KC_LEFT,  KC_DOWN,    KC_RIGHT, _______,                  _______,    _______,  _______,    _______,  _______,  _______,
                _______,  _______,  LOWER,      _______,  _______,                  KC_RGUI,    KC_SPC,   RAISE,      WINSHT,   MACSHT
),


/* ADJUST
 * .-----------------------------------------------------.                    .-----------------------------------------------------.
 * |        |  RESET |        |        |        |        |                    |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                    |COLEMKWI|COLEMAKL|        |        |        |        |
 * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |                    |        |        |        |        |        |        |
 * `--------+--------+--------+--------+--------+--------+--------.  .--------+--------+--------+--------+--------+--------+--------'
 *                   |        |        |        |        |        |  |        |        |        |        |        |
 *                   `--------------------------------------------'  `--------------------------------------------'
 */
[_ADJUST] = LAYOUT_void_ergo(
    _______,    RESET,    _______,  _______,    _______,  _______,                  _______,    _______,  _______,    _______,  _______,  _______,
    _______,    _______,  _______,  _______,    _______,  _______,                  COLEMAKWIN,COLEMAKLIN,_______,    _______,  _______,  _______,
    _______,    _______,  _______,  _______,    _______,  _______,                  _______,    _______,  _______,    _______,  _______,  _______,
                _______,  _______,  _______,    _______,  _______,                  _______,    _______,  _______,    _______,  _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAKWIN:
     if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAKWIN);
    }
      return false;
      break;
    case COLEMAKLIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAKLIN);
      }
      return false;
      break;
    case MACSHT:
     if (record->event.pressed) {
         SEND_STRING(SS_LCMD(SS_LSFT("4")));
    }
     break;
    case WINSHT:
     if (record->event.pressed) {
         SEND_STRING(SS_LGUI(SS_LSFT("S")));
    }
     break;
  }
  return true;
}

void matrix_init_user(void) {

}
