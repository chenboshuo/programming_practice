/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 * reference:
 * https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
 */

#include <stdlib.h>
#define max(a, b) (a) > (b) ? (a) : (b)
int *memo;
int solve(int *nums, int numsSize);

int rob(int *nums, int numsSize) {
  if (numsSize == 0) {
    return 0;
  }
  memo = (int *)malloc(sizeof(int) * (numsSize + 1));
  memo[0] = 0;
  memo[1] = *nums;
  for (int i = 2; i < numsSize + 1; ++i) {
    memo[i] = -1;
  }
  if (numsSize > 1) {
    memo[2] = max(*nums, *(nums + 1));
  }
  return solve(nums, numsSize);
}

int solve(int *nums, int numsSize) {
  if (memo[numsSize] > -1) {
    return memo[numsSize];
  }
  int sum1 =
      nums[numsSize - 1] + solve(nums, numsSize - 2); // 头指针不能随便动了
  int sum2 = solve(nums, numsSize - 1);
  memo[numsSize] = max(sum1, sum2);
  return memo[numsSize];
}
/*
https://leetcode.com/submissions/detail/241694540/
Runtime: 4 ms, faster than 74.43% of C online submissions for House Robber.
Memory Usage: 7 MB, less than 53.47% of C online submissions for House Robber.
 */
