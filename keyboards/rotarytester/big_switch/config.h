/*
Copyright 2020 zFrontier <carl.xia@zfrontier.com>

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
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0A01
#define DEVICE_VER 0x0005
#define MANUFACTURER zFrontier
#define PRODUCT Red Comet Big Switch

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { B5 }
#define MATRIX_COL_PINS { B6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


/* long tapping config */
#define TAPPING_TERM 500


#define ENCODERS_PAD_A { E6 }
#define ENCODERS_PAD_B { B5 }

#define ENCODER_RESOLUTION 4 