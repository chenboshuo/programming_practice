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
    memo[i] = max(memo[i - 1], memo[i - 2] + nums[i - 1]);
  }
  return memo[numsSize];
}
/*
https://leetcode.com/submissions/detail/241941377/
Runtime: 4 ms, faster than 74.29% of C online submissions for House Robber.
Memory Usage: 7.2 MB, less than 10.64% of C online submissions for House Robber.
 */
