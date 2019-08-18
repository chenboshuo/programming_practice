#include <stdlib.h>
#include <string.h>
char *cur;
char *countAndSay(int n) {
  if (n == 1) {
    return "1";
  }

  char *pre = countAndSay(n - 1);
  cur = (char *)malloc(sizeof(char) * (strlen(pre) * 2 + 1));
  int i = 0; // cur的索引值
  char count, value;
  for (count = '0', value = *pre; *pre; ++pre) {
    if (*pre == value) {
      ++count;
    } else {
      cur[i++] = count;
      cur[i++] = value;
      value = *pre;
      count = '1';
    }
  }
  cur[i++] = count;
  cur[i++] = value;
  cur[i] = '\0';
  return cur;
}

// https://leetcode.com/submissions/detail/252650285/
// Runtime:
// 0 ms, faster than 100.00% of C online submissions for Count and Say.
// Memory Usage:
// 7.4 MB, less than 100.00% of C online submissions for Count and Say.
