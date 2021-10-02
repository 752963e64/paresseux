#include "libc/x/x.h"
/* clang-format off */

static bool gb2312_decmap_once;
static void *gb2312_decmap_ptr;
static const unsigned char gb2312_decmap_rodata[] = {
  0xed, 0xcb, 0xbd, 0x2b, 0xc4, 0x01, 0x00, 0xc6, 0xf1, 0xdf, 0xef, 0xbc, 0xdc,
  0x1d, 0x0e, 0xe7, 0xed, 0xce, 0x4b, 0xea, 0x91, 0x62, 0x52, 0x67, 0xa1, 0x4c,
  0x4c, 0x8a, 0x85, 0x49, 0x51, 0x4a, 0x51, 0xa2, 0x24, 0xb9, 0x92, 0xeb, 0xb1,
  0x60, 0x52, 0x2c, 0xac, 0x4c, 0x0a, 0x03, 0xd9, 0x98, 0x14, 0x0b, 0x93, 0x62,
  0xa1, 0x4c, 0x4c, 0x8a, 0x85, 0x95, 0x7c, 0xff, 0x01, 0x56, 0xcb, 0x7d, 0xeb,
  0xd3, 0x33, 0x3d, 0x41, 0xf0, 0xff, 0x85, 0x81, 0x3c, 0x1e, 0x64, 0x72, 0x47,
  0x6c, 0x3c, 0xd4, 0xc2, 0x58, 0xa8, 0xec, 0x69, 0xa8, 0x91, 0xd7, 0x50, 0xf3,
  0x3d, 0x11, 0x4d, 0xaf, 0x46, 0x5a, 0xe7, 0x7e, 0xfb, 0xde, 0x46, 0xe4, 0x8e,
  0x02, 0x79, 0x03, 0xaf, 0xe8, 0x2f, 0x94, 0xf7, 0x51, 0x58, 0x24, 0x4f, 0xe0,
  0x02, 0xcd, 0xc5, 0x72, 0x0e, 0x8f, 0xe8, 0x8e, 0xca, 0x3b, 0xf8, 0xc4, 0x70,
  0x4c, 0x3e, 0x41, 0x79, 0x5c, 0x9e, 0xc5, 0x0d, 0xda, 0x4b, 0xe4, 0x75, 0xbc,
  0xa0, 0xaf, 0x54, 0xde, 0xc3, 0x37, 0xc6, 0xca, 0xe4, 0x73, 0xa4, 0x13, 0x72,
  0x16, 0xf7, 0xe8, 0x2c, 0x97, 0xb7, 0xf0, 0x8e, 0xc1, 0x0a, 0xf9, 0x10, 0xb1,
  0x4a, 0x79, 0x0a, 0x57, 0x68, 0x49, 0x6a, 0x69, 0x39, 0x29, 0x3f, 0xa0, 0xab,
  0x4a, 0xde, 0xc6, 0x07, 0x86, 0xaa, 0xe5, 0x63, 0x24, 0x6a, 0xe4, 0x19, 0x5c,
  0xa3, 0xad, 0x56, 0x5e, 0xc3, 0x33, 0x7a, 0xeb, 0xe4, 0x5d, 0x7c, 0x61, 0x34,
  0x25, 0x9f, 0x21, 0x95, 0x96, 0x17, 0x71, 0x87, 0x4c, 0xbd, 0xbc, 0x89, 0x37,
  0x0c, 0x34, 0xc8, 0x07, 0x88, 0x36, 0xca, 0x93, 0xb8, 0x84, 0x9a, 0xe4, 0x15,
  0x3c, 0x21, 0xc8, 0x97, 0xef, 0x8f, 0x7e, 0x00,
};

optimizesize void *gb2312_decmap(void) {
  if (gb2312_decmap_once) return gb2312_decmap_ptr;
  return xload(&gb2312_decmap_once,
               &gb2312_decmap_ptr,
               gb2312_decmap_rodata,
               242, 1024); /* 23.6328% profit */
}
