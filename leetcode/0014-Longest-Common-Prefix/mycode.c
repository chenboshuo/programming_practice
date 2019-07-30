char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize <= 0) {
    return "";
  }
  char *prefix = strs[0]; // 指针放在第一个字符串的首位
  for (; *strs[0]; ++strs[0]) {
    for (int i = 1; i < strsSize; ++i) {
      if (*(strs[i]++) != *strs[0]) { // *str[i] 排除都是'\0'
        *strs[0] = '\0';
        return prefix;
      }
    }
  }
  return prefix;
}

// https://leetcode.com/submissions/detail/247483108/
// Runtime: 8 ms, faster than 14.20% of C online submissions for Longest Common
// Prefix. Memory Usage: 7 MB, less than 80.73% of C online submissions for
// Longest Common Prefix.
