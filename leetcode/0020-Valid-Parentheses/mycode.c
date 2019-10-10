#include <stdbool.h>  // 定义bool变量
#include <string.h>

bool isValid(char* s) {
  char brackets[strlen(s) + 2];
  int pb = 0;
  for (int i = 0; s[i]; i++) {
    switch (s[i]) {
      case '(':
      case '[':
      case '{':
        brackets[pb++] = s[i];
        break;
      case ')':
        if (pb > 0 && brackets[pb - 1] == '(') {
          --pb;
        } else {
          return false;
        }
        break;
      case ']':
        if (pb > 0 && brackets[pb - 1] == '[') {
          --pb;
        } else {
          return false;
        }
        break;
      case '}':
        if (pb > 0 && brackets[pb - 1] == '{') {
          --pb;
        } else {
          return false;
        }
        break;
    }
  }
  if (pb != 0) {
    return false;
  }
  return true;
}
// Runtime: 0 ms, faster than 100.00% of C online submissions for Valid
// Parentheses.

// Memory Usage: 6.7 MB, less than 100.00% of C online submissions for Valid
// Parentheses.
