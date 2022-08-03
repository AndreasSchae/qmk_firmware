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

#include "Andi_V1.h"


#ifdef RGB_MATRIX_ENABLE

// Logical Layout
// Columns
//  0  1  2  3  4
//                   ROWS
//  4  3  2  1  0      0
//  5  6  7  8  9      1
// 14 13 12 11 10      2
//       15 16 17      3

// Logical Layout v1.3
// Columns
//  0  1  2  3  4  5  6  7  8  9
//                                 ROWS
//  0  1  2  3  4  5  6  7  8  9     0
// 19 18 17 16 15 14 13 12 11 10     1
// 20 21 22 23 24 25 26 27 28 29     2
//       35 34 33 32 31 30           3

led_config_t g_led_config = {{
                                //left
                                {   0,   1,  2,  3,  4,  5,  6},
                                {   13, 12, 11, 10,  9,  8,  7},
                                {   14, 15, 16, 17, 18, 19, 20},
                                {   27, 26, 25, 24, 23, 22, 21},
                                {   28, 29, 30, 31, 32, 33, 34},
                                //right
                                {   35, 36, 37, 38, 39, 40, 41},
                                {   42, 43, 44, 45, 46, 47, 48},
                                {   49, 50, 51, 52, 53, 54, 55},
                                {   56, 57, 58, 59, 60, 61, 62},
                                {   63, 64, 65, 66, 67, 68, 69}
                                 
    },{
                                //left (only placeholder so far)
                                { 31,  0}, { 46,  0}, { 62,  0}, { 77,  7}, { 93, 13}, {131, 13}, {147,  7},
                                {162,  0}, {178,  0}, {193,  0}, {201, 10}, {185, 10}, {170, 10}, {154, 17},
                                {139, 24}, { 85, 24}, { 70, 17}, { 54, 10}, { 39, 10}, { 23, 10}, { 15, 20},
                                { 31, 20}, { 46, 20}, { 62, 27}, { 77, 34}, {147, 34}, {162, 27}, {178, 20},
                                {193, 20}, {209, 20}, {185, 34}, {170, 37}, {154, 44}, { 70, 44}, { 54, 37},
                                 // right (only placeholder so far)
                                {122, 85}, {102, 85}, { 81, 85}, {102, 64}, {102, 43}, {102, 21}, { 81, 21},
                                { 81, 43}, { 81, 64}, { 61, 64}, { 61, 43}, { 61, 21}, { 41, 21}, { 41, 43},
                                { 41, 64}, { 20, 64}, { 20, 43}, { 20, 21}, {143, 85}, {163, 85}, {183, 85},
                                {163, 64}, {163, 43}, {163, 21}, {183, 21}, {183, 43}, {183, 64}, {204, 64},
                                {204, 43}, {204, 21}, {224, 21}, {224, 43}, {224, 64}, {244, 64}, {244, 43}
                              
    },{
                                 //left
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 //right
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4,
                                 4, 4, 4, 4, 4, 4, 4
    }};
#endif
