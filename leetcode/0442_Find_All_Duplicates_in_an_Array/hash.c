// reference
// https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/92390/Python-O(n)-time-O(1)-space
#include <stdlib.h>
#define abs(x) ((x > 0) ? (x) : (-x))
int *findDuplicates(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)malloc(sizeof(int) * (numsSize / 2));
  *returnSize = 0;
  for (int i = 0; i < numsSize; ++i) {
    int x = abs(nums[i]);
    if (nums[x - 1] < 0) {
      ans[(*returnSize)++] = x;
    } else {
      nums[x - 1] *= -1;
    }
  }
  return ans;
}

// Runtime: 92 ms, faster than 99.09% of C online submissions for Find All
// Duplicates in an Array. Memory Usage: 17 MB, less than 100.00% of C online
// submissions for Find All Duplicates in an Array.
