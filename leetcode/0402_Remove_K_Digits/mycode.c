#include <stdlib.h>
#include <string.h>
char *removeKdigits(char *num, int k) {
  int len_num = strlen(num);

  char *ans = (char *)malloc((len_num + 1) * sizeof(char));
  int ans_p = 0;
  for (int i = 0; i < len_num; ++i) {
    while (ans_p > 0 && num[i] < ans[ans_p - 1] && k-- > 0) { --ans_p; }
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

// https://leetcode.com/submissions/detail/347056291/
// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove K
// Digits. Memory Usage: 5.7 MB, less than 100.00% of C online submissions for
// Remove K Digits.
