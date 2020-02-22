#include <stdbool.h>
bool checkIfExist(int* arr, int arrSize) {
  bool exist[4000] = {false};
  for (int i = 0; i < arrSize; ++i) {
    if (exist[2000 + arr[i] * 2] ||
        (!(arr[i] & 1) && exist[2000 + arr[i] / 2])) {
      return true;
    }
    exist[2000 + arr[i]] = true;
  }
  return false;
}

// 24 / 104 test cases passed.
// Status: Runtime Error
// Submitted: 19 minutes ago
// Runtime Error Message:
// Line 4: Char 13: runtime error: index 4000 out of bounds for type '_Bool
// [4000]' (solution.c) Last executed input:
// [-778,-481,842,495,44,1000,-572,977,240,-116,673,997,-958,-539,-964,-187,-701,-928,472,965,-672,-88,443,36,388,-127,115,704,-549,1000,998,291,633,423,57,-77,-543,72,328,-938,-192,382,179]