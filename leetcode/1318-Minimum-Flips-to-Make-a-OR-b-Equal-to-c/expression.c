int minFlips(int a, int b, int c) {
  int ai, bi, ci, count = 0, _;
  while (a || b || c) {
    ai = a & 1;
    bi = b & 1;
    ci = c & 1;
    if ((_ = ai + bi - ci) < 0) {
      _ *= -1;
    }
    count += ((ai | bi) ^ ci) * (_);
    c >>= 1;
    b >>= 1;
    a >>= 1;
  }
  return count;
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Minimum Flips
// to Make a OR b Equal to c. Memory Usage: 6.5 MB, less than 100.00% of C
// online submissions for Minimum Flips to Make a OR b Equal to c.
// https://leetcode.com/submissions/detail/298407923/
