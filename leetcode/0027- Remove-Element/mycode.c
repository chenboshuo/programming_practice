int removeElement(int *nums, int numsSize, int val) {
  int i, j = 0;
  for (i = 0; i < numsSize; ++i) {
    if (nums[i] != val) {
      nums[j++] = nums[i];
    }
  }
  return numsSize - (i - j);
}

// https://leetcode.com/submissions/detail/247772609/
// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove
// Element. Memory Usage: 7.2 MB, less than 68.69% of C online submissions for
// Remove Element.
