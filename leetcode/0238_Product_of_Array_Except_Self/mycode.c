/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int nums_size, int* return_size){
  int product = 1;
  
  for(int i=0;i<nums_size;++i){
    product *= nums[i];
  }
  
  int *output = (int*)malloc(sizeof(int)*nums_size);
  *return_size = nums_size;
  
  for(int i=0;i<nums_size;++i){
    output[i] = product / nums[i];
  }
  
  return output;
}

// https://leetcode.com/submissions/detail/325086933/
// Runtime Error Message:
// Line 17: Char 25: runtime error: division by zero (solution.c)
// Last executed input:
// [0,0]