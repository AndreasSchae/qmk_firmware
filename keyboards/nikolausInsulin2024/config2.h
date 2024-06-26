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
#define PRODUCT_ID 0x0005
#define DEVICE_VER 0x0001
#define MANUFACTURER NikolausInsulin
#define PRODUCT PieceOfGarbage
/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

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

//#define MATRIX_ROW_PINS { B3, B2, B6}
//#define MATRIX_COL_PINS { D0, D4, C6, D7, E6, B4, B5}
//#define UNUSED_PINS

// row pins arduino code: 16, 14, 15, A0, A1. from bottom to top
// #define MATRIX_ROW_PINS { B2, B3, B1, F7, F6}
#define MATRIX_ROW_PINS \
    { B3, B1, F7, F6, F5, F4 }  // top to bottom

// column pins arduino code: 4, 5, 6, 7, 8, 9, 10. from inside to outside
// #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, B6}
#define MATRIX_COL_PINS \
    { B6, B5, B4, E6, D7, B2 }  // outside to inside

// row pins arduino code: 16, 14, 15, A0, A1. from bottom to top
// #define MATRIX_ROW_PINS { B2, B3, B1, F7, F6}
#define MATRIX_ROW_PINS_RIGHT \
    { B3, B1, F7, F6, F5, F4 }  // top to bottom
// column pins arduino code: 4, 5, 6, 7, 8, 9, 10. from outside to inside
// #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, B6}
#define MATRIX_COL_PINS_RIGHT \
    { B6, B5, B4, E6, D7, B2 }  // inside (left) to outside (right)
#define UNUSED_PINS

#define MASTER_RIGHT

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6

//#define BACKLIGHT_PIN B7
//#define BACKLIGHT_LEVELS 3
//#define BACKLIGHT_BREATHING

/* RGB light config */
#define RGB_DI_PIN D3

//#define RGBLED_NUM 29
/*
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_ANIMATIONS
#define DRIVER_LED_TOTAL 29
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_COUNT 1
*/
//#define RGBLIGHT_EFFECT_BREATHE_CENTER 2.0
//#define RGBLIGHT_EFFECT_BREATHE_MAX 255

#ifdef RGB_MATRIX_ENABLE
// The number of LEDs connected
#    define DRIVER_LED_TOTAL 58
#    define RGBLIGHT_SPLIT
#    define RGB_MATRIX_SPLIT \
        { 29, 29 }

// #  define RGB_DISABLE_TIMEOUT 300000 // number of milliseconds to wait until disabling effects
// #  define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5  // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16                            // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100                        // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

// Enable animations
// #  define ENABLE_RGB_MATRIX_ALPHAS_MODS                 // Static dual hue speed is hue for secondary hue
// #  define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN            // Static gradient top to bottom speed controls how much gradient changes
// #  define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT         // Static gradient left to right speed controls how much gradient changes
#    define ENABLE_RGB_MATRIX_BREATHING  // Single hue brightness cycling animation
// #  define ENABLE_RGB_MATRIX_BAND_SAT                    // Single hue band fading saturation scrolling left to right
// #  define ENABLE_RGB_MATRIX_BAND_VAL                    // Single hue band fading brightness scrolling left to right
// #  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT           // Single hue 3 blade spinning pinwheel fades saturation
// #  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL           // Single hue 3 blade spinning pinwheel fades brightness
// #  define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT             // Single hue spinning spiral fades saturation
// #  define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL             // Single hue spinning spiral fades brightness
// #  define ENABLE_RGB_MATRIX_CYCLE_ALL                   // Full keyboard solid hue cycling through full gradient
// #  define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT            // Full gradient scrolling left to right
// #  define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN               // Full gradient scrolling top to bottom
// #  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN                // Full gradient scrolling out to in
// #  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL           // Full dual gradients scrolling out to in
// #  define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON      // Full gradent Chevron shapped scrolling left to right
// #  define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL              // Full gradient spinning pinwheel around center of keyboard
// #  define ENABLE_RGB_MATRIX_CYCLE_SPIRAL                      // Full gradient spinning spiral around center of keyboard
// #  define ENABLE_RGB_MATRIX_DUAL_BEACON                 // Full gradient spinning around center of keyboard
// #  define ENABLE_RGB_MATRIX_RAINBOW_BEACON              // Full tighter gradient spinning around center of keyboard
// #  define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS           // Full dual gradients spinning two halfs of keyboard
// #  define ENABLE_RGB_MATRIX_RAINDROPS                   // Randomly changes a single key's hue
// #  define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS         // Randomly changes a single key's hue and saturation
// #  define ENABLE_RGB_MATRIX_HUE_BREATHING               // Hue shifts up a slight ammount at the same time then shifts back
// #  define ENABLE_RGB_MATRIX_HUE_PENDULUM                // Hue shifts up a slight ammount in a wave to the right then back to the left
// #  define ENABLE_RGB_MATRIX_HUE_WAVE                          // Hue shifts up a slight ammount and then back down in a wave to the right
// #    define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Required for the following two effects
// #  define ENABLE_RGB_MATRIX_TYPING_HEATMAP               // How hot is your WPM!
// #  define ENABLE_RGB_MATRIX_DIGITAL_RAIN                 // That famous computer simulation
// #    define RGB_MATRIX_KEYPRESSES // reacts to keypresses, required for the remaining effects
// #    define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE       // Pulses keys hit to hue & value then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE              // Static single hue pulses keys hit to shifted hue then fades to current hue
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE         // Hue & value pulse near a single key hit then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE    // Hue & value pulse near multiple key hits then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS        // Hue & value pulse the same column and row of a single key hit then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS   // Hue & value pulse the same column and row of multiple key hits then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS        // Hue & value pulse away on the same column and row of a single key hit then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS   // Hue & value pulse away on the same column and row of multiple key hits then fades value out
// #  define ENABLE_RGB_MATRIX_SPLASH                      // Full gradient & value pulse away from a single key hit then fades value out
// #  define ENABLE_RGB_MATRIX_MULTISPLASH                 // Full gradient & value pulse away from multiple key hits then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_SPLASH                // Hue & value pulse away from a single key hit then fades value out
// #  define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH           // Hue & value pulse away from multiple key hits then fades value out
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

#define COMBO_COUNT 3
#define COMBO_TERM 100

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#define LEADER_TIMEOUT 400
#define LEADER_PER_KEY_TIMING

//#define BOOTMAGIC_LITE_ROW_LEFT 0
//#define BOOTMAGIC_LITE_COLUMN_LEFT 0

#define ENCODERS_PAD_A \
    { D0, F5 }
#define ENCODERS_PAD_B \
    { D1, F4 }
#define ENCODER_RESOLUTIONS \
    { 4, 4 }

#define ENCODERS_PAD_A_RIGHT \
    { D0, F5 }
#define ENCODERS_PAD_B_RIGHT \
    { D1, F4 }
#define ENCODER_RESOLUTIONS_RIGHT \
    { 4, 4 }
