int searchInsert(int *nums, int numsSize, int target) {
  int left = 0, right = numsSize - 1;
  if (target > nums[right]) {
    return numsSize;
  }
  while (left < right) {
    int mid = (left + right) / 2;
    if (mid == left) {
      return (target > nums[mid]) ? mid + 1 : mid;
    }
    if (target == nums[mid]) {
      return mid;
    } else if (target > nums[mid]) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return 0;
}

// https://leetcode.com/submissions/detail/251574416/
// Runtime: 4 ms, faster than 85.85% of C online submissions for Search
// Insert Position. Memory Usage: 7.1 MB, less than 100.00% of C online
// submissions for Search Insert Position.
