#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);

  char *ans = (char *)malloc((len_num) * sizeof(char));
  int ans_p = 0;
  for (int i = 0; i < len_num; ++i) {
    while (ans_p > 0 && num[i] < ans[ans_p - 1] && k--) { --ans_p; }
    ans[ans_p++] = num[i];
  }

  while (k > 0) {
    --ans_p;
    --k;
  }

  ans[ans_p] = '\0';
  while (*ans == '0' && *(ans + 1)) { ++ans; }

  return *ans ? ans : "0";
}

// 4 / 33 test cases passed.
// Status: Runtime Error
// Submitted: 4 minutes ago
// Runtime Error Message:
// AddressSanitizer: heap-buffer-overflow on address 0x6020000001b1 at pc
// 0x000000401c48 bp 0x7ffd7dbcaa30 sp 0x7ffd7dbcaa20 Last executed input: "0"
// 0
