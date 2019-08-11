int strStr(char *haystack, char *needle) {
  if (!*needle) { // 处理两个空字符串的特殊情况
    return 0;
  }
  for (int i = 0, j = 0; haystack[i]; ++i) {
    if (haystack[i] != needle[j]) {
      i = i - j;
      j = -1;
    }
    ++j;
    if (!needle[j]) { // needle[j] == '\0' 代表遍历完成
      return i - j + 1;
    }
  }
  return -1;
}

// https://leetcode.com/submissions/detail/250714622/
// Runtime: 4 ms, faster than 79.47% of C online submissions for Implement
// strStr(). Memory Usage: 7.3 MB, less than 31.25% of C online submissions for
// Implement strStr().
