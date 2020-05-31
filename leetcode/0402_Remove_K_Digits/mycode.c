#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);
  if (len_num == k) { return "0"; }
  char *ans = (char *)malloc((len_num - k + 2) * sizeof(char));
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
// 7 / 33 test cases passed.
// Status: Wrong Answer
// Submitted: 2 days, 5 hours ago
// Input:
// "112"
// 1
// Output:
// "112"
// Expected:
// "11"
