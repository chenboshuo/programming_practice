#include <string.h>

char *removeKdigits(char *num, int k) {
  // int num_size = strlen(num);
  int fast;
  while (k) {
    int slow = 0;
    for (fast = 1; num[fast]; ++fast) {
      if (num[fast] < num[slow] && k) {
        num[slow] = num[fast];
        --k;
      } else {
        num[++slow] = num[fast];
      }
    }
    num[slow + 1] = '\0';
  }

  if (*num == '\0') { return "0"; }
  while (*num == '0' && *(num + 1)) { ++num; }
  return num;
}

// 2 / 33 test cases passed.
// Status: Time Limit Exceeded
// Submitted: 5 days, 5 hours ago
// Last executed input:
// "10"
// 2
