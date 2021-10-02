#include "libc/x/x.h"
/* clang-format off */

static bool __jisx0213_1_emp_decmap_once;
static void *__jisx0213_1_emp_decmap_ptr;
static const unsigned char __jisx0213_1_emp_decmap_rodata[] = {
  0xe3, 0x66, 0xb0, 0x15, 0xfa, 0xf7, 0x1f, 0x1d, 0x4a, 0x0b, 0x63, 0x8a, 0x61,
  0x83, 0x79, 0x22, 0xc4, 0xa9, 0x43, 0x85, 0x7b, 0x25, 0xe6, 0x73, 0xe3, 0x93,
  0xdf, 0x22, 0x86, 0x4d, 0xd4, 0x44, 0xee, 0x88, 0x21, 0x39, 0xb6, 0x91, 0x0f,
  0x8f, 0x98, 0xda, 0x9b, 0xa3, 0x8b, 0x25, 0x9b, 0xd3, 0xd0, 0x46, 0x9b, 0x8f,
  0xee, 0x7d, 0x21, 0x7c, 0xa1, 0xe4, 0x9b, 0x50, 0x18, 0x8e, 0xd3, 0x2f, 0x91,
  0xa4, 0x9b, 0xb6, 0x30, 0xf6, 0x7f, 0x96, 0x43, 0x1e, 0xf1, 0xea, 0xbf, 0x14,
  0x50, 0x23, 0x14, 0x5a, 0xca, 0xca, 0x9b, 0x50, 0x45, 0xce, 0x36, 0x4f, 0x58,
  0x08, 0x00,
};

optimizesize void *__jisx0213_1_emp_decmap(void) {
  if (__jisx0213_1_emp_decmap_once) return __jisx0213_1_emp_decmap_ptr;
  return xload(&__jisx0213_1_emp_decmap_once,
               &__jisx0213_1_emp_decmap_ptr,
               __jisx0213_1_emp_decmap_rodata,
               93, 680); /* 13.6765% profit */
}
