#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);
  if (len_num == k) { return "0"; }
  char *ans = (char *)malloc((len_num - k + 3) * sizeof(char));
  int ans_p = 0;
  for (int i = 0; i <= len_num; ++i) {
    while (ans_p > 0 && num[i] < ans[ans_p - 1] && k-- > 0) { --ans_p; }
    ans[ans_p++] = num[i];
  }
  ans[ans_p] = '\0';
  while (*ans == '0' && *(ans + 1)) { ++ans; }

  return ans;
}

// Submission Detail
// 21 / 33 test cases passed.
// Status: Runtime Error
// Submitted: 2 days, 4 hours ago
// Runtime Error Message:
// AddressSanitizer: heap-buffer-overflow on address 0x602000000794 at pc
// 0x000000401a69 bp 0x7ffc333203f0 sp 0x7ffc333203e0 Last executed input:
// "1234567890"
// 9
