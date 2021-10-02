#include "libc/x/x.h"
/* clang-format off */

static bool jisxcommon_encmap_once;
static void *jisxcommon_encmap_ptr;
static const unsigned char jisxcommon_encmap_rodata[] = {
  0xed, 0xcb, 0x3d, 0x4f, 0x93, 0x61, 0x18, 0xc5, 0xf1, 0x73, 0xdd, 0xcf, 0x53,
  0x6a, 0xd1, 0x0a, 0xad, 0xa8, 0x55, 0xaa, 0xf8, 0x86, 0x50, 0xb0, 0x82, 0x56,
  0x4b, 0x2b, 0x2a, 0xd0, 0x82, 0x56, 0xc0, 0x4a, 0xdf, 0x0c, 0xa5, 0x4d, 0xfc,
  0x08, 0x8e, 0x1a, 0x12, 0x27, 0x1a, 0xd3, 0xd9, 0xd5, 0x44, 0xa7, 0x26, 0xce,
  0xc6, 0x60, 0xf4, 0x0b, 0xb0, 0x39, 0xb9, 0x3a, 0xea, 0x6a, 0x88, 0x1a, 0xb4,
  0xed, 0x7d, 0x1d, 0x1f, 0xbe, 0x81, 0x13, 0x2c, 0xfe, 0x93, 0xdf, 0x72, 0x92,
  0x23, 0xa8, 0xb3, 0x05, 0xfc, 0x7a, 0x29, 0x5b, 0x5f, 0xde, 0x4a, 0xe3, 0x93,
  0x15, 0x79, 0x84, 0x3d, 0xac, 0x6e, 0xfa, 0xa7, 0x9b, 0xc6, 0xf9, 0xbc, 0xe6,
  0xa0, 0x05, 0x37, 0x1c, 0xde, 0xdd, 0xc4, 0xc5, 0xf7, 0x6d, 0xd7, 0xf7, 0xf8,
  0x9f, 0xfe, 0x3e, 0x28, 0xf6, 0xa1, 0x5a, 0x0f, 0x58, 0xf3, 0x7b, 0x0e, 0x40,
  0xd7, 0x02, 0xd0, 0x6a, 0x2f, 0x58, 0x3d, 0x88, 0x76, 0xf9, 0x90, 0xb0, 0x14,
  0x04, 0x4b, 0x87, 0x7d, 0xcc, 0xf7, 0x81, 0xf9, 0x7e, 0xd8, 0xe5, 0x90, 0xe1,
  0x62, 0x18, 0x36, 0x77, 0x04, 0xcc, 0x0d, 0x88, 0x5d, 0x38, 0x2a, 0x9a, 0x3d,
  0x06, 0x66, 0x8f, 0x0b, 0x33, 0x11, 0xbf, 0x4d, 0x9f, 0x00, 0xd3, 0x27, 0x3d,
  0x83, 0xd2, 0x4e, 0x44, 0x7b, 0x18, 0x3f, 0x05, 0xc6, 0x4f, 0x7b, 0x86, 0x3c,
  0x67, 0x8c, 0x8d, 0x9d, 0x05, 0x63, 0xe7, 0x60, 0x47, 0xce, 0x1b, 0x0e, 0x5f,
  0x30, 0x3f, 0x23, 0xc3, 0x6e, 0x37, 0x74, 0x11, 0x0c, 0x8d, 0x88, 0xf6, 0x8d,
  0xc2, 0x06, 0x63, 0x0e, 0x7b, 0xc7, 0xa0, 0x81, 0x71, 0x43, 0xff, 0x25, 0xd0,
  0x1f, 0x77, 0xe8, 0x5e, 0x86, 0x3a, 0x13, 0xe8, 0x62, 0xd2, 0x50, 0x27, 0xd1,
  0xed, 0x5c, 0x01, 0x3b, 0x57, 0x8d, 0xfe, 0x4e, 0x40, 0x77, 0xae, 0xa1, 0xf3,
  0xe3, 0x3a, 0x5e, 0xbd, 0x48, 0x26, 0x59, 0x9f, 0x82, 0xd6, 0x52, 0x86, 0xd5,
  0x34, 0x74, 0xf5, 0x06, 0xec, 0xc3, 0x69, 0x61, 0xe5, 0x26, 0x58, 0xb9, 0x05,
  0x2d, 0xdf, 0x06, 0xcb, 0x33, 0xa2, 0xc5, 0x59, 0x61, 0x61, 0x0e, 0x2c, 0x64,
  0xf0, 0x7a, 0x3b, 0x33, 0xc5, 0x8f, 0x59, 0xe1, 0x87, 0x79, 0xd1, 0xf7, 0x0b,
  0xd0, 0xcd, 0x3b, 0xe0, 0xe6, 0x5d, 0x4f, 0xce, 0x73, 0x0f, 0xf6, 0xdd, 0xa2,
  0x34, 0x52, 0x4b, 0x4f, 0xbe, 0xbd, 0x59, 0x8a, 0x76, 0x9a, 0xcb, 0x60, 0xf3,
  0xbe, 0xe8, 0xf3, 0xbc, 0x61, 0xe3, 0x81, 0x70, 0x63, 0x05, 0xdc, 0x28, 0xe0,
  0xcf, 0xb3, 0xa2, 0xd1, 0xf5, 0x92, 0xe1, 0xd3, 0xb2, 0x69, 0xe1, 0x7f, 0xfb,
  0x56, 0xb4, 0x22, 0x5f, 0xff, 0x02,
};

optimizesize void *jisxcommon_encmap(void) {
  if (jisxcommon_encmap_once) return jisxcommon_encmap_ptr;
  return xload(&jisxcommon_encmap_once,
               &jisxcommon_encmap_ptr,
               jisxcommon_encmap_rodata,
               370, 1024); /* 36.1328% profit */
}
