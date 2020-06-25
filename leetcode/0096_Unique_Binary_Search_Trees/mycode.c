int numTrees(int n) {
  int ans[n + 1];
  ans[0] = 1;
  for (int i = 1; i < n + 1; ++i) {
    ans[i] = 0;
    for (int j = 0; j < i; ++j) { ans[i] += (ans[j] * ans[i - 1 - j]); }
  }
  return ans[n];
}
// 19 / 19 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 5.2 MB
