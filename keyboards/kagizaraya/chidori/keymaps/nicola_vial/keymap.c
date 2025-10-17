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
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
#include "sendstring_japanese.h"

#include "board.h"

enum layer_number { _QWERTY = 0, _NICOLA, _RAISE, _ADJUST };

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;

enum NICOLA_Stats_Keys {
    NCL_OFF = QK_KB_0,
    NCL_ON
};
// NICOLA親指シフト

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QWERTY = SAFE_RANGE };

#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |ADJUST| Esc  | Alt  | GUI  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, RAISE,   KC_SPC,          NCL_ON,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

 /* Nicola
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  。  |  か  |  た  |  こ  |  さ  |             |  ら  |  ち  |  く  |  つ  |  、  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  う  |  し  |  て  |  け  |  せ  |             |  は  |  と  |  き  |  い  |  ん  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  。  |  ひ  |  す  |  ふ  |  へ  |             |  め  |  そ  |  ね  |  ほ  |  ・  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |左親指|             |右親指|      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   *
   * 左親指キー同時押し
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  ぁ  |  え  |  り  |  ゃ  |  れ  |             |  ぱ  |  ぢ  |  ぐ  |  づ  |  ぴ  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  を  |  あ  |  な  |  ゅ  |  も  |             |  ば  |  ど  |  ぎ  |  ぽ  |  ん  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  ぅ  |  ー  |  ろ  |  や  |  ぃ  |             |  ぷ  |  ぞ  |  ぺ  |  ぼ  |  ・  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |左親指|             |右親指|      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   * 右親指キー同時押し
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  。  |  が  |  だ  |  ご  |  ざ  |             |  よ  |  に  |  る  |  ま  |  ぇ  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  ヴ  |  じ  |  で  |  げ  |  ぜ  |             |  み  |  お  |  の  |  ょ  |  っ  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  。  |  び  |  ず  |  ぶ  |  べ  |             |  ぬ  |  ゆ  |  む  |  わ  |  ぉ  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |左親指|             |右親指|      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */

    [_NICOLA] = LAYOUT(
      _______,   NG_Q,     NG_W,    NG_E,    NG_R,    NG_T,              NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, _______,
      _______,   NG_A,     NG_S,    NG_D,    NG_F,    NG_G,              NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, _______,
      _______,   NG_Z,     NG_X,    NG_C,    NG_V,    NG_B,              NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH, _______,
      _______, _______, _______, _______, NCL_OFF, NG_SHFTL,         NG_SHFTR, _______, _______, _______, _______, _______

   ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |             |  F12 |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_RAISE] = LAYOUT(
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,             KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,            KC_F12,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, ADJUST, _______,           _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |      |      |      |      | Ins  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Caps |      |      |      |      |      |             |      |  -   |   =  |Print |ScLock|Pause |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | KANA |      | Home |PageDn|PageUp| End  |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] = LAYOUT(
      _______, QK_BOOT, _______, _______, _______, _______,           _______, _______, _______, _______,  _______, KC_INS,
      KC_CAPS, _______, _______, _______, _______, _______,           _______, KC_MINS, KC_EQL,  KC_PSCR, KC_SCRL, KC_PAUS,
      _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,           _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    )
};
// clang-format on
static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    // NICOLA親指シフト
    case NCL_OFF:
      if (record->event.pressed) {
        fn_pressed = true;
        fn_pressed_time = record->event.time;

        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);

        if(fn_pressed
        && (TIMER_DIFF_16(record->event.time, fn_pressed_time) < TAPPING_TERM)){
            nicola_off();
        }
        fn_pressed = false;
      }
      return false;
      break;
    case NCL_ON:
      if (record->event.pressed) {
        nicola_on();
        fn_pressed = false;
      }
      return false;
      break;
    // NICOLA親指シフト

    default:
        if(record->event.pressed){
            fn_pressed = false;
        }
        break;
  }

  // NICOLA親指シフト
  bool a = true;
  if (nicola_state()) {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
  }
  if (a == false) return false;
  // NICOLA親指シフト
    return true;
}

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

bool led_update_user(led_t led_state) {
    board_set_led_by_index(0, LED_YELLOW, led_state.caps_lock);
    board_set_led_by_index(1, LED_YELLOW, led_state.scroll_lock);

    return false;
}
