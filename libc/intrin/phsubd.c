/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2020 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/intrin/phsubd.h"
#include "libc/str/str.h"

/**
 * Subtracts adjacent 32-bit integers.
 *
 * @param 𝑎 [w/o] receives reduced 𝑏 and 𝑐 concatenated
 * @param 𝑏 [r/o] supplies two pairs of ints
 * @param 𝑐 [r/o] supplies two pairs of ints
 * @note goes fast w/ ssse3
 * @mayalias
 */
void(phsubd)(uint32_t a[4], const uint32_t b[4], const uint32_t c[4]) {
  uint32_t t[4];
  t[0] = b[0] - b[1];
  t[1] = b[2] - b[3];
  t[2] = c[0] - c[1];
  t[3] = c[2] - c[3];
  __builtin_memcpy(a, t, sizeof(t));
}
