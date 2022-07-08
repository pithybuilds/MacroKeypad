/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
//------led stuff----
#include "raw_hid.h"
#include "quantum.h"

// led stuff
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { 0, 1 },
  { 2, 3 },
}, {
  // LED Index to Physical Position
    { 0, 0 }, { 1, 0 }, { 2,0 }, { 3, 0 },
}, {
  // LED Index to Flag
  4, 4, 4, 4
} };

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1, KC_2,
        KC_3, KC_4,
        KC_5, KC_6,
        KC_8
    ),

    [1] = LAYOUT(
        ____, ____,
        ____, ____,
        ____, ____,
        ____
    ),

    [2] = LAYOUT(
        ____, ____,
        ____, ____,
        ____, ____,
        ____
    ),

    [3] = LAYOUT(
        ____, ____,
        ____, ____,
        ____, ____,
        ____
    )
};

//--------led stuff---you can have any color!--the values below are all white color for led--first column value defines the
//--------led position in your physical soldered led chain--other 3 values are r,g,b--
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)) {
        case 0:
            rgb_matrix_set_color(0, 1, 1, 1);
            rgb_matrix_set_color(1, 0, 0, 0);
            rgb_matrix_set_color(2, 0, 0, 0);
            rgb_matrix_set_color(3, 0, 0, 0);
            break;
        case 1:
            rgb_matrix_set_color(0, 1, 1, 1);
            rgb_matrix_set_color(1, 1, 1, 1);
            rgb_matrix_set_color(2, 0, 0, 0);
            rgb_matrix_set_color(3, 0, 0, 0);
            break;
        case 2:
            rgb_matrix_set_color(0, 1, 1, 1);
            rgb_matrix_set_color(1, 1, 1, 1);
            rgb_matrix_set_color(2, 1, 1, 1);
            rgb_matrix_set_color(3, 0, 0, 0);
            break;
        case 3:
            rgb_matrix_set_color(0, 1, 1, 1);
            rgb_matrix_set_color(1, 1, 1, 1);
            rgb_matrix_set_color(2, 1, 1, 1);
            rgb_matrix_set_color(3, 1, 1, 1);
            break;
        default:
            break;
    }
}




//----i think this is needed for led stuff
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    if(data[0] == 0xFC){
        switch (data[1]) {
            case 0x01:{
                // move to layer
                data[1] = 0xFD;
                layer_move(data[2]);
                break;
            }
            case 0x02:{
                // turn on layer
                data[1] = 0xFD;
                layer_on(data[2]);
                break;
            }
            case 0x03:{
                // turn off layer
                data[1] = 0xFD;
                layer_off(data[2]);
                break;
            }
        }
    }
    raw_hid_send(data, length);
}