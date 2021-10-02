#include "libc/x/x.h"
/* clang-format off */

static bool gbkext_decmap_once;
static void *gbkext_decmap_ptr;
static const unsigned char gbkext_decmap_rodata[] = {
  0xed, 0xd0, 0xdf, 0x4b, 0x13, 0x00, 0x1c, 0x04, 0xf0, 0xe9, 0x5a, 0xae, 0x96,
  0x3f, 0x72, 0xd5, 0x56, 0xcb, 0x52, 0xa7, 0x6b, 0x6e, 0xb5, 0xcc, 0xd9, 0x1a,
  0x06, 0xe3, 0x22, 0x10, 0x42, 0x50, 0x44, 0x10, 0x7c, 0x09, 0xc2, 0x30, 0xc2,
  0x28, 0x44, 0x21, 0x42, 0x21, 0x82, 0x20, 0x06, 0x41, 0x04, 0x51, 0x2f, 0x82,
  0xa7, 0x0c, 0x8a, 0x31, 0x48, 0x62, 0x90, 0x44, 0xa0, 0x08, 0x12, 0x04, 0x11,
  0x04, 0xbd, 0x08, 0x82, 0x0a, 0x82, 0x09, 0x83, 0x14, 0x06, 0xfa, 0xe0, 0x97,
  0xce, 0x37, 0xff, 0x87, 0x3c, 0xf8, 0x70, 0xaf, 0xc7, 0x39, 0x1c, 0x07, 0xf9,
  0xdf, 0x53, 0xe2, 0x80, 0xcd, 0xc9, 0xd3, 0x12, 0x58, 0xaa, 0x14, 0xb6, 0x2b,
  0x5f, 0x9d, 0xb0, 0xd1, 0x43, 0xb0, 0x36, 0x17, 0x6c, 0x47, 0x66, 0x0e, 0xc3,
  0x1e, 0x97, 0xc1, 0x12, 0x6e, 0x58, 0x51, 0xf2, 0x47, 0x60, 0xc3, 0x47, 0x61,
  0x2d, 0x1e, 0xd8, 0xa6, 0x4c, 0x1f, 0x83, 0x3d, 0x2a, 0x87, 0xc5, 0x2a, 0x60,
  0x05, 0xc9, 0x55, 0xc2, 0x06, 0xab, 0x60, 0x91, 0xe3, 0xb0, 0x3f, 0xf2, 0xa1,
  0x1a, 0x76, 0xcf, 0x0b, 0x0b, 0x9d, 0x80, 0xad, 0x49, 0xe6, 0x24, 0xac, 0xff,
  0x14, 0xac, 0xde, 0x07, 0x5b, 0xf1, 0x65, 0xb2, 0xeb, 0xbe, 0xc9, 0xec, 0xfe,
  0x4d, 0x5b, 0xbe, 0xe5, 0xe2, 0x5e, 0xbb, 0xfd, 0x98, 0x4b, 0xfb, 0xf1, 0x76,
  0xd9, 0x0f, 0xde, 0x38, 0x0d, 0x4e, 0x89, 0xf3, 0x0c, 0x78, 0x57, 0x16, 0x24,
  0x14, 0x00, 0x5f, 0xc8, 0xba, 0xdc, 0x3a, 0x0b, 0x66, 0xc5, 0x53, 0x03, 0x3e,
  0x90, 0x1f, 0x12, 0x3b, 0x07, 0xbe, 0x92, 0xbf, 0xd2, 0x7d, 0x1e, 0xfc, 0x24,
  0xde, 0x5a, 0x70, 0x44, 0x7e, 0x4b, 0xa2, 0x0e, 0x7c, 0x27, 0xdb, 0xd2, 0x57,
  0x0f, 0x7e, 0x91, 0x40, 0x10, 0x1c, 0x93, 0x25, 0x49, 0x35, 0x80, 0x13, 0xe2,
  0x68, 0x04, 0xef, 0xc8, 0xbc, 0x04, 0x43, 0xe0, 0x73, 0x59, 0x93, 0xf6, 0x0b,
  0xe0, 0x7b, 0x71, 0x87, 0xc1, 0xfb, 0xf2, 0x5d, 0xa2, 0x4d, 0xe0, 0x4b, 0x29,
  0x48, 0x67, 0x04, 0xfc, 0x28, 0x55, 0x51, 0x70, 0x48, 0x7e, 0x49, 0xfc, 0x22,
  0xf8, 0x46, 0x8a, 0xd2, 0x7b, 0x09, 0xfc, 0x2c, 0xfe, 0x18, 0xf8, 0x44, 0x16,
  0xe5, 0xfa, 0x65, 0x70, 0x5c, 0x76, 0xe5, 0x76, 0x33, 0x38, 0x2b, 0xb5, 0x57,
  0xc0, 0x67, 0xb2, 0x2a, 0x37, 0x5b, 0xc0, 0x8c, 0xb8, 0xe2, 0xe0, 0x80, 0x7c,
  0x93, 0x70, 0x2b, 0x98, 0x96, 0x0d, 0xe9, 0xb8, 0x0a, 0xe6, 0xa4, 0x3c, 0x01,
  0x3e, 0x94, 0x9f, 0xd2, 0x7c, 0x0d, 0x7c, 0x2d, 0x5b, 0xd2, 0x93, 0x04, 0xf3,
  0x49, 0x74, 0xed, 0xfd, 0xfb, 0x0f,
};

optimizesize void *gbkext_decmap(void) {
  if (gbkext_decmap_once) return gbkext_decmap_ptr;
  return xload(&gbkext_decmap_once,
               &gbkext_decmap_ptr,
               gbkext_decmap_rodata,
               370, 1024); /* 36.1328% profit */
}
