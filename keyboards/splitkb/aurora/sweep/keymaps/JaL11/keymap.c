/* Copyright 2022 splitkb.com <support@splitkb.com>
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
// better combo support
#include "g/keymap_combo.h"
// #include "layouts.h"

enum layers {
    _QWERTY = 0,
    _SYMBOLS,
    _NUMBERS,
    _ADJUST,
    _MISC
};
//must come after layer def!!!

// Tap Dance declarations
enum {
    TD_Q_ESC,
};

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
        TD(TD_Q_ESC)  ,     KC_W      ,     KC_E      ,     KC_R      ,    KC_T       ,             KC_Y      ,      KC_U     ,      KC_I     ,      KC_O     ,      KC_P     ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            HM_A      ,     HM_S      ,     HM_D      ,     HM_F      ,    KC_G       ,             KC_H      ,      HM_J     ,      HM_K     ,      HM_L     ,     HM_SCLN,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    MT(MOD_LCTL,KC_Z) ,     KC_X      ,     KC_C      ,     KC_V      ,     KC_B      ,             KC_N      ,      KC_M     ,      KC_COMM  ,      KC_DOT   , MT(MOD_LCTL,KC_SLSH),
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                        LT(_MISC, CW_TOGG),       LT(_SYMBOLS, KC_ENT),        LT(_NUMBERS, KC_SPC),  KC_BSPC
    //                               |-------------------------+----/* Space ctl */------| |-------------------------+-------------------------|
    ),

    // [_QWERTY] = LAYOUT(
    //   LT(_RAISE, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
    //   MT(MOD_LCTL, KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //   KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI,   KC_LSFT,                     KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
    //           KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC),   LT(_LOWER, KC_ENT), LT(_RAISE, KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
    // ),

    [_SYMBOLS] = LAYOUT(
      KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,      KC_QUOT, _______, _______, KC_BACKSLASH, KC_UNDERSCORE,
      KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,       KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC,
      KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,      KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH,
                                 KC_SCLN, KC_EQL,       KC_TAB,  KC_DEL
    ),

    [_NUMBERS] = LAYOUT(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      KC_TAB,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
      KC_LCTL, _______, _______, KC_MUTE, KC_VOLD,      KC_HOME, KC_END,  _______, _______, _______,
                                 _______, _______,      _______, _______
    ),

    [_ADJUST] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      BL_TOGG, BL_BRTG, _______, _______, _______,      _______, _______, _______, KC_F11,  KC_F12,
      BL_STEP, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                                 _______, _______,      _______, _______
    ),

    [_MISC] = LAYOUT(
      CW_TOGG, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
      ALT_TAB, BL_BRTG, KC_TAB,  ALT_TAB, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_F12,
      BL_STEP, BL_TOGG, _______, _______, _______,      _______, _______, _______, _______, _______,
                                 _______, _______,      _______, _______
    ),


};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _ADJUST);
}

// Turn off controller LED
void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_Q_ESC):
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}




//DOESN'T WORK

// void housekeeping_task_user(void) {
//     switch (get_highest_layer(layer_state | default_layer_state)) {
//         case 0:
//             // Default layer
//             rgblight_setrgb_at(RGB_BLACK, 0);
//             break;
//         case 1:
//             rgblight_setrgb_at(RGB_RED, 0);
//             break;
//         case 2:
//             rgblight_setrgb_at(RGB_GREEN, 0);
//             break;
//         case 3:
//             rgblight_setrgb_at(RGB_BLUE, 0);
//             break;
//     }
// }

// void keyboard_post_init_user(void) {
//     // Initialize RGB to static black
//     rgblight_enable_noeeprom();
//     rgblight_sethsv_noeeprom(HSV_BLACK);
//     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
// }


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall
    // This example string should fill that neatly
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?");

    if (is_keyboard_master()) {
        oled_write_P(text, false);
    } else {
        oled_write_P(text, false);
    }
    return false;
}
#endif
