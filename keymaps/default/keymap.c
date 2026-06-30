// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keycodes {
    TROUTKEY = SAFE_RANGE,
    BASSKEY,
    SALMONKEY,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) { // I love good documentation
    switch (keycode) {
    case TROUTKEY:
        if (record->event.pressed) {
            SEND_STRING("Trout");
        } else {
        }
        break;

    case BASSKEY:
        if (record->event.pressed) {
            SEND_STRING("BASS");
        } else {
        }
        break;

    case SALMONKEY:
        if (record->event.pressed) {
           SEND_STRING("SALMON");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
       TROUTKEY,   SALMONKEY,   BASSKEY,   KC_D
    )
    [1] = LAYOUT(
        KC_A,   KC_B,   KC_C,   KC_D
    )
    [2] = LAYOUT(
        KC_A,   KC_B,   KC_C,   KC_D
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(TO(0), TO(1))}, // can I make TO like TO(Layer+1/-1)
    [1] = { ENCODER_CCW_CW(TO(0), TO(2))},
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
};
#endif