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
  int *groups = (int*)malloc(sizeof(int)* n_group);
  int begin = 0;
  int active = 1;

  while(begin<n_group){
    for(int i=0; i<active;++i){
      
    }
  }
  free(groups);
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
