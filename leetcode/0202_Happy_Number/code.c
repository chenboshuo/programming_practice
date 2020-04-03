#include <math.h>
#include <stdbool.h>
#include <stdio.h>
int happy[10000];

bool _isHappy(int n) {
  if (n == 1) {
    return true;
  }
  if (happy[n] != -1) {
    return happy[n];
  }

  happy[n] = 0;
  int sum_squares = 0;
  int digits = n;
  while (digits) {
    sum_squares += pow(digits % 10, 2);
    digits /= 10;
  }
  happy[n] = _isHappy(sum_squares);
  return happy[n];
}

bool isHappy(int n) {
  for (int i = 0; i < 1000; ++i) {
    happy[i] = -1;
  }
  return _isHappy(n);
}

// https://leetcode.com/submissions/detail/318571153/
// 343 / 401 test cases passed.
// Status: Wrong Answer
// Submitted: 17 hours, 12 minutes ago
// Input:
// 1221
// Output:
// false
// Expected:
// true