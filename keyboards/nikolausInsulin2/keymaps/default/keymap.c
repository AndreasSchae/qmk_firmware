/* Copyright 2020 foostan
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
#include "keymap_german.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    tapdanceSpace, 
    //tapdanceTabAltTab, 
    tapdanceEscAltF4, // sends ESC on press and Alt+F4 on hold 
    tapdanceMin1MinAll, // sends windows+down (make windows smaller/minimize) on press and windows+m (minimize all windows) on hold
    tapdanceMaximizeFullscreen, // sends windows+down (make windows bigger/maximize) on press and F11 (go fullscreen) on hold 
    tapdanceEndShiftEnd,
    tapdanceHomeShiftHome, 
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

/*
// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);
*/

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, DE_UDIA):
            return TAPPING_TERM + 200;
        case LALT_T(DE_ODIA):
            return TAPPING_TERM + 200;
        case RALT_T(KC_DOT):
            return TAPPING_TERM + 200;
        case MT(MOD_RGUI, KC_J):
            return TAPPING_TERM + 200; 
        default:
            return TAPPING_TERM;
    }
}


bool is_alt_tab_active = false; //this is for super alt tab
uint16_t alt_tab_timer = 0;


enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    CIRCUM,
    BACKTICK,
    MINMZE,
    CSTRST, 
    CSTSETRED, 
    CSTSETBLUE, 
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BACKTICK:
      if (record->event.pressed) {
          // when keycode QMKBEST is pressed
          SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_EQL) SS_TAP(X_EQL) SS_UP(X_LSFT) SS_TAP(X_BSPACE));
          //SEND_STRING(SS_TAP(X_EQL));
      } else {
          // when keycode QMKBEST is released
      }
      break;
    case CIRCUM:
      if (record->event.pressed) {
          // when keycode QMKBEST is pressed
          SEND_STRING(SS_TAP(X_GRAVE) SS_TAP(X_GRAVE) SS_TAP(X_BSPACE));
          //SEND_STRING(SS_TAP(X_EQL));
      } else {
          // when keycode QMKBEST is released
      }
      break;
    case ALT_TAB:
      if (record->event.pressed) {
        // SEND_STRING("alttab triggerd");
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {    
        unregister_code(KC_TAB);
      }
      break;
    case MINMZE: 
    // minimize all windows
      if (record->event.pressed) {
        SEND_STRING(SS_LWIN(SS_TAP(X_M)));
      } else {    
        // 
      }
      break;
    case CSTRST:
      if (record->event.pressed) {
          reset_keyboard();
      } else {
          //
      }
      break;
    case CSTSETRED:
      if (record->event.pressed) {
          //rgb_matrix_set_color_all(255, 0, 0);
      } else {
          //
      }
      break;
    case CSTSETBLUE:
      if (record->event.pressed) {
          //rgb_matrix_set_color_all(0, 0, 255);
      } else {
          //
      }
      break;
    }
    return true;
};

// all leader key commands go here 
LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    
    SEQ_TWO_KEYS(KC_S, KC_S) {
      // make windows screenshot
      SEND_STRING(SS_LWIN(SS_TAP(X_PSCREEN))); 
    }
    SEQ_FOUR_KEYS(KC_S, KC_N, KC_I, KC_P) {
        // windows snipping tool
        SEND_STRING(SS_LWIN(SS_LSFT(SS_TAP(X_S))));
    }
    /*
    SEQ_FOUR_KEYS(KC_T, KC_A, KC_S, KC_K) {
        // windows task manager
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_ESC))));
    } */

    /*
    SEQ_FOUR_KEYS(KC_C, KC_A, KC_P, KC_S) {
      // toggle capslock
      SEND_STRING(SS_TAP(X_CAPS));
    }
    SEQ_FOUR_KEYS(KC_L, KC_O, KC_C, KC_K) {
      // lock windows
      SEND_STRING(SS_LWIN(SS_TAP(X_L)));
    }
    SEQ_FOUR_KEYS(KC_M, KC_U, KC_T, KC_E) {
      // toggle mute
      SEND_STRING(SS_TAP(X_MUTE));
    }    
    SEQ_FOUR_KEYS(KC_D, KC_I, KC_C, KC_T) {
        // open windows dictation mode
        SEND_STRING(SS_LWIN(SS_TAP(X_H)));
    } */

    /*
    // Neo system tray application toggle
    SEQ_THREE_KEYS(KC_N, KC_E, KC_O) {
      SEND_STRING(SS_LSFT(SS_TAP(X_PAUSE)) SS_DELAY(5) SS_TAP(X_LSFT));
    } */

    /*
    // windows window rearrangement
    // note how n is left arrow, r is down arrow, t is right arrow, g is up arrow
    // First group sends windowskey + direction
    SEQ_TWO_KEYS(KC_W, KC_N) {
      SEND_STRING(SS_LWIN(SS_TAP(X_LEFT)));
    }
    SEQ_TWO_KEYS(KC_W, KC_T) {
      SEND_STRING(SS_LWIN(SS_TAP(X_RIGHT)));
    }
    SEQ_TWO_KEYS(KC_W, KC_G) {
      SEND_STRING(SS_LWIN(SS_TAP(X_UP)));
    }
    SEQ_TWO_KEYS(KC_W, KC_R) {
      SEND_STRING(SS_LWIN(SS_TAP(X_DOWN)));
    }
    // Second group sends windowskey + shift + direction
    SEQ_THREE_KEYS(KC_W, KC_S, KC_N) {
      SEND_STRING(SS_LWIN(SS_LSFT(SS_TAP(X_LEFT))));
    }
    SEQ_THREE_KEYS(KC_W, KC_S, KC_T) {
      SEND_STRING(SS_LWIN(SS_LSFT(SS_TAP(X_RIGHT))));
    }
    SEQ_THREE_KEYS(KC_W, KC_S, KC_G) {
      SEND_STRING(SS_LWIN(SS_LSFT(SS_TAP(X_UP))));
    }
    SEQ_THREE_KEYS(KC_W, KC_S, KC_R) {
      SEND_STRING(SS_LWIN(SS_LSFT(SS_TAP(X_DOWN))));
    } */



    // BROWSER COMMANDS
    /*
    SEQ_TWO_KEYS(KC_T, KC_L) {
      // tab left
      SEND_STRING(SS_LCTL(SS_TAP(X_PGUP)));
    }
    SEQ_TWO_KEYS(KC_T, KC_R) {
      // tab right
      SEND_STRING(SS_LCTL(SS_TAP(X_PGDOWN)));
    }
    SEQ_FOUR_KEYS(KC_B, KC_O, KC_O, KC_K) {
      // bookmark 
      SEND_STRING(SS_LCTL("d"));
    } */
    
    // LAYER SWITCHING
    /*
    SEQ_FOUR_KEYS(KC_A, KC_N, KC_K, KC_I) {
      // anki layer
      layer_on(4);
    }
    SEQ_FIVE_KEYS(KC_Q, KC_W, KC_E, KC_R, KC_T) {
      // qwert layer
      layer_on(3);
    }
    SEQ_FOUR_KEYS(KC_G, KC_A, KC_M, KC_E) {
      // gaming layer
      layer_on(5);
    } */
    
    // MACROS FOR OBSIDIAN & ANKI 
    SEQ_ONE_KEY(KC_Q) {
      // Q: A: 
      SEND_STRING("Q"SS_LSFT(SS_TAP(X_DOT))" "SS_TAP(X_ENTER)"A"SS_LSFT(SS_TAP(X_DOT))" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_Q, KC_R) {
      // QR: A: 
      SEND_STRING("QR"SS_LSFT(SS_TAP(X_DOT))" "SS_TAP(X_ENTER)"A"SS_LSFT(SS_TAP(X_DOT))" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
    }    
    SEQ_TWO_KEYS(KC_E, KC_G) {
      // English: German:  
      SEND_STRING("English"SS_LSFT(SS_TAP(X_DOT))" "SS_TAP(X_ENTER)"German"SS_LSFT(SS_TAP(X_DOT))" "SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
    } 
    SEQ_FIVE_KEYS(KC_A, KC_L, KC_I, KC_A, KC_S) {
      // --- aliases: [] --- 
      SEND_STRING(""SS_TAP(X_SLSH)SS_TAP(X_SLSH)SS_TAP(X_SLSH)SS_TAP(X_ENTER)"aliases"SS_LSFT(SS_TAP(X_DOT))" "SS_ALGR(SS_TAP(X_8))SS_ALGR(SS_TAP(X_9))SS_TAP(X_ENTER)""SS_TAP(X_SLSH)SS_TAP(X_SLSH)SS_TAP(X_SLSH)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
    } 

    // KEYBOARD COMMANDS
    SEQ_FIVE_KEYS(KC_R, KC_E, KC_S, KC_E, KC_T) {
      // reset keyboard into bootloader mode
      reset_keyboard();
    }
    

  }
  
  // super alt tab timer
  if (is_alt_tab_active) { 
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
} 

/*
static uint16_t default_animation = RGB_MODE_BREATHE;
static int default_speed = 50;
*/
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
    //rgb_matrix_set_color_all(255, 0, 0);
}



// when adding combos change combocount in config.h

enum combos {
  //winCombo,
  //altCombo, 
  //superAltTabCombo, 
  shiftCombo, 
  shiftCombo2, 
  shiftComboR, 
};

//const uint16_t PROGMEM ueuo_combo[] = {DE_UE, DE_OE, COMBO_END};
//const uint16_t PROGMEM oeae_combo[] = {DE_OE, DE_AE, COMBO_END};
//const uint16_t PROGMEM superalttab_combo[] = {KC_C, KC_W, COMBO_END};
const uint16_t PROGMEM shift_combo[] = {KC_TAB, KC_U, COMBO_END};
const uint16_t PROGMEM shift2_combo[] = {KC_TAB, KC_DOT, COMBO_END};
const uint16_t PROGMEM shiftR_combo[] = {KC_D, DE_Y, COMBO_END};
//const uint16_t PROGMEM layer_combo[] = {KC_C, KC_W, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  //[winCombo] = COMBO(ueuo_combo, KC_LWIN),
  //[altCombo] = COMBO(oeae_combo, KC_LALT), 
  //[superAltTabCombo] = COMBO(superalttab_combo, ALT_TAB), 
  [shiftCombo] = COMBO(shift_combo, KC_LSHIFT),
  [shiftCombo2] = COMBO(shift2_combo, KC_LSHIFT),
  [shiftComboR] = COMBO(shiftR_combo, KC_RSHIFT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
    _______,  RGB_TOG,              RGB_MODE_BREATHE,                CSTSETRED,          CSTRST,              KC_LEAD,  _______,                                   _______,    KC_LEAD,   TO(6),    _______,        _______,            _______,    _______,
    TD(tapdanceMaximizeFullscreen),  TD(tapdanceEscAltF4), KC_X,                   KC_V,             KC_L,               KC_C,     KC_W,                                      KC_K,       KC_H,      KC_G,       KC_F,           KC_Q,               DE_SS,      KC_MS_WH_UP,    
    ALT_TAB,  KC_TAB,               KC_U,                   KC_I,             KC_A,               KC_E,     KC_O,                                      KC_S,       KC_N,      KC_R,       KC_T,           KC_D,               DE_Y,       KC_MS_WH_DOWN,    
    TD(tapdanceMin1MinAll),   KC_LCTRL,             MT(MOD_LGUI, DE_UDIA),  LALT_T(DE_ODIA),  DE_ADIA,            KC_P,     DE_Z,                                      KC_B,       KC_M,      KC_COMMA,   RALT_T(KC_DOT), MT(MOD_RGUI, KC_J), KC_RCTRL,   _______,    
                                                                KC_BSPACE,    TD(tapdanceSpace),   KC_DOWN,                 TG(1), OSM(MOD_LSFT), OSL(2)
  ), 
// numpad and arrows layer
[1] = LAYOUT(
    TO(0),      _______,     _______,           _______,       _______,  _______,    _______,                                    _______,                  _______,    _______,    _______,       _______,                 _______,     _______,
    _______,    _______,     KC_COMMA,          KC_7,          KC_8,     KC_9,       _______,                                    _______,                  C(KC_LEFT), KC_UP,      C(KC_RIGHT),   _______,                 _______,     _______,    
    _______,    _______,     KC_DOT,            KC_4,          KC_5,     KC_6,       _______,                                    TD(tapdanceHomeShiftHome), KC_LEFT,   KC_DOWN,    KC_RIGHT,      TD(tapdanceEndShiftEnd), _______,     _______,    
    _______,    _______,     MT(MOD_LGUI, KC_0),LALT_T(KC_1),  KC_2,     KC_3,       _______,                                    _______,                  _______,    _______,    _______,       _______,                 _______,     _______,    
                                                                _______,       _______,    _______,                _______,    _______,   _______
), 
// special signs layer
[2] = LAYOUT(
    _______,    _______,     _______,       _______,      _______,     _______,      _______,                                    _______,        _______,      _______,     _______,   _______,    _______,    _______,
    _______,    _______,     DE_AT,         DE_UNDS,      DE_LBRC,     DE_RBRC,      CIRCUM,                                     DE_EXLM,        DE_LABK,      DE_RABK,     DE_EQL,    DE_AMPR,    _______,    _______,    
    _______,    _______,     DE_BSLS,       DE_SLSH,      DE_LCBR,     DE_RCBR,      DE_ASTR,                                    DE_QUES,         DE_LPRN,      DE_RPRN,     DE_MINS,   DE_COLN,    _______,    _______,    
    _______,    _______,     DE_HASH,       DE_DLR,       DE_PIPE,     DE_TILD,      BACKTICK,                                   DE_PLUS,        DE_PERC,      DE_DQUO,     DE_QUOT,   DE_SCLN,    _______,    _______,    
                                                                            KC_DEL,    _______,    _______,                _______,    _______,   _______
), 

// qwertz layer
[3] = LAYOUT(
    TO(0),      _______,     KC_1,        KC_2,       KC_3,           KC_4,        KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       DE_SS,    _______,
    _______,    _______,     KC_Q,        KC_W,       KC_E,           KC_R,        KC_T,                                   DE_Z,       KC_U,       KC_I,       KC_O,       KC_P,       DE_UDIA,    _______,
    _______,    _______,     KC_A,        KC_S,       KC_D,           KC_F,        KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_ENT,     DE_ADIA,    _______,
    _______,    _______,     DE_Y,        KC_X,       KC_C,           KC_V,        KC_B,                                   KC_N,       KC_M,       KC_COMM,    KC_DOT,     DE_MINS,    _______,    _______,
                                                                            _______,    _______,    _______,    _______,    _______,   _______
), 
// anki layer
[4] = LAYOUT(
    TO(0),      _______,     _______,     _______,    _______,        _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,     _______,     _______,    _______,        _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    
    _______,    _______,     KC_1,        KC_2,       KC_3,           KC_4,       KC_5,                                   _______,    _______,    _______,    _______,    _______,    _______,    _______,    
    _______,    _______,     _______,     _______,    _______,        _______,    _______,                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    
                                                                            _______,    _______,    _______,    _______,    _______,   _______
), 
// gaming layer 
/*
[5] = LAYOUT(
    TO(0),      _______,     _______,     KC_1,        KC_2,       KC_3,           KC_4,        KC_5,                                   KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       DE_SS, 
    _______,    _______,     KC_TAB,      KC_Q,        KC_W,       KC_E,           KC_R,        KC_T,                                   DE_Z,       KC_U,       KC_I,       KC_O,       KC_P,       DE_UDIA, 
    _______,    _______,     KC_CAPS,     KC_A,        KC_S,       KC_D,           KC_F,        KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_ENT,     DE_ADIA, 
    _______,    _______,     KC_LSFT,     DE_Y,        KC_X,       KC_C,           KC_V,        KC_B,                                   KC_N,       KC_M,       KC_COMM,    KC_DOT,     DE_MINS,    _______, 
                                                                            KC_MS_BTN1,    _______,    KC_MS_BTN2,    _______,    _______,   _______
), */
// testing layer
/*
[6] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,       KC_8, KC_9, KC_0, DE_A, DE_B, DE_C, DE_D, 
    DE_E, TO(0),DE_G, DE_H, DE_I, DE_J, DE_K,       DE_L, DE_M, DE_N, DE_O, DE_P, DE_Q, DE_R, 
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,       KC_8, KC_9, KC_0, DE_A, DE_B, DE_C, DE_D, 
    DE_E, DE_F, DE_G, DE_H, DE_I, DE_J, DE_K,       DE_L, DE_M, DE_N, DE_O, DE_P, DE_Q, DE_R, 
                      KC_1,    KC_2,    KC_3,       KC_4,    KC_5,   KC_6
), */

};

/* 
[1] = LAYOUT(
    _______,            _______,            _______,    _______,        _______, _______,                                   _______,        _______, _______,   _______, _______, _______,
    _______,            _______,            _______,    _______,        _______, _______,                                   _______,        _______, _______,   _______, _______, _______,
    _______,            _______,            _______,    _______,        _______, _______,                                   _______,        _______, _______,   _______, _______, _______,
                                                                            _______,    _______,    _______,    _______,    _______,   _______
)
*/

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) > 0) {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        } else if (index == 1) {
            if (clockwise) {
                SEND_STRING(SS_LCTL(SS_TAP(X_PGUP)));
            } else {
                SEND_STRING(SS_LCTL(SS_TAP(X_PGDOWN)));
            }
        }
    } else {  /* Layer 0 */
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_WH_D);
            } else {
                tap_code(KC_WH_U);
            }
        }
    }
    return false;
}


/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
// maybe better implementation at example 5 here: 
// https://docs.qmk.fm/#/feature_tap_dance?id=example-1-send-on-single-tap-on-double-tap
// find implementation that does not go up to 3 taps. 

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}


static td_tap_t spacetap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t escaltf4tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t min1minalltap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t maximizefullscreentap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t endshiftendtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t homeshifthometap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// spaceEnter Tapdance
void space_finished(qk_tap_dance_state_t *state, void *user_data) {
    spacetap_state.state = cur_dance(state);
    switch (spacetap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_SPACE); break;
        case TD_SINGLE_HOLD: tap_code(KC_ENTER); break;
        case TD_DOUBLE_TAP: tap_code(KC_SPACE); tap_code(KC_SPACE); break;
        case TD_DOUBLE_HOLD: register_code(KC_LSFT); tap_code(KC_ENTER); unregister_code(KC_LSFT); break;
        default: ;
    }
}
void space_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (spacetap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SPACE); break;
        case TD_SINGLE_HOLD: unregister_code(KC_ENTER); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SPACE); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SPACE); unregister_code(KC_ENTER);
        default: ;
    }
    spacetap_state.state = TD_NONE;
}

// escAltF4 Tapdance
void escaltf4_finished(qk_tap_dance_state_t *state, void *user_data) {
    escaltf4tap_state.state = cur_dance(state);
    switch (escaltf4tap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_ESC); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT); break;
        case TD_DOUBLE_TAP: tap_code(KC_ESC); tap_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT); break;
        default: ;
    }
}
void escaltf4_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (escaltf4tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_F4); break;
        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F4); 
        default: ;
    }
    escaltf4tap_state.state = TD_NONE;
} 

// min1minAll Tapdance
void min1minall_finished(qk_tap_dance_state_t *state, void *user_data) {
    min1minalltap_state.state = cur_dance(state);
    switch (min1minalltap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LGUI); tap_code(KC_DOWN); unregister_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: register_code(KC_LGUI); tap_code(KC_M); unregister_code(KC_LGUI); break;
        case TD_DOUBLE_TAP: register_code(KC_LGUI); tap_code(KC_DOWN); unregister_code(KC_LGUI); register_code(KC_LGUI); tap_code(KC_DOWN); unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: register_code(KC_LGUI); tap_code(KC_M); unregister_code(KC_LGUI); break;
        default: ;
    }
}
void min1minall_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (min1minalltap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOWN); break;
        case TD_SINGLE_HOLD: unregister_code(KC_M); break;
        case TD_DOUBLE_TAP: unregister_code(KC_DOWN); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_M); 
        default: ;
    }
    min1minalltap_state.state = TD_NONE;
} 

// maximizeFullscreen Tapdance
void  maximizefullscreen_finished(qk_tap_dance_state_t *state, void *user_data) {
    maximizefullscreentap_state.state = cur_dance(state);
    switch (maximizefullscreentap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_LGUI); tap_code(KC_UP); unregister_code(KC_LGUI); break;
        case TD_SINGLE_HOLD: tap_code(KC_F11);  break;
        case TD_DOUBLE_TAP: register_code(KC_LGUI); tap_code(KC_UP); unregister_code(KC_LGUI); register_code(KC_LGUI); tap_code(KC_UP); unregister_code(KC_LGUI); break;
        case TD_DOUBLE_HOLD: tap_code(KC_F11);  break;
        default: ;
    }
}
void maximizefullscreen_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (maximizefullscreentap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_UP); break;
        case TD_SINGLE_HOLD: unregister_code(KC_F11); break;
        case TD_DOUBLE_TAP: unregister_code(KC_UP); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_F11); 
        default: ;
    }
    maximizefullscreentap_state.state = TD_NONE;
} 

// endShiftEnd Tapdance
void endshiftend_finished(qk_tap_dance_state_t *state, void *user_data) {
    endshiftendtap_state.state = cur_dance(state);
    switch (endshiftendtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_END); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); tap_code(KC_END); unregister_code(KC_LSFT); break;
        case TD_DOUBLE_TAP: tap_code(KC_END); break;
        case TD_DOUBLE_HOLD: tap_code(KC_END); break;
        default: ;
    }
}
void endshiftend_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (endshiftendtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_END); break;
        case TD_SINGLE_HOLD: unregister_code(KC_END); break;
        case TD_DOUBLE_TAP: unregister_code(KC_END); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_END);
        default: ;
    }
    endshiftendtap_state.state = TD_NONE;
}

// HomeShiftHome Tapdance
void homeshifthome_finished(qk_tap_dance_state_t *state, void *user_data) {
    homeshifthometap_state.state = cur_dance(state);
    switch (homeshifthometap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_HOME); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); tap_code(KC_HOME); unregister_code(KC_LSFT); break;
        case TD_DOUBLE_TAP: tap_code(KC_HOME); break;
        case TD_DOUBLE_HOLD: tap_code(KC_HOME); break;
        default: ;
    }
}
void homeshifthome_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (homeshifthometap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_HOME); break;
        case TD_SINGLE_HOLD: unregister_code(KC_HOME); break;
        case TD_DOUBLE_TAP: unregister_code(KC_HOME); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_HOME);
        default: ;
    }
    homeshifthometap_state.state = TD_NONE;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [tapdanceSpace] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset),
    [tapdanceEscAltF4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, escaltf4_finished, escaltf4_reset), 
    [tapdanceMin1MinAll] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, min1minall_finished, min1minall_reset), 
    [tapdanceMaximizeFullscreen] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, maximizefullscreen_finished, maximizefullscreen_reset), 
    [tapdanceEndShiftEnd] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, endshiftend_finished, endshiftend_reset), 
    [tapdanceHomeShiftHome] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, homeshifthome_finished, homeshifthome_reset), 
};




/*
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  // left 
  {   NO_LED, 0, 1, 2, 3, 4, NO_LED,},
  {   5, 6, 7, 8, 9, 10, 11,},
  {   12, 13, 14, 15, 16, 17, 18,},
  {   19, 20, 21, 22, 23, 24, 25,},
  {   NO_LED, NO_LED, NO_LED, NO_LED, 26, 27, 28,},
  // right 
  {   NO_LED, 29, 30, 31, 32, 33,  NO_LED,},
  {   34, 35, 36, 37, 38, 39, 40,},
  {   41, 42, 43, 44, 45, 46, 47,},
  {   48, 49, 50, 51, 52, 53, 54,},
  {   55, 56, 57, NO_LED, NO_LED, NO_LED, NO_LED,},
},
 {
  // LED Index to Physical Position
  // horizontal: 224/(14-1) = 17.23
  // vertical: 64/(5-1) = 16
  // left 
                { 16,  00 }, { 32,  00 }, { 48,  00 }, { 64,  00 }, { 80,  00 }, 
  {  00,  16 }, { 16,  16 }, { 32,  16 }, { 48,  16 }, { 64,  16 }, { 80,  16 }, { 96,  16 },
  {  00,  32 }, { 16,  32 }, { 32,  32 }, { 48,  32 }, { 64,  32 }, { 80,  32 }, { 96,  32 },
  {  00,  48 }, { 16,  48 }, { 32,  48 }, { 48,  48 }, { 64,  48 }, { 80,  48 }, { 96,  48 },
                                                       { 64,  64 }, { 80,  64 }, { 96,  64 }, 
  // right 
                { 128,  00 }, { 144,  00 }, { 160,  00 }, { 176,  00 }, { 192,  00 }, 
  { 112,  16 }, { 128,  16 }, { 144,  16 }, { 160,  16 }, { 176,  16 }, { 192,  16 }, { 208,  16 },
  { 112,  32 }, { 128,  32 }, { 144,  32 }, { 160,  32 }, { 176,  32 }, { 192,  32 }, { 208,  32 },
  { 112,  48 }, { 128,  48 }, { 144,  48 }, { 160,  48 }, { 176,  48 }, { 192,  48 }, { 208,  48 },
  { 112,  64 }, { 128,  64 }, { 144,  64 }, 
}, {
  // LED Index to Flag
  // left 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  // right 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
} };
*/

/*
void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
*/

/*
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,       KC_8, KC_9, KC_0, DE_A, DE_B, DE_C, DE_D, 
    DE_E, TO(0),DE_G, DE_H, DE_I, DE_J, DE_K,       DE_L, DE_M, DE_N, DE_O, DE_P, DE_Q, DE_R, 
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,       KC_8, KC_9, KC_0, DE_A, DE_B, DE_C, DE_D, 
    DE_E, DE_F, DE_G, DE_H, DE_I, DE_J, DE_K,       DE_L, DE_M, DE_N, DE_O, DE_P, DE_Q, DE_R, 
                      KC_1,    KC_2,    KC_3,       KC_4,    KC_5,   KC_6
                      */