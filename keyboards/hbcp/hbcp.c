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
#include "hbcp.h"
#include "rgblight.h"
#include "ws2812.h"

// Default LED indicator colour values
__attribute__ ((weak))
LED_TYPE caps_led = { 255, 0, 0 };
__attribute__ ((weak))
LED_TYPE num_led = { 0, 255, 0 };
__attribute__ ((weak))
LED_TYPE scroll_led = { 0, 0, 255 };

LED_TYPE indicators[3];
bool indi_enable = true;
extern rgblight_config_t rgblight_config;

void copyrgb(LED_TYPE *src, LED_TYPE *dst);

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case INDI_MOD:
      if (record->event.pressed)
        indi_enable = !indi_enable;
        return false;
    break;
  }

  return process_record_user(keycode, record);
}

void rgblight_set(void) {
  if (rgblight_config.enable) {
    for (uint8_t i = 0; i < RGBLED_NUM; i++) {
      led[i].r = 0;
      led[i].g = 0;
      led[i].b = 0;
    }
  }

  if (indi_enable) {
    for (uint8_t i = 0; i < RGBLED_NUM; i++) {
      led[i].r = indicators[i].r;
      led[i].g = indicators[i].g;
      led[i].b = indicators[i].b;
    }
  }

  ws2812_setleds(led, RGBLED_NUM);
}

void led_set_kb(uint8_t usb_led) {
  // First, set all indicators to off
  for (int i = 0; i < 3; i++) {
    setrgb(0, 0, 0, &indicators[i]);
  }

  // Set indicators to on based on status
  if (usb_led & (1 << USB_LED_NUM_LOCK)) {
    copyrgb(&num_led, &indicators[0]); // num lock color
  }

  if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
    copyrgb(&caps_led, &indicators[1]); // caps lock color
  }

  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
    copyrgb(&scroll_led, &indicators[2]); // scroll lock color
  }

  if (indi_enable) {
    rgblight_set();
  }

  led_set_user(usb_led);
}

void copyrgb(LED_TYPE *src, LED_TYPE *dst) {
  (*dst).r = (*src).r;
  (*dst).g = (*src).g;
  (*dst).b = (*src).b;
}