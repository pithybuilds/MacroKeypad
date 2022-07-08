/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

//needed for led stuff!! for common led config i think*
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xEEEE
#define PRODUCT_ID      0x2019
#define DEVICE_VER		0x0001
#define MANUFACTURER    PithyBuilds
#define PRODUCT         L1V32a

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 2

#define MATRIX_ROW_PINS { B5, B4, E6, B6 }
#define MATRIX_COL_PINS { D4, B3 }
#define UNUSED_PINS

//added for led----------vvvvvvvvvvvvv---------
#define DIODE_DIRECTION COL2ROW

#define RGB_DI_PIN D1
#define DRIVER_LED_TOTAL 4
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
//added for led----------^^^^^^^^^^^^^---------

/* encoder added by stevec - revers direction by swapping below - or change assignment in Vial*/
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { B2 }

//uid - generate your own and add it here
#define VIAL_KEYBOARD_UID {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}