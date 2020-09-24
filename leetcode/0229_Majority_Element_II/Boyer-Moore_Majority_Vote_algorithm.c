#include<stdio.h> // NULL in it
int *majorityElement(int *nums, int numsSize, int *returnSize) {
  if(numsSize == 0){
    *returnSize = 0;
    return NULL;
  }
  int* candidates = (int*)malloc(sizeof(int)*2);
  candidates[0]= 0;
  candidates[1] = 1;
  int count1 = 0;
  int count2 = 0;
  for(int i=0;i<numsSize;++i){
    if(nums[i] == candidates[0]){
      ++count1;
    }else if(nums[i] == candidates[1]){
      ++count2;
    }else if(count1 == 0){
      candidates[0] = nums[i];
      count1 = 1;
    }else if(count2 == 0){
      candidates[1] = nums[i];
      count2 = 1;
    }else{
      --count1;
      --count2;
    }
  }

  count1 = 0;
  count2 = 0;
  for(int i=0;i<numsSize;++i){
    if(nums[i] == candidates[0]){
      ++count1;
    }else if(nums[i] == candidates[1]){
      ++count2;
    }
  }

  *returnSize = 0;
  if(count1 > numsSize/3){
    ++(*returnSize);
  }else{
    candidates[0] = candidates[1];
  }

  if(count2 > numsSize/3){
    ++(*returnSize);
  }
  return candidates;

}

// Memory Usage: 7.1 MB, less than 90.91% of C online submissions for Majority Element II.
// Runtime: 12 ms, faster than 63.64% of C online submissions for Majority Element II.