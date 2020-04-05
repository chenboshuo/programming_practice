

void moveZeroes(int* nums, int numsSize) {
  int slow = 0;
  for (int fast = 0; fast < numsSize; ++fast) {
    if (nums[fast] != 0) {
      // exchange
      int temp = nums[fast];
      nums[fast] = nums[slow];
      nums[slow] = temp;
      ++slow;
    }
  }
}

// Submission Detail
// 21 / 21 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 7.2 MB
// Submitted: 15 hours, 20 minutes ago
