/*-*-mode:c++;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8-*-│
│vi: set net ft=c++ ts=2 sts=2 sw=2 fenc=utf-8                              :vi│
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
#include "libc/stdio/stdio.h"
#include "third_party/libcxx/map"
#include "third_party/libcxx/string"

int main(int argc, char *argv[]) {
  printf("std::map + std::string example\n");
  std::map<std::string, int> m{
      {"CPU", 10},
      {"GPU", 15},
      {"RAM", 20},
  };
  printf("m[\"CPU\"] is %d\n", m["CPU"]);
  printf("m[\"RAM\"] is %d\n", m["RAM"]);
  printf("m[\"GPU\"] is %d\n", m["GPU"]);
  printf("setting cpu to 25\n");
  m["CPU"] = 25;  // update an existing value
  printf("m[\"CPU\"] is %d\n", m["CPU"]);
  printf("m[\"RAM\"] is %d\n", m["RAM"]);
  printf("m[\"GPU\"] is %d\n", m["GPU"]);
}
