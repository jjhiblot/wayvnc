/*
 * Copyright (c) 2019 Andri Yngvason
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <xkbcommon/xkbcommon.h>

#include "intset.h"

struct vnc_keyboard_v1;

struct vnc_keyboard {
	struct vnc_keyboard_v1* virtual_keyboard;
};

int vnc_keyboard_init(struct vnc_keyboard* self);
void vnc_keyboard_destroy(struct vnc_keyboard* self);
void vnc_keyboard_feed(struct vnc_keyboard* self, xkb_keysym_t symbol, bool is_pressed);
void vnc_keyboard_feed_code(struct vnc_keyboard* self, xkb_keycode_t code,
		bool is_pressed);
