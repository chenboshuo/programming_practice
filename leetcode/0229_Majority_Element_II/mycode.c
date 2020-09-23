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
  int times = 2;
  majority[0] = nums[0];
  for (int i = 1; i < numsSize; i++){
    if(nums[i] == majority[0]){
      times += 2;
    }else{
      times -= 1;
    }
    if(times == 0){
      majority[0] = nums[i];
      times = 2;
    }
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

  // mange the equal cases
  if(majority_times <= numsSize/3){
    *returnSize = 0;
    return NULL;
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

// Submission Result: Wrong Answer 
// Input:
// [0,3,4,0]
// Output:
// []
// Expected:
// [0]