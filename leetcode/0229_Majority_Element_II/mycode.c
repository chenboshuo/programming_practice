#include <stdlib.h> 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
  if(numsSize==0){
    *returnSize = 0;
    return NULL;
  }
  int* majority = (int*)malloc(sizeof(int)*2);

  // find the most frequently element
  int times = 0;
  for (int i = 0; i < numsSize; i++){
    if(times == 0){
      majority[0] = nums[i];
      times = 2;
    }else{
      if(nums[i] == majority[0]){
        times += 2;
      }else{
        times -= 1;
      }
    }
  }

  // the element doesn't more than floor(n/3)
  if(times == 0){
    *returnSize = 0;
    return majority;
  }

  times = 0;
  int majority_times = 0;
  for (int i = 0; i < numsSize; i++){
    if(nums[i] != majority[0]){
      if(times == 0){
        majority[1] = nums[i];
        times = 1;
      }else{
        if(nums[i] == majority[1]){
          times += 1;
        }else{
          times -= 1;
        }
      }
    }else{
      ++majority_times;
    }
  }

  // manage only one majority
  if(majority_times > numsSize/3 * 2+1){
    *returnSize = 1;
    return majority;
  }

  // count the second element times
  majority_times = 0;
  for (int i = 0; i < numsSize; i++){
    if(nums[i]== majority[1]){
      ++majority_times;
    }
  }
  if(majority_times > numsSize/3){
    *returnSize = 2;
  }else{
    *returnSize = 1;
  }
  return majority;
}

// Input:
// [6,5,5]
// Output:
// []
// Expected:
// [5]