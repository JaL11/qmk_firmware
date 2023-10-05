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
#define CTL_F9  MT(MOD_LCTL, KC_F9)
#define CTL_F10  MT(MOD_LCTL, KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_GESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SFT_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, CTL_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_LGUI, KC_LALT, LT(2, KC_ENT),    LT(1, KC_SPC), KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
  	[1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,                                   KC_6,   KC_7,   KC_8,   KC_9,     KC_0,    _______,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CTL_F10, KC_F5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        CTL_F9, CTL_F10, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                   KC_HOME, KC_END, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                            KC_LGUI, _______, KC_SPC,   KC_ENT, MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

	[2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_CAPS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                     _______, _______, _______, _______, _______, KC_EQL,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                         KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                      KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
                                    KC_TILD, KC_LGUI, MO(3),             KC_ENT, _______, KC_RALT

                                      //`--------------------------'  `--------------------------'
  ),

	[3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_LGUI, _______, KC_SPC,       KC_ENT, _______, KC_RALT
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
