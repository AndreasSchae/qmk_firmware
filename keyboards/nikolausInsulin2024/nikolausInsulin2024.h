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

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// row pins arduino code: 16, 14, 15, A0, A1. from bottom to top
// #define MATRIX_ROW_PINS { B2, B3, B1, F7, F6}
// column pins arduino code: 4, 5, 6, 7, 8, 9, 10. from inside to outside 
// #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, B6}

 #define LAYOUT( \
 	L11, L12, L13, L14, L15, L16, L17, 					R17, R16, R15, R14, R13, R12, R11, \
 	L21, L22, L23, L24, L25, L26, L27, 					R27, R26, R25, R24, R23, R22, R21, \
 	L31, L32, L33, L34, L35, L36, L37, 					R37, R36, R35, R34, R33, R32, R31, \
 	L41, L42, L43, L44, L45, L46, L47, 					R47, R46, R45, R44, R43, R42, R41, \
	L51, L52, L53, L54, L55, LT1, LT2, LT3,		   RT3, RT2, RT1, R55, R54, R53, R52, R51 \
 ) \
 { \
 	{ L16,  L15,  L14,  L13,  L12,  L11}, \
 	{ L26,  L25,  L24,  L23,  L22,  L21}, \
 	{ L36,  L35,  L34,  L33,  L32,  L31}, \
 	{ L46,  L45,  L44,  L43,  L42,  L41}, \
 	{ LT1,  L55,  L54,  L53,  L52,  L51}, \
	{ L17,  L27,  L37,  L47,  LT2,  LT3}, \
 	{ R16,  R15,  R14,  R13,  R12,  R11}, \
 	{ R26,  R25,  R24,  R23,  R22,  R21}, \
 	{ R36,  R35,  R34,  R33,  R32,  R31}, \
 	{ R46,  R45,  R44,  R43,  R42,  R41}, \
 	{ RT1,  R55,  R54,  R53,  R52,  R51}, \
	{ R17,  R27,  R37,  R47,  RT2,  RT3} \
 }

/*
#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311 \
) \
{ \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311 } \
}
*/
