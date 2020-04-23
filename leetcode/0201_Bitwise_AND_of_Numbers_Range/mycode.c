// reference
// https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/56753/Accepted-C-solution-with-simple-explanation
int rangeBitwiseAnd(int m, int n) {
  int exponent = 0;
  while (m != n) {
    m >>= 1;
    n >>= 1;
    ++exponent;
  }
  return m << exponent;
}

// Runtime: 4 ms, faster than 90.98% of C online submissions for Bitwise AND of
// Numbers Range. Memory Usage: 5.5 MB, less than 100.00% of C online
// submissions for Bitwise AND of Numbers Range.
// https://leetcode.com/submissions/detail/328933174/
