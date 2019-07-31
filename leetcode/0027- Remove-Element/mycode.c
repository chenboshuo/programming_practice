int removeElement(int *nums, int numsSize, int val) {
  int *p = nums;
  int *q = nums;
  for (int i = 0; i < numsSize; ++i, ++q) {
    if (*q != val) {
      *p++ = *q;
    }
  }
  return numsSize - (q - p);
}
// https://leetcode.com/submissions/detail/247771434/
// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove
// Element. Memory Usage: 7.3 MB, less than 36.36% of C online submissions for
// Remove Element.
