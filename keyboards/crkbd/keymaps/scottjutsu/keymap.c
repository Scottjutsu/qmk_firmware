#include "scottjutsu.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _SCOTTY 0
#define _NUMBERS 1
#define _SYMBOLS 2
#define _MACR0S 3
#define _KEEB 4

// MACROS appears to be a QMK keyword so we're hax0rs now
enum custom_keycodes {
  SCOTTY = SAFE_RANGE,
  NUMBERS,
  SYMBOLS,
  MACR0S,
  KEEB,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_SCOTTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    MO(_KEEB), XXXXXXX,    KC_K,    KC_P,    KC_M,    KC_W,                         KC_G,    KC_U,    KC_F,    KC_V, KC_LBRC, KC_RBRC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_R,    KC_N,    KC_H,    KC_T,    KC_B,                         KC_O,    KC_E,    KC_A,    KC_I,    KC_S, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_J,    KC_C,    KC_L, G(KC_SPC),                      KC_BSPC,    KC_Y,    KC_D,    KC_X,    KC_Q, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LSFT, MO(_SYMBOLS), KC_SPC,   KC_ENT, MO(_MACR0S), MO(_NUMBERS) \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBERS] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_5,    KC_6,    KC_7,    KC_8,    KC_9, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_AMPR,   KC_LT, KC_LCBR, KC_LBRC,                      KC_RBRC, KC_RCBR,   KC_GT, KC_ASTR, A(KC_MINS), A(S(KC_MINS)),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_SCLN, KC_UNDS, KC_EXLM, KC_QUES, KC_LPRN,                      KC_RPRN,  KC_DOT, KC_COMM, KC_MINS, KC_COLN, KC_PERC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CIRC,  KC_EQL,  KC_DLR, KC_HASH,   KC_AT, KC_BSLS,                      KC_SLSH, KC_QUOT,  KC_DQT,  KC_GRV, KC_PLUS, KC_PIPE,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MACR0S] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------------------------------------------.                    ,-----------------------------------------------------------------------------------------.
            XXXXXXX,    C(A(KC_D)), C(A(KC_LEFT)),  C(A(KC_ENT)), C(A(KC_RGHT)),    C(A(KC_G)),                            G(KC_O),       G(KC_W),       G(KC_Q),       G(KC_N),       G(KC_T),       XXXXXXX,\
  //,--------------+--------------+--------------+--------------+--------------+--------------|                    |--------------+--------------+--------------+--------------+--------------+--------------|
            XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,    S(G(KC_V)),     KC__VOLUP,                            G(KC_R),       G(KC_C),       G(KC_V),       G(KC_H),       G(KC_S),       XXXXXXX,\
  //,--------------+--------------+--------------+--------------+--------------+--------------|                    |--------------+--------------+--------------+--------------+--------------+--------------|
            XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,      KC__MUTE,   KC__VOLDOWN,                            G(KC_Z),    S(G(KC_Z)),       G(KC_A),       G(KC_D),       G(KC_F),       G(KC_P),\
  //,--------------+--------------+--------------+--------------+--------------+--------------|---------|  |-------+--------------+--------------+--------------+--------------+--------------+--------------|
                                                                               XXXXXXX, XXXXXXX, XXXXXXX,   C(KC_C), XXXXXXX, XXXXXXX \
                                                                           //`--------------------------'  `--------------------------'
  ),

  [_KEEB] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  KC_SPC,     KC_ENT,   XXXXXXX, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting KEEB layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

// void matrix_init_user(void) {
//     #ifdef RGBLIGHT_ENABLE
//       RGB_current_mode = rgblight_config.mode;
//     #endif
//     //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//     #ifdef SSD1306OLED
//         iota_gfx_init(!has_usb());   // turns on the display
//     #endif
// }

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// void matrix_scan_user(void) {
//    iota_gfx_task();
// }

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case SCOTTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_SCOTTY);
      }
      return false;
    case NUMBERS:
      if (record->event.pressed) {
        layer_on(_NUMBERS);
      } else {
        layer_off(_NUMBERS);
      }
      return false;
    case SYMBOLS:
      if (record->event.pressed) {
        layer_on(_SYMBOLS);
      } else {
        layer_off(_SYMBOLS);
      }
      return false;
    case MACR0S:
        if (record->event.pressed) {
          layer_on(_MACR0S);
        } else {
          layer_off(_MACR0S);
        }
        return false;
    case KEEB:
        if (record->event.pressed) {
          layer_on(_KEEB);
        } else {
          layer_off(_KEEB);
        }
        return false;
  }
  return true;
}

#ifdef OLED_DRIVER_ENABLE
void render_rgb_status(void) {
    static char temp[23] = {0};
    snprintf(temp, sizeof(temp) + 1, "H:%3d S:%3d V:%3d", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v);
    oled_write_ln("", false);
    oled_write(temp, false);
}
void oled_task_user(void) {
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case _SCOTTY:
            oled_write_P(PSTR("Scotty\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _MACR0S:
            oled_write_P(PSTR("Macros\n"), false);
            break;
        case _KEEB:
            oled_write_P(PSTR("KEEB\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

  // 
  #ifdef RGB_MATRIX_ENABLE
    render_rgb_status();
  #endif
}
#endif
