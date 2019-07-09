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

int rob(int *nums, int numsSize) {
  if (numsSize == 0) {
    return 0;
  }
  memo = (int *)malloc(sizeof(int) * (numsSize + 1));
  memo[0] = 0;
  memo[1] = *nums;
  for (int i = 1; i < numsSize; ++i) {
    memo[i + 1] = max(memo[i], memo[i - 1] + nums[i]);
  }
  return memo[numsSize];
}
/*
https://leetcode.com/submissions/detail/241941377/
Runtime: 4 ms, faster than 74.29% of C online submissions for House Robber.
Memory Usage: 7.2 MB, less than 10.64% of C online submissions for House Robber.
 */
