#include <stdbool.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *distributeCandies(int candies, int num_people, int *returnSize) {
  int *ans = (int *)calloc(sizeof(int), num_people);
  *returnSize = num_people;
  int cur = 1;
  bool reverse = false;
  while (candies) {
    if (reverse) {
      for (int i = num_people; i > -1; --i) {
        int give = min(candies, cur);
        ans[i] += give;
        candies -= give;
        ++cur;
      }
    } else {
      for (int i = 0; i < num_people; ++i) {
        int give = min(candies, cur);
        ans[i] += give;
        candies -= give;
        ++cur;
      }
    }
    reverse = !reverse;
  }
  return ans;
}
// Runtime Error Message:
// =================================================================
// ==31==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60200000011c
// at pc 0x0000004018c7 bp 0x7ffc7d5ecfe0 sp 0x7ffc7d5ecfd0 READ of size 4 at
// 0x60200000011c thread T0
//     #2 0x7f6612a6182f in __libc_start_main
//     (/lib/x86_64-linux-gnu/libc.so.6+0x2082f)
// 0x60200000011c is located 0 bytes to the right of 12-byte region
// [0x602000000110,0x60200000011c) allocated by thread T0 here:
//     #0 0x7f6613a7d17e in calloc
//     (/usr/lib/x86_64-linux-gnu/libasan.so.5+0x10c17e) #3 0x7f6612a6182f in
//     __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2082f)
// Shadow bytes around the buggy address:
//   0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0c047fff8000: fa fa 00 00 fa fa fd fa fa fa fd fa fa fa fd fa
//   0x0c047fff8010: fa fa fd fa fa fa fd fa fa fa fd fa fa fa 00 00
// =>0x0c047fff8020: fa fa 00[04]fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8070: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
// Shadow byte legend (one shadow byte represents 8 application bytes):
//   Addressable:           00
//   Partially addressable: 01 02 03 04 05 06 07
//   Heap left redzone:       fa
//   Freed heap region:       fd
//   Stack left redzone:      f1
//   Stack mid redzone:       f2
//   Stack right redzone:     f3
//   Stack after return:      f5
//   Stack use after scope:   f8
//   Global redzone:          f9
//   Global init order:       f6
//   Poisoned by user:        f7
//   Container overflow:      fc
//   Array cookie:            ac
//   Intra object redzone:    bb
//   ASan internal:           fe
//   Left alloca redzone:     ca
//   Right alloca redzone:    cb
//   Shadow gap:              cc
// ==31==ABORTING
// Last executed input:
// 10
// 3
