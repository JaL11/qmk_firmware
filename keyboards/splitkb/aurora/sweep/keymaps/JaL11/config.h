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

#pragma once

#include "layouts.h"

// Not yet available in `keymap.json` format
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#endif


// Not yet available in `keymap.json` format
#ifdef MOUSEKEY_ENABLE
     // The default is 100
#   define MOUSEKEY_WHEEL_INTERVAL 50
     // The default is 40
#   define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

// /* Flash */
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET              // Activates the double-tap behavior
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 400U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

// COMBOS
#ifdef COMBO_ENABLE
#   define COMBO_VARIABLE_LEN
#   define COMBO_TERM 50
#endif

#ifdef TAP_DANCE_ENABLE
#   define TAPPING_TERM 175
#   define TAPPING_TERM_PER_KEY
#endif
// controlling rbg (currently not working maybe check discord)
//https://docs.splitkb.com/hc/en-us/articles/5799904122012-Onboard-RGB

// #undef RGB_DI_PIN
// #define RGB_DI_PIN 25
// #undef RGBLED_NUM
// #define RGBLED_NUM 2
// #undef RGBLED_SPLIT
// #define RGBLED_SPLIT {1, 1}
