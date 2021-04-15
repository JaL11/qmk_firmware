
#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

// Encoder settings to unflip the direction of the ecoders and get the resolution right
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 2

#define UNICODE_SELECTED_MODES UC_LNX

// Retro Tapping:
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY


//  #define PERMISSIVE_HOLD
#define TAPPING_TERM 200

//Combos:
#define COMBO_COUNT 1
#define COMBO_TERM 200

// Leader key:
//#define LEADER_KEY_STRICT_KEY_PROCESSING
#define LEADER_TIMEOUT 300