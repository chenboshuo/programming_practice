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

// Wrong Answer
// Details
// Input
// 12
// Output
// -1753703748
// Expected
// 505379714
