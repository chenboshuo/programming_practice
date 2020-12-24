#define MOD 1000000007

int concatenatedBinary(int n) {
  long ans = 0;
  int shift = 0;
  for (int i = 1; i <= n; ++i) {
    if ((i & (i - 1)) == 0) { ++shift; }
    ans = ((ans << shift) | i) % MOD;
    // printf("%i %d %d\n",i,len,ans);
    // ans = ((ans << len) + i);
  }
  return ans;
}

// Runtime: 20 ms, faster than 94.44% of C online submissions for Concatenation
// of Consecutive Binary Numbers. Memory Usage: 5.5 MB, less than 83.33% of C
// online submissions for Concatenation of Consecutive Binary Numbers.
