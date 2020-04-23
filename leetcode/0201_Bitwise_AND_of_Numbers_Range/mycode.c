int rangeBitwiseAnd(int m, int n) {
  int result = m;
  for (size_t i = m + 1; i <= n; ++i) {
    result &= i;
    if (result == 0) {
      return 0;
    }
  }
  return result;
}


// 8265 / 8266 test cases passed.
// Status: Runtime Error
// Submitted: 51 minutes ago
// Runtime Error Message:
// Line 5: Char 17: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.c)
// Last executed input:
// 2147483647
// 2147483647