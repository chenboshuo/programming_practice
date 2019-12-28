#include <stdbool.h>
#include <stdlib.h>

int comp(const void* a, const void*b){
  return *(int*)a - *(int*)b;
}

bool isPossibleDivide(int* nums, int numsSize, int k){
  if(numsSize % k != 0){
    return false;
  }
  qsort(nums, numsSize, sizeof(int), comp);
  int n_group = numsSize/k;
  int n_zero = 0;
  int delta;

  for(int i = 1; i < numsSize && (i % n_group != 0); ++i){
    delta = nums[i] - nums[i-1];
    if(delta > 1){ // 前后两数差大于1
      return false;
    }
    if(delta == 0){
      ++n_zero;
      if(n_zero + 1 > k){
        return false;
      }
    }else{
      n_zero = 0;
    }
  }

  return true;
}

// https://leetcode.com/submissions/detail/289094225/
// Wrong Answer
// Input
// [12,12,2,11,22,20,11,13,3,21,1,13]
// 3
// Output
// false
// Expected
// true
