#include <string.h>
int strStr(char *haystack, char *needle) {
  if (!*needle) { // 处理两个空字符串的特殊情况
    return 0;
  }
  int n_len = strlen(needle);
  int h_len = strlen(haystack);
  if (n_len > h_len) {
    return -1;
  }
  for (int i = 0; i < h_len; ++i) {
    int j;
    for (j = 0; haystack[i + j] == needle[j] && i + j < h_len; ++j) {
      ;
    }
    if (!needle[j]) { // needle[j] == '\0' 代表遍历完成
      return i;
    }
  }
  return -1;
}

// https://leetcode.com/submissions/detail/249660167/
// Runtime: 1304 ms, faster than 13.52% of C online submissions for Implement
// strStr(). Memory Usage: 7.2 MB, less than 61.90% of C online submissions for
// Implement strStr().
