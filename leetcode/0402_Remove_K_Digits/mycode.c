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

// Runtime: 212 ms, faster than 7.91%
// of C online submissions for Remove K Digits.
// Memory Usage: 5.6 MB,
// less than 100.00% of C online submissions for Remove K Digits.
