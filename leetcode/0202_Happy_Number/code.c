#include <math.h>

bool isHappy(int n) {
  if (n == 1) {
    return true;
  }
  if (n / 10 == 0) {
    return false;
  }

  int sum_squares = 0;
  while (n) {
    sum_squares += pow(n % 10, 2);
    n /= 10;
  }
  return isHappy(sum_squares);
}

// https://leetcode.com/submissions/detail/318555120/
// 399 / 401 test cases passed.
// Status: Wrong Answer
// Submitted: 18 hours, 4 minutes ago
// Input:
// 7
// Output:
// false
// Expected:
// true