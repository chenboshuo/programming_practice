/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int nums_size, int* return_size) {
  int product = 1;
  bool has_zero = false;
  int* output = (int*)malloc(sizeof(int) * nums_size);
  *return_size = nums_size;

  for (int i = 0; i < nums_size; ++i) {
    if (nums[i] != 0) {
      product *= nums[i];
    } else if (has_zero) {
      for (int j = 0; j < nums_size; ++j) {
        output[j] = 0;
      }
      return output;
    } else {
      has_zero = true;
    }
  }

  if (has_zero) {
    for (int i = 0; i < nums_size; ++i) {
      if (nums[i] != 0) {
        output[i] = 0;
      } else {
        output[i] = product;
      }
    }
    return output;
  }

  for (int i = 0; i < nums_size; ++i) {
    output[i] = product / nums[i];
  }

  return output;
}

// https://leetcode.com/submissions/detail/325103450/
// 18 / 18 test cases passed.
// Status: Accepted
// Runtime: 36 ms
// Memory Usage: 13.7 MB
// Submitted: 1 hour, 18 minutes ago
