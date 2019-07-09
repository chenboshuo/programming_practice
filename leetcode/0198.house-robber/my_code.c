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
  while (numsSize-- > 1) {
    int _ = cur;
    cur = max(cur, pre + *(++nums));
    pre = _;
  }
  return cur;
}
/*
https://leetcode.com/submissions/detail/241954072/
Runtime Error Message:
AddressSanitizer: heap-buffer-overflow on address 0x602000000020 at pc
0x00000040181b bp 0x7ffe0f7478f0 sp 0x7ffe0f7478e8 Last executed input:
[1,2,3,1]
 */
