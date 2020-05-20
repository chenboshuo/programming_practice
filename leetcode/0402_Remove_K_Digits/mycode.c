#include <string.h>

char *removeKdigits(char *num, int k) {
  int num_size = strlen(num);
  if (k == num_size) { return "0"; }
  while (k) {
    int i;
    for (i = 0; num[i] && num[i] <= num[i + 1]; ++i) { ; }
    if (num[i]) {
      --k;
      for (; num[i]; ++i) { num[i] = num[i + 1]; }
    }
  }

  while (*num == '0' && *(num + 1)) { ++num; }
  return num;
}

// 7 / 33 test cases passed.
// Status: Time Limit Exceeded
// Submitted: 5 days, 5 hours ago
// Last executed input:
// "112"
// 1
