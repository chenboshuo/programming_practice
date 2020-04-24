int subarraySum(int* nums, int nums_size, int k) {
  int count = 0;
  int sum;
  for (int i = 0; i < nums_size; ++i) {
    sum = 0;
    for (int j = i; j < nums_size; ++j) {
      if ((sum += nums[j]) == k) {
        ++count;
        continue;
      }
    }
  }
  return count;
}

// Runtime: 452 ms, faster than 68.94% of C online submissions for Subarray Sum Equals K.
// Memory Usage: 6.6 MB, less than 100.00% of C online submissions for Subarray Sum Equals K.