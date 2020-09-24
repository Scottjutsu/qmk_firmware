
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
CONSOLE_ENABLE             = no  # Console for debug(+400)
COMMAND_ENABLE             = no  # Commands for debug and configuration
NKRO_ENABLE                = yes # Nkey Rollover https://tinyurl.com/yd69lrdz - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
MIDI_ENABLE                = no  # MIDI controls
AUDIO_ENABLE               = no  # Audio output on port C6
UNICODE_ENABLE             = no  # Unicode
BLUETOOTH_ENABLE           = no  # Enable Bluetooth with the Adafruit EZ-Key HID
BACKLIGHT_ENABLE           = no  # Disabled because we're enabling WS2812 RGB underlight (see below).
RGBLIGHT_ENABLE            = no  # Disabled because we're enabling WS2812 RGB underlight (see below).
SWAP_HANDS_ENABLE          = no  # Enable one-hand typing
RGB_MATRIX_ENABLE          = WS2812 # Enable WS2812 RGB underlight

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

OLED_DRIVER_ENABLE = yes
