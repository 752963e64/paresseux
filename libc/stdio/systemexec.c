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
#include "libc/dce.h"
#include "libc/macros.internal.h"
#include "libc/paths.h"
#include "libc/runtime/runtime.h"
#include "libc/str/str.h"
#include "libc/sysv/errfuns.h"

/**
 * Executes system command replacing current process.
 * @vforksafe
 */
int systemexec(const char *cmdline) {
  size_t n, m;
  char *a, *b, *argv[4], comspec[PATH_MAX];
  if (!IsWindows()) {
    argv[0] = _PATH_BSHELL;
    argv[1] = "-c";
  } else {
    b = "cmd.exe";
    a = kNtSystemDirectory;
    if ((n = strlen(a)) + (m = strlen(b)) >= ARRAYLEN(comspec)) {
      return enametoolong();
    }
    memcpy(mempcpy(comspec, a, n), b, m + 1);
    argv[0] = comspec;
    argv[1] = "/C";
  }
  argv[2] = cmdline;
  argv[3] = NULL;
  return execv(argv[0], argv);
}
