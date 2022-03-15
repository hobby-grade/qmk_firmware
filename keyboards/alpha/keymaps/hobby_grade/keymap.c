/* Copyright 2018-2022 PyrooL & Stefan Hancock
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version; despite the fact that you should not.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK,
    _MODS,
    _FUNCTIONS,
    _ADJUST
};

enum layer_keycodes {
    COLMK = SAFE_RANGE,
    MODS,
    FUNC,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * |   Q  │   W  │   F  │   P  │   G  │   J  │   L  │   U  │   Y  │ BKSP │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │   A  │   R  │   S  │   T  │   D  │   H  │   N  │   E  │   I  │   O  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 *    │   Z  │   X  │   C  │   V  │ MODS & SPACE │   B  │   K  │   M  │
 *    └──────┴──────┴──────┴──────┴──────────────┴──────┴──────┴──────┘
 */
[_COLEMAK] = LAYOUT(
	KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,  KC_J,  KC_L,  KC_U,  KC_Y,  KC_BSPC,
	KC_A,  KC_R,  KC_S,  KC_T,  KC_D,  KC_H,  KC_N,  KC_E,  KC_I,  KC_O,
	KC_Z,  KC_X,  KC_C,  KC_V,  LT(_MODS, KC_SPC),  KC_B,  KC_K,  KC_M
),

/* MODS
 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
 * |   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ BKSP │  ESC │  TAB │   ;  │   '  │ LEFT │ DOWN │  UP  │ RGHT │   O  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 *    │   Z  │   X  │   C  │   V  │ MODS & SPACE │   B  │   K  │   M  │
 *    └──────┴──────┴──────┴──────┴──────────────┴──────┴──────┴──────┘
 */
[_MODS] = LAYOUT(
	KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_BSPC, KC_ESC, KC_TAB, KC_SCLN, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(_FUNCTIONS),
	OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LALT), KC_ENT, MT(MOD_LSFT, KC_ENT), KC_COMM, KC_DOT, KC_SLSH
),

	[_FUNCTIONS] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_LSFT, KC_F11, KC_F12, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, TO(_ADJUST),
		RGB_VAI, RGB_VAD, RGB_HUI, TO(0), RGB_MOD, KC_MPLY, KC_VOLD, KC_VOLU
        ),

	[_ADJUST] = LAYOUT(
		RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO
        ),
};
