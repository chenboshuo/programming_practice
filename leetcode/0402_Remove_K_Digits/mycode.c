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
  return ans;
}

// 1 / 33 test cases passed.
// Status: Wrong Answer
// Submitted: 2 days, 5 hours ago
// Input:
// "10200"
// 1
// Output:
// "0200"
// Expected:
// "200"
