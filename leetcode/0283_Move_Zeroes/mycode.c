
void moveZeroes(int* nums, int numsSize) {
  int slow = 0;
  for (int fast = 0; fast < numsSize; ++fast) {
    if (nums[fast] != 0) {
      nums[slow] = nums[fast];
      slow++;
    }
  }
  while (slow < numsSize) {
    nums[slow++] = 0;
  }
}

// 21 / 21 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 7.5 MB
// Submitted: 4 minutes ago
