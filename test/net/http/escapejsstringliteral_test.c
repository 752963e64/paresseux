/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2021 Justine Alexandra Roberts Tunney                              │
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
#include "libc/calls/calls.h"
#include "libc/runtime/gc.internal.h"
#include "libc/stdio/stdio.h"
#include "libc/testlib/ezbench.h"
#include "libc/testlib/hyperion.h"
#include "libc/testlib/testlib.h"
#include "net/http/escape.h"

char *escapejs(const char *s) {
  char *p;
  size_t n;
  p = EscapeJsStringLiteral(s, strlen(s), &n);
  ASSERT_EQ(strlen(p), n);
  return p;
}

TEST(EscapeJsStringLiteral, test) {
  EXPECT_STREQ("", gc(escapejs("")));
  EXPECT_STREQ("\\u00ff", gc(escapejs("\377")));
  EXPECT_STREQ("\\u00ff\\u0080\\u0080\\u0080\\u0080",
               gc(escapejs("\377\200\200\200\200")));
  EXPECT_STREQ("\\u0001\\u0002\\u0003 \\u0026\\u003d\\u003c\\u003e\\/",
               gc(escapejs("\1\2\3 &=<>/")));
}

TEST(EscapeJsStringLiteral, testUcs2) {
  EXPECT_STREQ("\\u00d0\\u263b", gc(escapejs("Ð☻")));
}

TEST(EscapeJsStringLiteral, testAstralPlanes) {
  EXPECT_STREQ("\\ud800\\udf30\\ud800\\udf30", gc(escapejs("𐌰𐌰")));
}

TEST(EscapeJsStringLiteral, testBrokenUnicode_sparesInnocentCharacters) {
  EXPECT_STREQ("\\u00e1YO", gc(escapejs("\xE1YO")));
}

void makefile1(void) {
  FILE *f;
  char *p;
  size_t n;
  p = EscapeJsStringLiteral(kHyperion, kHyperionSize, &n);
  f = fopen("/tmp/a", "wb");
  fwrite(p, n, 1, f);
  fclose(f);
  free(p);
}

void makefile2(void) {
  int fd;
  char *p;
  size_t n;
  p = EscapeJsStringLiteral(kHyperion, kHyperionSize, &n);
  fd = creat("/tmp/a", 0644);
  write(fd, p, n);
  close(fd);
  free(p);
}

BENCH(EscapeJsStringLiteral, bench) {
  EZBENCH2("escapejs", donothing,
           free(EscapeJsStringLiteral(kHyperion, kHyperionSize, 0)));
  EZBENCH2("makefile1", donothing, makefile1());
  EZBENCH2("makefile2", donothing, makefile2());
}
