/* Copyright 2019 ENDO Katsuhiro <ka2hiro@kagizaraya.jp>
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

/*
 * Board config
 */
/*
#define NUM_BOARDS  2

#define BOARD_INFOS \
{ \
    { \
        true, \
        false, \
        0x00, \
        { D4, D5, D6, D7 }, \
        { D1, D0, C3, C2, C1, C0 }, \
        { B1, B2 }, \
        { false, false }, \
        NULL \
    }, \
    { \
        false, \
        false, \
        0x20, \
        { GPB4, GPB5, GPB6, GPB7 }, \
        { GPA7, GPA6, GPA5, GPA4, GPA3, GPA2 }, \
        { GPB0, GPB1 }, \
        { false, false }, \
        NULL \
    }, \
}
*/
#define VIAL_KEYBOARD_UID {0x8E, 0x81, 0x84, 0xE1, 0xEE, 0xD0, 0xDB, 0x8D}
#define VIAL_UNLOCK_COMBO_ROWS {0, 1}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
