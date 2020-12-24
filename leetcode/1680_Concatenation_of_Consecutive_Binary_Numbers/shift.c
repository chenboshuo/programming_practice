#define MOD 1000000007

int concatenatedBinary(int n) {
  long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int len = 0;
    for (int j = 1; j <=i; j <<= 1) { ++len; }
    // ans += (((ans << len) % MOD) + i) % MOD;
    // printf("%i %d %d\n",i,len,ans);
    ans = ((ans << len) + i);
  }
  return ans;
}

// Runtime: 68 ms, faster than 50.00% of C online submissions for Concatenation
// of Consecutive Binary Numbers. Memory Usage: 5.5 MB, less than 83.33% of C
// online submissions for Concatenation of Consecutive Binary Numbers.
