/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start

int lengthOfLastWord(char *s) {
  int len = 0;  // 记录字符串长度
  while (*s) {
    if (*s == ' ') {
      if (!*(s + 1)) {
        return len;
      } else {
        len = -1;
      }
    }
    len++;
    s++;
  }
  return len;
}

// https://leetcode.com/submissions/detail/265307721/
// Wrong Answer
// Details
// Input
// "b   a    "
// Output
// 0
// Expected
// 1
// @lc code=end
