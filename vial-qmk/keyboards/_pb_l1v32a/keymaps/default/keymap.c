#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1, KC_2,
        KC_3, KC_4,
        KC_5, KC_6,
        KC_8
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_KP_PLUS);
        } else {
            tap_code(KC_KP_MINUS);
        }
        //return true;  <----was this
        return true;
}
#endif // ENCODER_ENABLE
