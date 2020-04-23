long int rangeBitwiseAnd(long int m, long int n) {
  long int result = m;
  for (long int i = m + 1; i <= n; ++i) {
    result &= i;
    if (result == 0) {
      return 0;
    }
  }
  return result;
}

// 8266 / 8266 test cases passed.
// Status: Accepted
// Runtime: 444 ms
// Memory Usage: 5.3 MB
// Submitted: 52 minutes ago
