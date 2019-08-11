int strStr(char *haystack, char *needle) {
  if (!*needle) { // 处理两个空字符串的特殊情况
    return 0;
  }
  for (int i = 0, j = 0; haystack[i]; ++i) {
    if (haystack[i] != needle[j]) {
      j = -1;
    }
    ++j;
    if (!needle[j]) { // needle[j] == '\0' 代表遍历完成
      return i - j + 1;
    }
  }
  return -1;
}

// https://leetcode.com/submissions/detail/250713943/
// "mississippi"
// "issip"
// Output:
// -1
// Expected:
// 4
