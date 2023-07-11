/*
 * Copyright (c) 2019 - 2020 Andri Yngvason
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
 *
 * Acknowledgements: Reading Josef Gajdusek's wvnc code helped me understand
 * how to use the xkbcommon API to interface with the wayland virtual keyboard
 * interface.
 */

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>
#include <neatvnc.h>

#include "vnc-keyboard-unstable-v1.h"
#include "vnc_keyboard.h"

#define MAYBE_UNUSED __attribute__((unused))

int vnc_keyboard_init(struct vnc_keyboard* self)
{
	return 0;
}

void vnc_keyboard_destroy(struct vnc_keyboard* self)
{
}

void vnc_keyboard_feed(struct vnc_keyboard* self, xkb_keysym_t symbol, bool is_pressed)
{
	vnc_keyboard_v1_key(self->virtual_keyboard, 0, symbol, is_pressed);
}

void vnc_keyboard_feed_code(struct vnc_keyboard* self, xkb_keycode_t code,
		bool is_pressed)
{
	nvnc_log(NVNC_LOG_ERROR, "ERROR: %s is not supported", __func__);
}
