#include QMK_KEYBOARD_H
#include "keymap_german.h"



void keyboard_post_init_user(void) {
    //rgblight_enable_noeeprom();
    //rgblight_sethsv_noeeprom(0,255,0);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
    /*
    rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
    rgb_matrix_mode_noeeprom(default_animation);
    rgb_matrix_set_speed_noeeprom(default_speed);
    */
    //rgb_matrix_set_color_all(0, 255, 0);
    rgb_matrix_sethsv(170, 255, 150);
}


enum custom_keycodes {
    CSTSETGREEN,
    CSTSETRED,
    CSTSETTOGGLE,
    CSTSETBLUE,
    CSTSETBREATHE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CSTSETGREEN:
            if (record->event.pressed) {
                // rgb_matrix_set_color_all(255, 0, 0);
                rgb_matrix_sethsv(85, 255, 150);
            } else {
                //
            }
            break;
        case CSTSETRED:
            if (record->event.pressed) {
                // rgb_matrix_set_color_all(255, 0, 0);
                rgb_matrix_sethsv(0, 255, 150);
            } else {
                //
            }
            break;
        case CSTSETTOGGLE:
            if (record->event.pressed) {
                // rgb_matrix_set_color_all(255, 0, 0);
                //   rgb_matrix_sethsv(0, 255, 0);
                rgb_matrix_toggle();
            } else {
                //
            }
            break;
        case CSTSETBLUE:
            if (record->event.pressed) {
                // rgb_matrix_set_color_all(0, 0, 255);
                rgb_matrix_sethsv(170, 255, 150);
            } else {
                //
            }
            break;
        case CSTSETBREATHE:
            if (record->event.pressed) {
                // rgb_matrix_set_color_all(0, 0, 255);
                //   rgb_matrix_sethsv(240, 255, 150);
                // rgb_matrix_mode(RGB_MATRIX_BREATHING);
                rgb_matrix_step();
            } else {
                //
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 
// Base layer

[0] = LAYOUT(
    CSTSETBREATHE,  _______,    KC_3,       KC_PGDOWN,  KC_PGUP,    KC_6,                                                       KC_LEFT,    KC_UP,      KC_DOWN,    KC_RIGHT,   _______,    _______, 
    CSTSETGREEN,    KC_ESC,     DE_J,       DE_D,       DE_U,       DE_A,       DE_X,                          KC_P,            KC_H,       KC_L,       KC_M,       KC_W,       DE_SS,      CSTSETBREATHE, 
    CSTSETRED,      KC_TAB,     KC_C,       KC_T,       KC_I,       KC_E,       KC_O,                          KC_B,            KC_N,       KC_R,       KC_S,       KC_G,       KC_Q,       CSTSETRED, 
    CSTSETBLUE,     KC_LSFT,    DE_F,       DE_V,       DE_UDIA,    DE_ADIA,    DE_ODIA,                       KC_Y,            KC_Z,       KC_COMMA,   KC_DOT,     KC_K,       KC_RSFT,    CSTSETBLUE, 
    CSTSETTOGGLE,   KC_LCTRL,   KC_LGUI,    KC_LALT,    KC_LEAD,    KC_BSPACE,  KC_SPACE, KC_DOWN,      TG(1), OSM(MOD_LSFT),   OSL(2),     KC_LEAD,    KC_RALT,    KC_RGUI,    KC_RCTRL,   CSTSETTOGGLE),

    [1] = LAYOUT(
    TO(0),      _______,     _______,       _______,    _______,  _______,                                                           _______,    _______,    _______,       _______,     _______,     _______,
    _______,    _______,     KC_COMMA,      KC_7,       KC_8,     KC_9,       _______,                                    _______,   _______,    _______,    _______,       _______,     _______,     _______,    
    _______,    _______,     KC_DOT,        KC_4,       KC_5,     KC_6,       _______,                                    _______,   _______,    _______,    _______,       _______,     _______,     _______,    
    _______,    _______,     KC_0,          KC_1,       KC_2,     KC_3,       _______,                                    _______,   _______,    _______,    _______,       _______,     _______,     _______,    
    _______,    _______,     _______,       _______,    _______,  _______,    _______,    _______,            _______,    _______,   _______,    _______,    _______,       _______,     _______,     _______
), 
// special signs layer
[2] = LAYOUT(
    _______,    _______,     _______,       _______,    _______,  _______,                                                                _______,      _______,     _______,   _______,    _______,    _______,
    _______,    _______,     DE_AT,         DE_UNDS,    DE_LBRC,  DE_RBRC,    _______,                                     DE_EXLM,        DE_LABK,      DE_RABK,     DE_EQL,    DE_AMPR,    _______,    _______,    
    _______,    _______,     DE_BSLS,       DE_SLSH,    DE_LCBR,  DE_RCBR,    DE_ASTR,                                    DE_QUES,        DE_LPRN,      DE_RPRN,     DE_MINS,   DE_COLN,    _______,    _______,    
    _______,    _______,     DE_HASH,       DE_DLR,     DE_PIPE,  DE_TILD,    _______,                                   DE_PLUS,        DE_PERC,      DE_DQUO,     DE_QUOT,   DE_SCLN,    _______,    _______,    
    _______,    _______,     _______,       _______,    _______,  KC_DEL,     _______,    _______,            _______,    _______,        _______,      _______,     _______,   _______,    _______,    _______
),


};


