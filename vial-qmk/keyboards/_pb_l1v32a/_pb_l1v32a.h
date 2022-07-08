/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "quantum.h"

#define LAYOUT( \
	K00, K01, \
	K10, K11, \
	K20, K21, \
		 K31  \
) { \
	{ K00,	 K01 }, \
	{ K10,   K11 }, \
	{ K20,	 K21 }, \
	{ KC_NO, K31 }  \
}

//need a blank line space at end of code duh.