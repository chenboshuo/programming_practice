int rangeBitwiseAnd(int m, int n){
  int result = m;
  for(int i=m+1;i<=n;++i){
    result &= i;
    if(result == 0){
      return 0;
    }
  }
  return result;
}

// 8264 / 8266 test cases passed.
// Status: Runtime Error
// Submitted: 46 minutes ago
// Runtime Error Message:
// Line 5: Char 22: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int' (solution.c)
// Last executed input:
// 2147483646
// 2147483647