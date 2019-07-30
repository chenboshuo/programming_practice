char *longestCommonPrefix(char **strs, int strsSize) {
  if (strsSize <= 0) {
    return "";
  }
  for (int j = 0; strs[0][j]; ++j) {
    for (int i = 1; i < strsSize; ++i) {
      if (strs[i][j] != strs[0][j]) { // *str[i] 排除都是'\0'
        strs[0][j] = '\0';
        return strs[0];
      }
    }
  }
  return strs[0];
}

// https://leetcode.com/submissions/detail/247484304/
// Runtime: 4 ms, faster than 72.16% of C online submissions for Longest Common
// Prefix. Memory Usage: 7.1 MB, less than 47.71% of C online submissions for
// Longest Common Prefix.
