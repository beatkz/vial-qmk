// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <print.h>
#include "../trackpad/gr_trackpad65_config.h"

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC , KC_Q,    KC_W,    KC_E,            KC_R,           KC_T, KC_DEL,  KC_F5,   KC_F2,   KC_Y,    KC_U,           KC_I,             KC_O,    KC_P,    KC_MINS,
        KC_TAB , KC_A,    KC_S,    KC_D,            KC_F,           KC_G,                            KC_H,    KC_J,           KC_K,             KC_L,    KC_SCLN, KC_ENT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,            KC_V,           KC_B,                            KC_N,    KC_M,           KC_COMM,          KC_DOT,  KC_SLSH, KC_BSLS,
                 KC_LGUI, KC_LALT, LSFT_T(KC_LNG2), LT(2, JP_MHEN), KC_SPC,         LOW_SPEED,       NCL_ON,  KC_BSPC,  RSFT_T(KC_LNG1),  KC_LBRC, KC_RBRC,

        MS_BTN1, KC_NO, KC_NO, KC_NO, KC_NO,
        MS_BTN2, KC_NO, KC_NO, KC_NO, KC_NO,
        MS_BTN3, G(KC_TAB), KC_BTN5, G(KC_D), KC_BTN4,
        G(KC_S), G(KC_TAB), G(C(KC_RGHT)), G(KC_D), G(C(KC_LEFT)),
        GRTL_CS, GRTL_SS, GRTL_CC, GRTL_CA, GRTL_RVS, GRTL_RHS, GRTL_IC, GRTL_IS, GRTL_SO,
        GRT_VAL_5, GRT_VAL_4, GRT_VAL_2, GRT_OFF, GRT_ON, GRT_OFF, GRT_ON, GRT_ON, GRT_OFF,
        GRTL_1T, GRTL_2T, GRTL_3T, GRTL_4T
    ),
    [1] = LAYOUT(
        _______, NG_Q,    NG_W,    NG_E,    NG_R,    NG_T, _______, _______, _______,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,    NG_LBRC,
        _______, NG_A,    NG_S,    NG_D,    NG_F,    NG_G,                               NG_H,    NG_J,    NG_K,    NG_L,    NG_SCLN, _______,
        _______, NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                               NG_N,    NG_M,    NG_COMM, NG_DOT,  NG_SLSH, _______,
                 _______, _______, _______, NCL_OFF, NG_SHFTL,          _______,         NG_SHFTR,_______, _______, _______, _______,

        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    ),

    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______,
                 _______, _______, _______, _______, _______,          _______,          _______, KC_BSPC, _______, _______, _______,

        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
        KC_F11 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                            KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 ,
                 _______, _______, _______, _______, _______,          KC_KB_MUTE,       _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    ),
    [4] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______ ,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______ ,
                 _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______, _______,

        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
    [1] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN) },
    [2] =   { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [3] =   { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN) },
    [4] =   { ENCODER_CCW_CW(KC_UP, KC_DOWN) }
};

// NICOLA親指シフト
static bool nicola_active = false;
static bool fn_pressed = false;
static uint16_t fn_pressed_time = 0; // fn_pressed の押下時刻を保持
// NICOLA親指シフト

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
}

// タイマーによる fn_pressed のリセット
void matrix_scan_user(void) {
    if (fn_pressed && (TIMER_DIFF_16(timer_read(), fn_pressed_time) >= TAPPING_TERM)) {
        fn_pressed = false; // TAPPING_TERM 経過後に fn_pressed をリセット
    }
}

void matrix_init_user(void) {
    // NICOLA親指シフト
    set_nicola(1);
    // NICOLA親指シフト
}
