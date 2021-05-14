/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Spotify Vol Dn/Up  |      		 | Knob 2: Vol Dn/Up  |
        | Press: N/A                 | Hold: Layer 2 | Press: N/A         |
        | OBS mute                   | Mute   		 | Play/Pause         |
        | OBS unmute                 | Media Previous| Media Next         |
     */
    [0] = LAYOUT(
        KC_NO, MO(1), KC_NO,
        KC_F15, KC_MUTE, KC_MPLY,
        KC_F16, KC_MPRV, KC_MNXT
    ),
    /*
        | RESET          | Held: Layer 2    | Media Stop |
        | Held: Layer 2  | Backlight step   | RGB Mode   |
        | Media Previous | Backlight on/off | RGB on/off |
     */
    [1] = LAYOUT(
        RESET  , _______, KC_STOP,
        KC_PSCREEN, BL_STEP, RGB_MOD,
        KC_MPRV, BL_TOGG , RGB_TOG
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _RIGHT) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    else if (index == _MIDDLE) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
			tap_code(KC_F13);
        } else {
            tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
			tap_code(KC_F14);
        }
    }
}
