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

/*  K00, K01, K10, K11, K02, K03, K12, K13, K04, K05, K14, K15, K06, K27, K07, K18, K19, K08, K09, \ 19
    K20, K21, K30, K31, K22, K23, K32, K33, K24, K25, K34, K35, K26, K47, K38, K39, K28, K29, \ 18
    K40, K41, K50, K51, K42, K43, K52, K53, K44, K45, K54, K55, K46,      K58, K59, K48,      \ 16
    K60, K61, K70, K71, K62, K63, K72, K73, K64, K65, K74, K75,      K67, K78, K79, K68, K69, \ 17
    K80, K81,                K83,                K95, K94,      K86, K87, K98, K99, K88       \ 10
    */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    KC_ESC,   KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_LNUM, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,   KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_CAPS,  KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT, KC_ENT,           KC_P4,   KC_P5,   KC_P6,  
    KC_LSFT,  KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_LSFT,          KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL,  KC_LGUI,                         KC_SPC,                          KC_RALT, KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT),

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

void led_init_ports(void) {
  DDRB |= (1<<0); // OUT
  DDRB |= (1<<1); // OUT
  DDRB |= (1<<2); // OUT
}

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    PORTB |= (1 << 0);
  } else {
    PORTB &= ~(1 << 0);
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    PORTB |= (1 << 1);
  } else {
    PORTB &= ~(1 << 1);
  }

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    PORTB |= (1 << 2);
  } else {
    PORTB &= ~(1 << 2);
  }

}
