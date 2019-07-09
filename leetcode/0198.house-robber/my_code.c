/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 * reference:
 * https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
 */
#define max(a, b) (a) > (b) ? (a) : (b)

int rob(int *nums, int numsSize) {
  if (numsSize == 0) {
    return 0;
  }
  if (numsSize == 1) {
    return *nums;
  }
  int pre = *nums;
  int cur = nums[1];
  for (int i = 2; i < numsSize; ++i) {
    // memo[i + 1] = max(memo[i], memo[i - 1] + nums[i]);
    int _ = cur;
    cur = max(cur, pre + nums[i]);
    pre = _;
  }
  return cur;
}
/*
https://leetcode.com/submissions/detail/241953507/
Input:
[2,1]
Output:
1
Expected:
2
 */
