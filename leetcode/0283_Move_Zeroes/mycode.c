

void moveZeroes(int* nums, int numsSize) {
  int slow = 0;
  for (int fast = 0; fast < numsSize; ++fast) {
    if (nums[fast] != 0) {
      // exchange
      nums[slow] ^= nums[fast];
      nums[fast] ^= nums[slow];
      nums[slow] ^= nums[fast];
      ++slow;
    }
  }
}

// 9 / 21 test cases passed.
// Status: Wrong Answer
// Submitted: 15 hours, 34 minutes ago
// Input:
// [1]
// Output:
// [0]
// Expected:
// [1]