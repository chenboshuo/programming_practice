#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool repeatedSubstringPattern(char *s) {
  int len = strlen(s);
  bool memo[len][len];
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      memo[i][j] = (s[i] == s[j]);
      if (i != j && i > 0 && j > 0 && memo[i][j] && memo[i - 1][j - 1]) {
        return true;
      }
    }
  }
  return false;
}

// Input:
// "bb"
// Output:
// false
// Expected:
// true
