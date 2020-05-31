#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);
  char *ans = (char *)malloc((len_num - k + 1) * sizeof(char));
  int ans_p = 0;
  while (*num) {
    while (ans_p > 0 && *num < ans[ans_p - 1] && k--) { --ans_p; }
    ans[ans_p++] = *num;
    ++num;
  }
  ans[ans_p] = '\0';
  while (*ans == '0' && *(ans + 1)) { ++ans; }

  return ans;
}

// Submission Detail
// 2 / 33 test cases passed.
// Status: Runtime Error
// Submitted: 2 days, 5 hours ago
// Runtime Error Message:
// AddressSanitizer: heap-buffer-overflow on address 0x6020000000f1 at pc
// 0x000000401bbe bp 0x7ffec8e46570 sp 0x7ffec8e46560 Last executed input: "10"
// 2
