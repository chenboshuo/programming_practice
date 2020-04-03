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
  for (int i = 0; i < 10000; ++i) {
    happy[i] = -1;
  }
  return _isHappy(n);
}

// https://leetcode.com/submissions/detail/318571714/
// 350 / 401 test cases passed.
// Status: Runtime Error
// Submitted: 17 hours, 12 minutes ago
// Runtime Error Message:
// Line 10: Char 12: runtime error: index 1111111 out of bounds for type 'int
// [10000]' (solution.c) Last executed input: 1111111