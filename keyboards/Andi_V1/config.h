/*
Copyright 2020 foostan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x3265
#define PRODUCT_ID 0x0004
#define DEVICE_VER 0x0002
#define MANUFACTURER AndiEnterprise
#define PRODUCT RIPPuchi
/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */




// row pins left keyboard
#define MATRIX_ROW_PINS \
    { D4, C6, D7, E6, B4 }  // top to bottom

// column pins left keyboard
#define MATRIX_COL_PINS \
    { F4, F5, F6, F7, B1, B3, B2 }  // outside to inside

// row pins right keyboard
#define MATRIX_ROW_PINS_RIGHT \
    { D4, C6, D7, E6, B4 }  // top to bottom
// column pins right keyboard
#define MATRIX_COL_PINS_RIGHT \
    { F4, F5, F6, F7, B1, B3, B2 }  // inside (left) to outside (right)
#define UNUSED_PINS




/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW


/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6

#define MASTER_LEFT


#define RGBLIGHT_SPLIT
#define SPLIT_USB_DETECT

/* RGB light config */
#define RGB_DI_PIN D3

#define DRIVER_LED_TOTAL 70
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_STARTUP_VAL 150
#define RGB_MATRIX_SPLIT {35,35}
// /*== choose animations ==*/
//#define RGBLIGHT_EFFECT_RGB_TEST
//#define RGBLIGHT_EFFECT_ALTERNATING
#define ENABLE_RGB_MATRIX_BREATHING
#define RGB_DISABLE_WHEN_USB_SUSPENDED






/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE



/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define COMBO_COUNT 0
#define COMBO_TERM 100

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT


#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#define LEADER_TIMEOUT 400
#define LEADER_PER_KEY_TIMING


