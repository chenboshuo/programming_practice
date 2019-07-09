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
  int pre = 0;
  int cur = *nums;
  for (int i = 1; i < numsSize; ++i) {
    int _ = cur;
    cur = max(cur, pre + nums[i]);
    pre = _;
  }
  return cur;
}
/*
int rob(int *nums, int numsSize) {
  if (numsSize==0) {
    return 0;
  }
  if (numsSize == 1) {
    return *nums;
  }
  int pre = 0;
  int cur = *nums;
  for(int i = 1; i<numsSize; ++i){
    int _ = cur;
    cur = max(cur, pre + nums[i]);
    pre = _;
  }
  return cur;
}
https://leetcode.com/submissions/detail/241954839/
69 / 69 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 7.1 MB
性能低了
 */
