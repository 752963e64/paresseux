#include "libc/x/x.h"
/* clang-format off */

static bool __cp932ext_decmap_once;
static void *__cp932ext_decmap_ptr;
static const unsigned char __cp932ext_decmap_rodata[872] = {
  0xe5, 0x92, 0x5d, 0x4c, 0xd3, 0x67, 0x18, 0xc5, 0x7d, 0x3e, 0xfe, 0x6f, 0x0b,
  0x54, 0xac, 0x5b, 0xd7, 0x2a, 0x73, 0xe0, 0x62, 0x63, 0x1a, 0x56, 0x75, 0x2e,
  0x8c, 0xcd, 0x8e, 0x75, 0x49, 0x53, 0x59, 0xec, 0x1a, 0x62, 0x0c, 0x21, 0x06,
  0xc9, 0xb6, 0x38, 0x35, 0xc3, 0x79, 0xc5, 0x12, 0xb2, 0x70, 0xb1, 0x60, 0x29,
  0x55, 0x71, 0x36, 0x45, 0xa0, 0x5b, 0xa0, 0x6c, 0x32, 0xca, 0x87, 0xcd, 0xca,
  0x66, 0xd9, 0x54, 0xaa, 0x28, 0x10, 0x17, 0x1b, 0x43, 0x88, 0x32, 0x07, 0x84,
  0x31, 0xc2, 0xb0, 0x21, 0x02, 0x8e, 0x49, 0x21, 0x40, 0xa1, 0x91, 0x6d, 0x59,
  0x80, 0xdb, 0xc5, 0xbb, 0x65, 0xe7, 0xea, 0xe4, 0x39, 0x39, 0x27, 0xcf, 0xc5,
  0x6f, 0x21, 0x26, 0x33, 0x4f, 0xcf, 0x8a, 0xa9, 0x59, 0x31, 0x19, 0x13, 0xb0,
  0x19, 0x05, 0xf6, 0x2d, 0x09, 0x1c, 0xbf, 0x26, 0xb0, 0xfb, 0xba, 0xe0, 0x0c,
  0xbe, 0xd8, 0x2e, 0x70, 0x45, 0xb3, 0xd7, 0x04, 0x5f, 0x89, 0xca, 0xac, 0x3d,
  0x31, 0xd9, 0xb9, 0x98, 0xac, 0x7b, 0x41, 0x16, 0x8d, 0x88, 0x85, 0x88, 0xe0,
  0x3f, 0x22, 0x02, 0xcb, 0x41, 0xef, 0x51, 0xd2, 0x57, 0x6e, 0xb0, 0x7f, 0x8a,
  0x17, 0xe8, 0xd6, 0x92, 0xe8, 0xa4, 0xab, 0x84, 0x57, 0x88, 0x84, 0x5c, 0x3f,
  0x1d, 0x95, 0xdd, 0xa8, 0x02, 0xf8, 0x58, 0x0e, 0xeb, 0x61, 0x1f, 0x6c, 0x07,
  0x35, 0x9c, 0x54, 0xb7, 0xbc, 0xb5, 0xbc, 0x87, 0x90, 0x8b, 0x0d, 0x7d, 0x37,
  0xc5, 0xba, 0x55, 0x4d, 0xce, 0x0b, 0x31, 0x07, 0x18, 0x87, 0x97, 0x00, 0x7c,
  0xf3, 0x2b, 0x81, 0x7f, 0x5e, 0xe0, 0xec, 0x9c, 0x28, 0x99, 0x5a, 0x7b, 0x65,
  0x4d, 0x0d, 0x8a, 0x55, 0xeb, 0x5b, 0x14, 0xe3, 0x01, 0x91, 0xbf, 0x25, 0x27,
  0x3f, 0xf9, 0xed, 0x63, 0xe9, 0x8a, 0x0a, 0x78, 0x45, 0x52, 0x1a, 0x5f, 0xe8,
  0x02, 0xc4, 0x14, 0x3c, 0xbe, 0x37, 0x78, 0x69, 0x65, 0xaf, 0x34, 0x20, 0x1c,
  0x01, 0xd1, 0x79, 0x53, 0x70, 0x79, 0xc6, 0x94, 0xa5, 0xdf, 0xe2, 0xc8, 0xfc,
  0xbb, 0xfd, 0x3b, 0x60, 0x62, 0x99, 0x04, 0xf0, 0x93, 0x39, 0xf9, 0x23, 0xb1,
  0xe7, 0x19, 0x37, 0x9e, 0x41, 0xe8, 0xc0, 0x0a, 0xd4, 0x60, 0xc7, 0x34, 0x7a,
  0x53, 0x07, 0x74, 0xcb, 0xd8, 0x9f, 0xde, 0x70, 0x1f, 0xc2, 0x25, 0x50, 0x91,
  0xda, 0x12, 0x3f, 0xda, 0x0c, 0x4b, 0xdf, 0xc2, 0x64, 0x72, 0x9b, 0x39, 0x82,
  0xe9, 0x72, 0x71, 0xc2, 0xf0, 0xc9, 0x86, 0xad, 0x09, 0x05, 0x63, 0xf0, 0xc6,
  0x5e, 0xe3, 0xfe, 0xec, 0x43, 0x5e, 0xe8, 0x80, 0xd7, 0xc2, 0x90, 0x56, 0x60,
  0xca, 0x3b, 0xe0, 0x44, 0x55, 0x5a, 0xba, 0x25, 0xd1, 0xe0, 0x01, 0x93, 0x31,
  0x67, 0xf4, 0x0b, 0xe9, 0x41, 0x95, 0xb4, 0xcd, 0xf8, 0x0d, 0x38, 0xb1, 0x51,
  0xb6, 0xc9, 0x09, 0xaf, 0x83, 0xeb, 0x8c, 0x34, 0xac, 0xf9, 0x45, 0xf3, 0xa0,
  0x54, 0xd2, 0x05, 0xc0, 0x05, 0x4a, 0x56, 0xd8, 0x40, 0x7f, 0x55, 0xdc, 0x87,
  0xe1, 0xa3, 0xfe, 0xa3, 0xba, 0x23, 0x2e, 0xd4, 0x15, 0x1e, 0x39, 0x18, 0x8b,
  0x70, 0xed, 0x0c, 0xe7, 0xb8, 0x01, 0x77, 0x7e, 0x2d, 0x6d, 0x3f, 0x76, 0x01,
  0xb2, 0x9e, 0xc0, 0xfe, 0xf8, 0x66, 0xd8, 0xe8, 0x86, 0x43, 0x46, 0xeb, 0xfa,
  0xbb, 0x30, 0x07, 0x8d, 0xf8, 0xa5, 0xd4, 0x07, 0x45, 0x87, 0x8b, 0x31, 0x8c,
  0xa9, 0xd6, 0x0f, 0x2c, 0x29, 0x7f, 0xed, 0x3c, 0xcf, 0x91, 0x1e, 0x6e, 0xef,
  0x61, 0x6b, 0xa2, 0x36, 0xa9, 0x50, 0x77, 0x39, 0xc4, 0xa5, 0xb7, 0xd9, 0x07,
  0x2d, 0x58, 0x8f, 0x36, 0x70, 0x80, 0x1b, 0x4f, 0xff, 0xc8, 0x3f, 0x77, 0xf1,
  0x40, 0x17, 0xcf, 0x77, 0x72, 0x25, 0x78, 0xa0, 0x70, 0x5f, 0xae, 0x3a, 0x04,
  0x1c, 0xa6, 0x5e, 0x30, 0x64, 0xef, 0xe8, 0x83, 0x6c, 0x07, 0xee, 0xca, 0xd2,
  0x67, 0x1e, 0x48, 0x50, 0x15, 0x65, 0xe6, 0xa7, 0x3a, 0xf0, 0x3c, 0xe5, 0x16,
  0xc3, 0x56, 0x36, 0x05, 0xc1, 0x1a, 0x82, 0xe7, 0xbe, 0x83, 0x97, 0xd0, 0x53,
  0xcf, 0x4d, 0x75, 0x5c, 0x34, 0x86, 0x49, 0xdd, 0x10, 0xae, 0xe1, 0xf6, 0x6a,
  0xfe, 0x0c, 0x36, 0x25, 0x25, 0xbd, 0x78, 0x7c, 0xdb, 0x61, 0x39, 0xc4, 0x7f,
  0x98, 0xa5, 0xbf, 0x05, 0x43, 0xd0, 0xc8, 0x69, 0x2c, 0xa9, 0x47, 0xcf, 0x71,
  0xdd, 0x59, 0xf6, 0x9f, 0x87, 0x70, 0x15, 0xe4, 0xea, 0xf5, 0x8f, 0xf0, 0x6e,
  0x09, 0x23, 0x9e, 0xb5, 0xb1, 0xd3, 0xc6, 0xcb, 0x27, 0xf9, 0x11, 0xeb, 0x27,
  0x62, 0xf4, 0x5b, 0x8c, 0xc6, 0xf0, 0x49, 0x94, 0x2e, 0xce, 0x90, 0xee, 0x32,
  0xec, 0x38, 0xb1, 0x00, 0x13, 0xf4, 0x3d, 0x2c, 0x8e, 0x53, 0xdb, 0x10, 0x75,
  0x81, 0xc1, 0x05, 0xef, 0x7a, 0x61, 0x00, 0x6e, 0xa0, 0xe2, 0xce, 0x04, 0x35,
  0x4c, 0xd0, 0xc3, 0x5e, 0xfa, 0xf5, 0x1e, 0x8d, 0xdc, 0x23, 0x6c, 0x0d, 0xd1,
  0x10, 0x05, 0xd9, 0x62, 0x87, 0xbc, 0x9d, 0x26, 0x47, 0x3b, 0xf5, 0x5f, 0xa7,
  0x20, 0x1c, 0x1c, 0x95, 0xe4, 0x19, 0x21, 0x18, 0x0c, 0x50, 0x93, 0x9f, 0x7c,
  0x7e, 0xc2, 0xa5, 0x46, 0x9a, 0x02, 0x57, 0x03, 0xd5, 0x79, 0x49, 0x3b, 0x86,
  0x52, 0x62, 0x32, 0x3e, 0x8b, 0x26, 0x55, 0xc2, 0xfb, 0x0a, 0x99, 0x56, 0xbd,
  0x61, 0x57, 0x5e, 0x31, 0xbc, 0x87, 0xc3, 0x90, 0xc2, 0x1b, 0x5b, 0x6a, 0xa9,
  0xbe, 0x96, 0xd4, 0x9b, 0xbd, 0x20, 0x7b, 0x67, 0xd0, 0x43, 0x15, 0x1e, 0x7a,
  0x33, 0xe3, 0xd5, 0x21, 0xd8, 0x5d, 0x0d, 0xe6, 0x97, 0xd3, 0x0a, 0x74, 0xa2,
  0x52, 0xaa, 0x2c, 0xa7, 0x6a, 0xf8, 0xdc, 0x49, 0xda, 0xd3, 0xa8, 0x54, 0xaa,
  0x98, 0xe5, 0x76, 0xde, 0x52, 0x76, 0x8a, 0xf0, 0x94, 0x9d, 0xca, 0xec, 0x54,
  0x63, 0xa3, 0x11, 0x74, 0xa3, 0x08, 0xa0, 0x64, 0x30, 0xab, 0xca, 0x60, 0x44,
  0x8a, 0xb3, 0xcf, 0x60, 0xd3, 0x63, 0x7c, 0x8c, 0x83, 0x76, 0x5a, 0x57, 0xb3,
  0xb8, 0xc6, 0x72, 0x6f, 0x54, 0x70, 0x1b, 0xc5, 0xd5, 0xcf, 0xad, 0x9d, 0x76,
  0xaf, 0xba, 0xc8, 0x3f, 0x61, 0x5d, 0xab, 0xf8, 0xc1, 0xac, 0x6e, 0x66, 0xdf,
  0x53, 0xa3, 0xf8, 0x30, 0x28, 0xb5, 0x06, 0xa5, 0x7f, 0xc9, 0x23, 0xfe, 0x4f,
  0x61, 0xbc, 0xa3, 0xb9, 0xad, 0x79, 0x5a, 0x1e, 0xb5, 0xff, 0x41, 0x14, 0xff,
  0x04,
};

optimizesize void *__cp932ext_decmap(void) {
  if (__cp932ext_decmap_once) return __cp932ext_decmap_ptr;
  return xloadzd(&__cp932ext_decmap_once,
                 &__cp932ext_decmap_ptr,
                 __cp932ext_decmap_rodata,
                 872, 1534, 969, 2, 0xde26b180u); /* 44.9948% profit */
}
