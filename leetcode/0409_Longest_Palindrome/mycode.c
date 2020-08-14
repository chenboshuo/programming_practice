#include <stdbool.h>
int longestPalindrome(char *s) {
  int map[256] = { 0 };
  bool has_odd = false;
  while (*s) {
    ++map[*s];
    ++s;
  }

  int ans = 0;
  for (int i = 'A'; i <= 'z'; ++i) {
    ans += map[i] / 2;
    has_odd |= (map[i] & 1);
  }
  return ans * 2 + has_odd;
}

// https://leetcode.com/submissions/detail/380685617/?from=/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3423/

// 95 / 95 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 5.3 MB
// Submitted: 0 minutes ago
