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

// 参考:
// https://mp.weixin.qq.com/s?__biz=MzUyNjQxNjYyMg==&mid=2247485240&idx=1&sn=fbccc747b2e8558c6478171709005ff9&chksm=fa0e68b9cd79e1af5ab68d42adea0b24c7d4867069091df9e95b6f20ab57b69c4e38994a36be
// 官方实现方法
int searchInsert_(int *nums, int numsSize, int target) {
  int left = 0, right = numsSize - 1;
  if (target > nums[right]) {
    return numsSize;
  }
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (target == nums[mid]) {
      return mid;
    } else if (target > nums[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}

// https://leetcode.com/submissions/detail/251575639/
// Input:
// [1,3,5,6]
// 2
// Output:
// 0
// Expected:
// 1
