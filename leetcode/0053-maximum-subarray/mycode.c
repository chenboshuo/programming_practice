#include <limits.h>

int maxSubArray(int *nums, int numsSize) {
  int this_sum, max_sum;

  max_sum = INT_MIN;
  for (int i = 0; i < numsSize; ++i) {
    this_sum = 0;
    for (int j = i; j < numsSize; ++j) {
      this_sum += nums[j];
      if (this_sum > max_sum) {
        max_sum = this_sum;
      }
    }
  }
  return max_sum;
}

// https://leetcode.com/submissions/detail/257712574/
// Runtime: 288 ms, faster than 7.24% of C online submissions for Maximum
// Subarray. Memory Usage: 7.7 MB, less than 15.79% of C online submissions for
// Maximum Subarray.
