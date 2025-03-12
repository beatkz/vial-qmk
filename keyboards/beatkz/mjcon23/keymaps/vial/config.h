// Copyright 2024 Keiji MOMOSE (@beatkz)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

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

#define VIAL_KEYBOARD_UID {0x61, 0xE6, 0x7B, 0xA2, 0x4E, 0xA1, 0x7A, 0x22}
#define VIAL_UNLOCK_COMBO_ROWS {1, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 4}
#define DYNAMIC_KEYMAP_LAYER_COUNT 15
