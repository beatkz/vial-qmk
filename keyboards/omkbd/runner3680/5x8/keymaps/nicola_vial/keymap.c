#include QMK_KEYBOARD_H

// NICOLA親指シフト
#include "timer.h" // タイマー機能のために追加
#include "keymap_japanese.h"
#include "sendstring_japanese.h"
#include "nicola.h"
NGKEYS nicola_keys;

enum NICOLA_Stats_Keys {
    NCL_OFF = QK_KB_0,
    NCL_ON
};
// NICOLA親指シフト

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

enum layer_number {
    _QWERTY = 0,
    _NICOLA,
    _ADJUST
};

enum custom_keycodes {
  ADJUST = SAFE_RANGE,
  RGBRST
};

// Fillers to make layering more clear
#define EISU LALT(KC_GRV)
#define AD_MHEN LT(_ADJUST, JP_MHEN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-------------------------------------------------------.      ,--------------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  |   -  |   ^  |   \  |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |      |      |   Y  |   U  |   I  |   O  |   P  |   @  |   [  | Bksp |
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |      |      |   H  |   J  |   K  |   L  |   :  |   ;  |   ]  | Enter|
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |      |      |      |   N  |   M  |   ,  |   .  |   /  |   \  |  Up  | Shift|
     * |------+------+------+------+------+------+------+------|      |------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  | MHEN |  Del | Space| Enter|      |      | Bksp | HENK |Adjust|  F10 | Left | Down | Right|
     * `-------------------------------------------------------'      `-------------------------------------------------------'
     */
  [_QWERTY] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______, RGBRST ,     _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   _______, UG_NEXT,     _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   _______, UG_SATU,     _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   JP_LBRC, UG_VALU,     _______, JP_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS,
      _______, JP_ZKHK, _______, KC_LALT, KC_LGUI, AD_MHEN, KC_SPC, _______,     _______, NCL_ON,  KC_BSPC, KC_RGUI, _______,  _______, _______, _______
      ),

  [_NICOLA] = LAYOUT(
      _______, NG_1,    NG_2,    NG_3,    NG_4,    NG_5,    _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
      _______, NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,    _______, _______,     _______, _______, NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,    NG_LBRC,
      _______, NG_A,    NG_S,    NG_D,    NG_F,    NG_G,    _______, _______,     _______, _______, NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN, _______,
      _______, NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,    _______, _______,     _______, _______, NG_N,    NG_M,    NG_COMM, NG_DOT,  NG_SLSH, _______,
      _______, _______, _______, _______, _______, NCL_OFF, NG_SHFTL,_______,     _______, NG_SHFTR,_______, _______, _______, _______, _______, _______
      ),

  [_ADJUST] =  LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______,     _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      _______, RGBRST,  QK_BOOT, _______, _______, KC_F11,  _______, _______,     _______, _______, KC_F12,  _______, _______, _______, _______, JP_AT,
      _______, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, _______, _______, _______,     _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, JP_COLN, _______,
      _______, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_DEL,  _______, _______, _______, _______, _______
      )
};

// NICOLA親指シフト
static bool nicola_active = false;
static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0; // fn_pressed の押下時刻を保持
// NICOLA親指シフト

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        break;

      case RGBRST:
        #ifdef RGBLIGHT_ENABLE
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_config = rgblight_config;
          }
        #endif
        break;

    // NICOLA親指シフト
    case NCL_OFF:
        if (record->event.pressed) {
            fn_pressed = true;
            fn_pressed_time = timer_read(); // 押下時刻を記録
            layer_on(2); // レイヤー 2 をオン
        } else {
            layer_off(2); // レイヤー 2 をオフ
            // NCL_ON 直後（TAPPING_TERM 以内）の場合のみ、NICOLA モードと IME をオフ
            if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) < TAPPING_TERM)) {
                layer_off(1); // _NICOLA レイヤーをオフ
                nicola_off(); // NICOLA モードをオフ
                nicola_active = false; // NICOLA モード状態を更新
                #ifdef OS_WINDOWS
                tap_code(KC_INT5); // 無変換キーで IME をオフ
                #elif OS_MAC
                tap_code(KC_LNG2); // Mac の日本語入力オフ
                #endif
            }
            // NICOLA モードがオンの場合、IME 制御キーを送信せず、モードとレイヤーを維持
            fn_pressed = false;
        }
        return false;
        break;

    case NCL_ON:
        if (record->event.pressed) {
            nicola_on(); // NICOLA モードをオン
            layer_on(1); // _NICOLA レイヤーをオン
            nicola_active = true; // NICOLA モード状態を更新
            fn_pressed = true; // NCL_ON でも fn_pressed を設定
            fn_pressed_time = timer_read(); // 押下時刻を記録
            #ifdef OS_WINDOWS
            tap_code(KC_INT4); // 変換キーで IME をオン
            #elif OS_MAC
            tap_code(KC_LNG1); // Mac の日本語入力オン
            #endif
        }
        return false;
        break;
    // NICOLA親指シフト
    default:
        if (record->event.pressed) {
            fn_pressed = false; // 他のキー押下で fn_pressed をリセット
        }
        break;
    }

    // NICOLA親指シフト
    // NICOLA モードがアクティブな場合、NICOLA 専用のキー処理を行う
    bool continue_processing = true;
    if (nicola_active) {
        nicola_mode(keycode, record);
        continue_processing = process_nicola(keycode, record);
    }
    return continue_processing;
    // NICOLA親指シフト
  return true;
}

// タイマーによる fn_pressed のリセット
void matrix_scan_user(void) {
    if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) >= TAPPING_TERM)) {
        fn_pressed = false; // TAPPING_TERM 経過後に fn_pressed をリセット
    }
}

void matrix_init_user(void) {
    // NICOLA親指シフト
    set_nicola(_NICOLA);
    // NICOLA親指シフト
}
