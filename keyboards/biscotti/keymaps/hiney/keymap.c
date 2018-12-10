/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_all( 

  /*K00,  K01,  K10,  K11,  K02,  K03,  K12,  K13,  K04,  K05,  K14,  K15,  K06,  K07,  K27, \
    K20,     K21,  K30,  K31,  K22,  K23,  K32,  K33,  K24,  K25,  K34,  K35,  K26,    K47, \
    K40,       K41,  K50,  K51,  K42,  K43,  K52,  K53,  K44,  K45,  K55,  K55,      K46,  \
            K60,  K61,  K70,  K71,  K62,  K63,  K72,  K73,  K64,  K65,  K74,  K75,  K66, \
                K80,  K81,        K82,        K83,        K84,        K86,  K87        \     */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_BSLS,   KC_GRV,      
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSPC,               
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,    MO(1),                
    KC_LALT, KC_LGUI,          KC_SPC,           KC_SPC,           KC_SPC,                    KC_RGUI,  KC_RCTL
  ),
  [1] = LAYOUT_all( 

  /*K00,  K01,  K10,  K11,  K02,  K03,  K12,  K13,  K04,  K05,  K14,  K15,  K06,  K07,  K27, \
    K20,     K21,  K30,  K31,  K22,  K23,  K32,  K33,  K24,  K25,  K34,  K35,  K26,    K47, \
    K40,       K41,  K50,  K51,  K42,  K43,  K52,  K53,  K44,  K45,  K55,  K55,      K46,  \
            K60,  K61,  K70,  K71,  K62,  K63,  K72,  K73,  K64,  K65,  K74,  K75,  K66, \
                K80,  K81,        K82,        K83,        K84,        K86,  K87        \     */
    RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_INS,   KC_GRV,      
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_UP,    KC_RBRC,    KC_DEL,               
    KC_CAPS, KC_VOLD,    KC_VOLU,    KC_TRNS,    KC_TRNS,    KC_G,    KC_H,    KC_J,    KC_HOME,    KC_PGUP,    KC_LEFT,  KC_RGHT,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_END, KC_PGDN,  KC_DOWN,  KC_RSFT,    KC_TRNS,                
    KC_LALT, KC_MPRV,          KC_SPC,           KC_MPLY,           KC_MPLY,                    KC_MNXT,  KC_RCTL
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
