/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start

int lengthOfLastWord(char *s) {
  int len = 0;
  while (*s && *s != ' ') {
    ++len;
    ++s;
  }
  while (*s == ' ') { ++s; }
  if (*s == '\0') {
    return len;
  } else {
    return lengthOfLastWord(s);
  }
}

// https://leetcode.com/submissions/detail/265318438/
// Runtime: 4 ms, faster than 57.85% of C online submissions for Length of Last
// Word. Memory Usage: 6.8 MB, less than 100.00% of C online submissions for
// Length of Last Word.
// @lc code=end
