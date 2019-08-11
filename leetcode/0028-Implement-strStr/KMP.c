#include <stdlib.h>
#include <string.h>
int strStr(char *haystack, char *needle) {
  // 处理两个空字符串的特殊情况
  if (!*needle) {
    return 0;
  }

  int n_len = strlen(needle);
  int h_len = strlen(haystack);

  // needle大于haystack,不比较
  if (n_len > h_len) {
    return -1;
  }
  char *next = (char *)malloc(sizeof(char) * n_len);
  next[0] = -1;
  int _ = 0;

  // 生成next数组
  for (int i = 1; i < n_len; ++i) {
    next[i] = _;
    while (_ > 0 && needle[i] != needle[_]) {
      --_;
    }
    if (needle[_] == needle[i]) {
      _++;
    }
  }

  // 根据next将对应索引移动到不匹配的位置
  for (int i = 0, j = 0; i < h_len; ++i) {
    while (j != -1 && haystack[i] != needle[j]) {
      j = next[j];
    }
    ++j;
    if (j == n_len) { // 通过长度对比(有可能出现j=-1的情况)
      return i - j + 1;
    }
  }
  return -1;
}

// https://leetcode.com/submissions/detail/250709242/
// Runtime: 4 ms, faster than 79.47% of C online submissions for Implement
// strStr(). Memory Usage: 7.3 MB, less than 18.75% of C online submissions for
// Implement strStr().
