#include <string.h>

char *removeKdigits(char *num, int k) {
  int num_size = strlen(num);
  if (k == num_size) { return "0"; }
  int fast;
  while (k) {
    int slow = 0;
    for (fast = 1; fast < num_size; ++fast) {
      if (num[fast] < num[slow] && k) {
        num[slow] = num[fast];
        --k;
      } else {
        num[++slow] = num[fast];
      }
    }
    num[slow + 1] = '\0';
    --num_size;
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
