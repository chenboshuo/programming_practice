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
    while (top && nums[i] < stack[top - 1] && top - 1 + numsSize - 1 >= k) {
      --top;
    }
    if (top < k) { stack[top++] = nums[i]; }
  }
  return stack;
}
// Wrong Answer
// Details
// Input
// [71,18,52,29,55,73,24,42,66,8,80,2]
// 3
// Output
// [2,80,42]
// Expected
// [8,80,2]
