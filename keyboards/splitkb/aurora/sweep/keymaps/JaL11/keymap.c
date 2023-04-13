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
#include g/keymap_combo.h


enum layers {
    _QWERTY = 0,
    _SYMBOLS,
    _NUMBERS,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            KC_Q      ,     KC_W      ,     KC_E      ,     KC_R      ,    KC_T       ,             KC_Y      ,      KC_U     ,      KC_I     ,      KC_O     ,      KC_P     ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    MT(MOD_LSFT, KC_A),     KC_S      ,     KC_D      ,     KC_F      ,     KC_G      ,             KC_H      ,      KC_J     ,      KC_K     ,      KC_L     , MT(MOD_LSFT,KC_SCLN),
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    MT(MOD_LCTL,KC_Z) ,     KC_X      ,     KC_C      ,     KC_V      ,     KC_B      ,             KC_N      ,      KC_M     ,      KC_COMM  ,      KC_DOT   , MT(MOD_LCTL,KC_SLSH),
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                                    MOD_LSFT   ,    LT(_SYMBOLS, KC_ENT),        LT(_NUMBERS, KC_SPC),  KC_BSPC
    //                               |-------------------------+----/* Space ctl */------| |-------------------------+-------------------------|
    ),

    // [_QWERTY] = LAYOUT(
    //   LT(_RAISE, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
    //   MT(MOD_LCTL, KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //   KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI,   KC_LSFT,                     KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
    //           KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC),   LT(_LOWER, KC_ENT), LT(_RAISE, KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
    // ),

    [_SYMBOLS] = LAYOUT(
      KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, KC_BACKSLASH, KC_UNDERSCORE,
      KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC,
      KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH,
                                 KC_SCLN, KC_EQL,  KC_TAB,  KC_DEL
    ),

    [_NUMBERS] = LAYOUT(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
      KC_TAB,   KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      KC_LCTL, _______, _______, KC_MUTE, KC_VOLD,      KC_HOME, KC_END,  _______, _______, _______,
                                 _______, _______,      _______, _______
    ),

    [_ADJUST] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
      BL_TOGG, BL_BRTG, _______, _______, _______,          _______, _______, _______, KC_F11,  KC_F12,
      BL_STEP, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
                                 _______, _______,          _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _ADJUST);
}


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
