int strStr(char *haystack, char *needle) {
  if (!*needle) { // 处理两个空字符串的特殊情况
    return 0;
  }
  int j;
  for (int i = 0; haystack[i]; ++i) {
    for (j = 0; haystack[i + j] == needle[j]; ++j) {
      ;
    }
    if (!needle[j]) { // needle[j] == '\0' 代表遍历完成
      return i;
    }
  }
  return -1;
}

// https://leetcode.com/submissions/detail/248043197/
//
// Runtime Error

// Input
// "a"
// "a"
