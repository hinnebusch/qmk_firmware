/* Copyright 2018 REPLACE_WITH_YOUR_NAME
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
#ifndef QCP_H
#define QCP_H

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_all(\
    K00, K01, K10, K11, K02, K03, K12, K13, K04, K05, K14, K15, K06, K27, K07, K18, K19, K08, K09, \
    K20, K21, K30, K31, K22, K23, K32, K33, K24, K25, K34, K35, K26, K47, K38, K39, K28, K29, \
    K40, K41, K50, K51, K42, K43, K52, K53, K44, K45, K54, K55, K46,      K58, K59, K48,      \
    K60, K61, K70, K71, K62, K63, K72, K73, K64, K65, K74, K75,      K67, K78, K79, K68, K69, \
    K80, K81,                K83,                K95, K94,      K86, K87, K98, K99, K88      \
) { \
    { K00,   K01,  K02,    K03,   K04,    K05,    K06,    K07,   K08,   K09 }, \
	{ K10,   K11,  K12,    K13,   K14,    K15,    KC_NO,    KC_NO,   K18,   K19 }, \
	{ K20,   K21,  K22,    K23,   K24,    K25,    K26,    K27,   K28,   K29 }, \
	{ K30,   K31,  K32,    K33,   K34,    K35,    KC_NO,    KC_NO,   K38,   K39 }, \
	{ K40,   K41,  K42,    K43,   K44,    K45,    K46,    K47, K48,   KC_NO }, \
	{ K50,   K51,  K52,    K53,   K54,    K55,    KC_NO,    KC_NO,   K58,   K59 }, \
	{ K60,   K61,  K62,    K63,   K64,    K65,    KC_NO,    K67,   K68,   K69 }, \
	{ K70,   K71,  K72,    K73,   K74,    K75,    KC_NO,    KC_NO,   K78,   K79 }, \
	{ K80,   K81,  KC_NO,    K83,   KC_NO,    KC_NO,    K86,    K87,   K88,   KC_NO }, \
	{ KC_NO,   KC_NO,  KC_NO,    KC_NO,   K94,    K95,    KC_NO,    KC_NO,   K98,   K99 } \
}

#endif
