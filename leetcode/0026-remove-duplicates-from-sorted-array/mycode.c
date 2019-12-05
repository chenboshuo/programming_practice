/**
 * 去重
 * @param  nums     数组
 * @param  numsSize 数组大小
 * @return          新的数组的大小
 */
int removeDuplicates(int* nums, int numsSize){
  if(numsSize<2){
    return numsSize;
  }

  int pre;
  int post = 0;


  for(pre = 1;pre < numsSize;++pre){
    if(nums[post] != nums[pre]){
      nums[++post] = nums[pre];
    }
  }
  return post+1;
}

// Runtime: 16 ms, faster than 92.42% of C online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 9.6 MB, less than 50.00% of C online submissions for Remove Duplicates from Sorted Array.
