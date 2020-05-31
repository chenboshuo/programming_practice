#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);

  char *ans = (char *)malloc((len_num + 1) * sizeof(char));
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

// Submission Detail
// 26 / 33 test cases passed.
// Status: Wrong Answer
// Submitted: 3 minutes ago
// Input:
// "43214321"
// 4
// Output:
// "11"
// Expected:
// "1321"
