#include QMK_KEYBOARD_H


#define QWERTY   DF(_QWERTY)

// Key aliases
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_QUOT MT(MOD_RSFT, KC_QUOTE)
#define CTL_PIPE MT(MOD_RCTL, KC_PIPE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define CTRL_F9  MT(MOD_LCTL, KC_F9)
#define CTRL_F10 MT(MOD_LCTL, KC_F10)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY LAYER used for normal typing
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
            KC_HYPR, KC_LGUI, KC_LALT, LT(2, KC_SPC), LT(1, KC_ENT),   LT(2, KC_ENT), LT(1, KC_SPC), KC_BSPC,  KC_DEL, KC_HYPR
                                      //`--------------------------'  `--------------------------'
  ),
  // LOWER LAYER used for numbers and shortcuts on the left and for navigation on right hand side
  	[1] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,   KC_1,  KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    CTRL_F10, KC_F5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    CTRL_F9, CTRL_F10, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______, _______, KC_HOME, KC_END, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                            _______, _______, KC_LGUI, _______, KC_SPC,  KC_ENT, MO(3), KC_RALT, _______, _______
                                      //`--------------------------'  `--------------------------'
    ),

  // SYMBOLS LAYER used for symbols on left and right hand side
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
                    _______, _______, KC_TILD, KC_LGUI, MO(3),             KC_ENT, _______, KC_RALT, _______, _______
                                      //`--------------------------'  `--------------------------'
    ),

  // MISC layer for rgb controls
	[3] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,_______, _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, KC_LGUI, _______, KC_SPC,       KC_ENT, _______, KC_RALT, _______, _______
    ),
    // GAMING LAYER for vidja gams currently WIP #TODO
    [4] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0, KC_MINS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SFT_T(KC_TAB), KC_A, KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_APP,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, CTL_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_HYPR, KC_LGUI, KC_LALT, LT(2, KC_SPC), LT(1, KC_ENT),   LT(2, KC_ENT), LT(1, KC_SPC), KC_BSPC,  KC_DEL, KC_HYPR
                                      //`--------------------------'  `--------------------------'
  )

};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

