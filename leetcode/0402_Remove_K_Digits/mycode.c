#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);
  char *ans = (char *)malloc((len_num - k + 3) * sizeof(char));
  ans[0] = '0';
  int ans_p = 1;
  while (*num) {
    while (ans_p > 0 && *num < ans[ans_p - 1] && k--) { --ans_p; }
    ans[ans_p++] = *num;
    ++num;
  }
  ans[ans_p] = '\0';
  while (*ans == '0' && *(ans + 1)) { ++ans; }

  return ans;
}

// 6 / 33 test cases passed.
// Status: Wrong Answer
// Submitted: 2 days, 5 hours ago
// Input:
// "9"
// 1
// Output:
// "9"
// Expected:
// "0"
