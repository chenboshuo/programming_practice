/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int nums_size, int* return_size) {
  int left_product = 1;
  int* output = (int*)malloc(sizeof(int) * nums_size);
  *return_size = nums_size;
  for (int i = 0; i < nums_size; ++i) {
    output[i] = left_product;
    left_product *= nums[i];
  }
  int right_product = 1;
  for (int i = nums_size - 1; i > -1; --i) {
    output[i] *= right_product;
    right_product *= nums[i];
  }
  return output;
}

// Runtime: 48 ms, faster than 67.12% of C online submissions for Product of Array Except Self.
// Memory Usage: 13.8 MB, less than 100.00% of C online submissions for Product of Array Except Self.

// https://leetcode.com/submissions/detail/325122370/