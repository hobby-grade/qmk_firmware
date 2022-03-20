/* Copyright (C) 2019, 2020  Keyboard.io, Inc; 2022 hobby-grade
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

enum atreus_layers {
  _COLEMAK,
  _ZEUS,
  _HERA,
  _ADJUST
};

enum atreus_keycodes {
  COLEMAK = SAFE_RANGE,
  ZEUS,
  HERA
};

#define ZEUS MO(_ZEUS)
#define HERA MO(_HERA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
	,----------------------------------.                ,----------------------------------.
	|   Q  |   W  |   F  |   P  |   G  |                |   J  |   L  |   U  |   Y  |   '  |
	|------+------+------+------+------|                |------+------+------+------+------|
	|   A  |   R  |   S  |   T  |   D  |                |   H  |   N  |   E  |   I  |   O  |
	|------+------+------+------+------+------.  ,------+------+------+------+------+------|
	|   Z  |   X  |   C  |   V  |   B  |  DEL |  | BKSP |   K  |   M  |   ,  |   .  |   /  |
	|------+------+------+------+------+------|  |------+------+------+------+------+------|
	| SHFT |  TAB |  ESC | ZEUS |  ALT | CTRL |  | SPCE | SUPR | HERA |   [  |   ]  | ENTR |
	`-----------------------------------------'  `-----------------------------------------'
*/

[_COLEMAK] = LAYOUT(
   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_BSPC, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,
   KC_RSFT, KC_TAB,  KC_ESC,  ZEUS,    KC_RALT, KC_RCTRL,KC_SPC,  KC_RGUI, HERA,    KC_LBRC, KC_RBRC, KC_ENTER
),

/* Zeus
	,----------------------------------.                ,----------------------------------.
	|   !  |   @  |   #  |   $  |   %  |                |   ^  |   &  |   *  |   (  |   )  |
	|------+------+------+------+------|                |------+------+------+------+------|
	|      |      |  UP  |      |      |                |      |   _  |   +  |      |      |
	|------+------+------+------+------+------.  ,------+------+------+------+------+------|
	|      | LEFT | DOWN | RGHT |      |      |  |      |      |      |      |      |      |
	|------+------+------+------+------+------|  |------+------+------+------+------+------|
	|      |   `  |   ~  |      |      |      |  |      |      |      |      |      |   |  |
	`-----------------------------------------'  `-----------------------------------------'
*/

[_ZEUS] = LAYOUT(
   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Hera
	,----------------------------------.                ,----------------------------------.
	|   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |
	|------+------+------+------+------|                |------+------+------+------+------|
	|      |      |  UP  |      |      |                |      |   -  |   =  |      |      |
	|------+------+------+------+------+------.  ,------+------+------+------+------+------|
	|      | LEFT | DOWN | RGHT |      |      |  |      |      |      |      |      |      |
	|------+------+------+------+------+------|  |------+------+------+------+------+------|
	|      |      |      |      |      |      |  |      |      |      |      |      |   \  |
	`-----------------------------------------'  `-----------------------------------------'
*/


[_HERA] = LAYOUT(
   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};
