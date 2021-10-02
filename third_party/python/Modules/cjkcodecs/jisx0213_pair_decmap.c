#include "libc/x/x.h"
/* clang-format off */

static bool jisx0213_pair_decmap_once;
static void *jisx0213_pair_decmap_ptr;
static const unsigned char jisx0213_pair_decmap_rodata[] = {
  0x63, 0x60, 0x18, 0x5c, 0x80, 0x91, 0xa1, 0xbc, 0x9a, 0x8d, 0xa1, 0xbc, 0x8e,
  0x8f, 0xa1, 0xa2, 0x02, 0x5d, 0x8e, 0x9f, 0xc1, 0x25, 0x8d, 0x61, 0x14, 0x8c,
  0x82, 0x51, 0x40, 0x35, 0x00, 0x00,
};

optimizesize void *jisx0213_pair_decmap(void) {
  if (jisx0213_pair_decmap_once) return jisx0213_pair_decmap_ptr;
  return xload(&jisx0213_pair_decmap_once,
               &jisx0213_pair_decmap_ptr,
               jisx0213_pair_decmap_rodata,
               32, 1024); /* 3.125% profit */
}
