#include "libc/x/x.h"
/* clang-format off */

static bool cp932ext_decmap_once;
static void *cp932ext_decmap_ptr;
static const unsigned char cp932ext_decmap_rodata[] = {
  0x63, 0x60, 0x18, 0x05, 0x23, 0x1d, 0x30, 0x32, 0xc4, 0x9f, 0xc2, 0x26, 0x9e,
  0xcb, 0xe0, 0x30, 0x67, 0x34, 0x74, 0x06, 0x1f, 0x38, 0xc5, 0xe0, 0xf0, 0xa7,
  0x9d, 0xd1, 0xe1, 0x0f, 0x29, 0x7a, 0x5c, 0x98, 0x1c, 0xfe, 0x30, 0x32, 0x3b,
  0xfc, 0xd9, 0xc7, 0xec, 0xe0, 0x8d, 0x2c, 0x0e, 0x00,
};

optimizesize void *cp932ext_decmap(void) {
  if (cp932ext_decmap_once) return cp932ext_decmap_ptr;
  return xload(&cp932ext_decmap_once,
               &cp932ext_decmap_ptr,
               cp932ext_decmap_rodata,
               48, 1024); /* 4.6875% profit */
}
