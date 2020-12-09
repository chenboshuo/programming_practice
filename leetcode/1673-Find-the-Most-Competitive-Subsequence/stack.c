// https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952786/JavaC%2B%2BPython-One-Pass-Stack-Solution
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *mostCompetitive(int *nums, int numsSize, int k, int *returnSize) {
  *returnSize = k;
  int *stack = (int *)malloc(sizeof(int) * k);
  int top = 0;
  for (int i = 0; i < numsSize; ++i) {
    while (top && nums[i] < stack[top - 1] && top - 1 + numsSize - i >= k) {
      --top;
    }
    if (top < k) { stack[top++] = nums[i]; }
  }
  return stack;
}
// Runtime: 392 ms, faster than 57.14% of C online submissions for Find the Most
// Competitive Subsequence. Memory Usage: 45.7 MB, less than 14.29% of C online
// submissions for Find the Most Competitive Subsequence.
