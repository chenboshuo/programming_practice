#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#define MEMORY_SIZE 10000
int happy[MEMORY_SIZE];

bool _isHappy(int n) {
  if (n == 1) {
    return true;
  }
  if (n < MEMORY_SIZE && happy[n] != -1) {
    return happy[n];
  }

  int sum_squares = 0;
  int digits = n;
  while (digits) {
    sum_squares += pow(digits % 10, 2);
    digits /= 10;
  }

  if (n < MEMORY_SIZE) {
    happy[n] = 0;
    happy[n] = _isHappy(sum_squares);
    return happy[n];
  } else {
    return _isHappy(sum_squares);
  }
}

bool isHappy(int n) {
  for (int i = 0; i < MEMORY_SIZE; ++i) {
    happy[i] = -1;
  }
  return _isHappy(n);
}

// https://leetcode.com/submissions/detail/318573140/

// 401 / 401 test cases passed.
// Status: Accepted
// Runtime: 8 ms
// Memory Usage: 5.2 MB
// Submitted: 17 hours, 13 minutes ago
