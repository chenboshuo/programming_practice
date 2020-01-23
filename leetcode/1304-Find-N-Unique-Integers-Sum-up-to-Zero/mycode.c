#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
  int *nums = (int*)calloc(n,sizeof(int));
  int num = 1;
  for(int i=0; i<n/2; ++i,++num){
    nums[i] = num;
    nums[n-1-i] = -num;
  }

  *returnSize = n;
  return nums;
}
// 4 ms 94.96%
// 7.6 MB
// https://leetcode.com/contest/weekly-contest-169/submissions/detail/289360298/
