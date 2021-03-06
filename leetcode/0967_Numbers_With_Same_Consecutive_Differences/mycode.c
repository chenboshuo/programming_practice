
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numsSameConsecDiff(int N, int K, int *returnSize) {
  int* result = calloc(10240,sizeof(int)); // the result
  *returnSize = 0;
  if (N == 1){
    *returnSize = 10;
    for (int i = 0; i < 11; ++i){
      result[i] = i;
    }
    return result;
  }
  if(K == 0){
    *returnSize = 9;
    for (int i = 0; i < 11; ++i){
      result[i] = 0;
      int t = N;
      while(t--){
        result[i] *= 10;
        result[i] += i;
      }
    }
    return result+1;
  }

  for(int hightest_digit=1; 
      hightest_digit<10;
      ++hightest_digit){
    
    int num_cases = (1 << (N-1));

    /* 
     * (i)_10 = (b1 b2...bn)_2
     * where n is the length of the integers
     * i is the variable `cases` to record different cases
     * 
     * bi=1 means increase
     * bi=0 means decrease 
    */
    for(int cases=0;cases < num_cases;++cases){
      int pre = hightest_digit;
      int ans = hightest_digit;
      int mask = (1 << (N-2));// create bit mask,
      while(mask){
        ans *= 10;
        int next;
        if(mask & cases){
          next = pre + K; 
        }else{
          next = pre - K;
        }
        if (next < 0 || next >= 10){
          ans = -1;
          break;
        }
        ans += next;
        mask >>= 1;
        pre = next;
      }
      if (ans != -1){
        result[(*returnSize)++] = ans;
      }
    }
  }
  return result;
}
// 92 / 92 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 11 MB
// Submitted: 0 minutes ago
