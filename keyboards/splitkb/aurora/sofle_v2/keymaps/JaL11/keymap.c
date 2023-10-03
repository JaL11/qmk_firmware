#include QMK_KEYBOARD_H


#define QWERTY   DF(_QWERTY)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_QUOT MT(MOD_RSFT, KC_QUOTE)
#define CTL_PIPE MT(MOD_RCTL, KC_PIPE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define CTRL_F9  MT(MOD_LCTL, KC_F9)
#define CTRL_F10  MT(MOD_LCTL, KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_MINS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SFT_T(KC_TAB), KC_A, KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_APP,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, CTL_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_HYPR, KC_LGUI, KC_LALT, LT(2, KC_SPC), LT(1, KC_ENT),   LT(2, KC_ENT), LT(1, KC_SPC), KC_BSPC,  KC_DEL, //KC_HYPR
                                      //`--------------------------'  `--------------------------'
  ),
  	[1] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,   KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CTRL_F10, KC_F5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CTRL_F9, CTRL_F10, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_HOME, KC_END, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                            _______, _______, KC_LGUI, _______, KC_SPC,  KC_ENT, MO(3), KC_RALT, _______, //_______,
                                      //`--------------------------'  `--------------------------'
    ),

	[2] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_CAPS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                       _______, _______, _______, _______, _______, KC_EQL,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                         KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______,   KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                    _______, _______, KC_TILD, KC_LGUI, MO(3),             KC_ENT, _______, KC_RALT, _______, //_______,
                                      //`--------------------------'  `--------------------------'
    ),

	[3] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,_______, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, KC_LGUI, _______, KC_SPC,       KC_ENT, _______, KC_RALT, _______, //_______,
    ),

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



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

// #include QMK_KEYBOARD_H
// // better combo support
// #include "g/keymap_combo.h"
// // #include "layouts.h"

// enum layers {
//     _QWERTY = 0,
//     _SYMBOLS,
//     _NUMBERS,
//     _ADJUST,
//     _MISC
// };
// //must come after layer def!!!

// // Tap Dance declarations
// enum {
//     TD_Q_ESC,
// };

// bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
// uint16_t alt_tab_timer = 0;     // we will be using them soon.

// enum custom_keycodes {          // Make sure have the awesome keycode ready
//   ALT_TAB = SAFE_RANGE,
// };

// // Tap Dance definitions
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Q, twice for ESC
//     [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
// };

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//     [_QWERTY] = LAYOUT(
//     //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
//         TD(TD_Q_ESC)  ,     KC_W      ,     KC_E      ,     KC_R      ,    KC_T       ,             KC_Y      ,      KC_U     ,      KC_I     ,      KC_O     ,      KC_P     ,
//     //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
//             HM_A      ,     HM_S      ,     HM_D      ,     HM_F      ,    KC_G       ,             KC_H      ,      HM_J     ,      HM_K     ,      HM_L     ,     HM_SCLN,
//     //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
//     MT(MOD_LCTL,KC_Z) ,     KC_X      ,     KC_C      ,     KC_V      ,     KC_B      ,             KC_N      ,      KC_M     ,      KC_COMM  ,      KC_DOT   , MT(MOD_LCTL,KC_SLSH),
//     //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
//     //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
//                                         LT(_MISC, CW_TOGG),       LT(_SYMBOLS, KC_ENT),        LT(_NUMBERS, KC_SPC),  KC_BSPC
//     //                               |-------------------------+----/* Space ctl */------| |-------------------------+-------------------------|
//     ),

//     // [_QWERTY] = LAYOUT(
//     //   LT(_RAISE, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
//     //   MT(MOD_LCTL, KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     //   KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI,   KC_LSFT,                     KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
//     //           KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC),   LT(_LOWER, KC_ENT), LT(_RAISE, KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
//     // ),

//     [_SYMBOLS] = LAYOUT(
//       KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,      KC_QUOT, _______, _______, KC_BACKSLASH, KC_UNDERSCORE,
//       KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,       KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC,
//       KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,      KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH,
//                                  KC_SCLN, KC_EQL,       KC_TAB,  KC_DEL
//     ),

//     [_NUMBERS] = LAYOUT(
//       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
//       KC_TAB,  KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS,
//       KC_LCTL, _______, _______, KC_MUTE, KC_VOLD,      KC_HOME, KC_END,  _______, _______, _______,
//                                  _______, _______,      _______, _______
//     ),

//     [_ADJUST] = LAYOUT(
//       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
//       BL_TOGG, BL_BRTG, _______, _______, _______,      _______, _______, _______, KC_F11,  KC_F12,
//       BL_STEP, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
//                                  _______, _______,      _______, _______
//     ),

//     [_MISC] = LAYOUT(
//       CW_TOGG, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
//       ALT_TAB, BL_BRTG, KC_TAB,  ALT_TAB, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_F12,
//       BL_STEP, BL_TOGG, _______, _______, _______,      _______, _______, _______, _______, _______,
//                                  _______, _______,      _______, _______
//     ),


// };

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _ADJUST);
// }

// // Turn off controller LED
// void keyboard_pre_init_user(void) {
//   // Set our LED pin as output
//   setPinOutput(24);
//   // Turn the LED off
//   // (Due to technical reasons, high is off and low is on)
//   writePinHigh(24);
// }

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case TD(TD_Q_ESC):
//             return TAPPING_TERM + 75;
//         default:
//             return TAPPING_TERM;
//     }
// }


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) { // This will do most of the grunt work with the keycodes.
//     case ALT_TAB:
//       if (record->event.pressed) {
//         if (!is_alt_tab_active) {
//           is_alt_tab_active = true;
//           register_code(KC_LALT);
//         }
//         alt_tab_timer = timer_read();
//         register_code(KC_TAB);
//       } else {
//         unregister_code(KC_TAB);
//       }
//       break;
//   }
//   return true;
// }

// void matrix_scan_user(void) { // The very important timer.
//   if (is_alt_tab_active) {
//     if (timer_elapsed(alt_tab_timer) > 1000) {
//       unregister_code(KC_LALT);
//       is_alt_tab_active = false;
//     }
//   }
// }
