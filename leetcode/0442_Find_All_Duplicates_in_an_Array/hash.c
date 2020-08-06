// reference
// https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/92390/Python-O(n)-time-O(1)-space
#include <math.h>
#include <stdlib.h>
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

// 28 / 28 test cases passed.
// Status: Accepted
// Runtime: 124 ms
// Memory Usage: 16.9 MB
