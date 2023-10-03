#Bootloader selection
BOOTLOADER = rp2040
# Convert from Elite-C to standard RP2040
CONVERT_TO = promicro_rp2040

ENCODER_ENABLE = yes
OLED_ENABLE = yes

# Enable RGB see https://docs.splitkb.com/hc/en-us/articles/5799904122012-Onboard-RGB
# RGBLIGHT_ENABLE = yes
# WS2812_DRIVER = vendor # Use the RP2040's PIO interfaceasdf

### NEEDED FOR COMBOS
# VPATH += keyboards/gboards
# COMBO_ENABLE = yes

### Caps word
CAPS_WORD_ENABLE = yes

### Enable tap dance see https://docs.qmk.fm/#/feature_tap_dance?id=how-to-use
# TAP_DANCE_ENABLE = yes
