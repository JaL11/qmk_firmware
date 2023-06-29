# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

#Bootloader selection
BOOTLOADER = rp2040
# Convert from Elite-C to standard RP2040
CONVERT_TO=promicro_rp2040

ENCODER_ENABLE = no
OLED_ENABLE = no

# Enable RGB see https://docs.splitkb.com/hc/en-us/articles/5799904122012-Onboard-RGB
# RGBLIGHT_ENABLE = yes
# WS2812_DRIVER = vendor # Use the RP2040's PIO interface

### NEEDED FOR COMBOS
VPATH += keyboards/gboards
COMBO_ENABLE = yes

### Caps word
CAPS_WORD_ENABLE = yes

### Enable tap dance see https://docs.qmk.fm/#/feature_tap_dance?id=how-to-use
TAP_DANCE_ENABLE = yes
