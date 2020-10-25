#include <stdbool.h>
#include <stdlib.h>
bool winnerSquareGame(int n) {
  bool* memo = (bool*)calloc(n + 1, sizeof(bool));
  for (int i = 1; i * i <= n; ++i) {
    memo[i] = true;
  }
  if (memo[n]) {
    return true;
  }
  for (int i = 2; i <= n; ++i) {
    bool has_win = true;
    for (int k = 1; i - k * k >= 1; ++k) {
      has_win = has_win && memo[i - k * k];
    }
    memo[i] = !has_win;
  }
  return memo[n];
}
// 47 / 72 test cases passed.
// Status: Wrong Answer
// Submitted: 5 minutes ago
// Input:
// 15
// Output:
// true
// Expected:
// false
