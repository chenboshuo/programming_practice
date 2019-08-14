

int searchInsert(int* nums, int numsSize, int target){
  int left = 0, right = numsSize - 1;
  if(target > nums[right]){
    return numsSize;
  }
  while(left < right){
    int mid = (left + right)/2;

    if (target == nums[mid]){
      return mid;
    }else if (target > nums[mid]){
      left = mid;
    }else{
      right = mid;
    }
    if(mid == left){
      return (target > nums[mid])? mid+1 : mid;
    }
  }
  return 0;
}

// https://leetcode.com/submissions/detail/251573361/
// Input:
// [1,3,6,9]
// 9
// Output:
// 2
// Expected:
// 3
