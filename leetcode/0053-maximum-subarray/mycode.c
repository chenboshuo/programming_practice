int maxSubArray(int *nums, int numsSize) {
  int sum1 = *nums, sum2 = *nums;
  int negative = *nums;
  ++nums;

  for (; --numsSize; ++nums) {
    // 如果读取到负数,sum_2
    if (*nums < 0) {
      if ((sum1 + sum2) > negative) {
        sum1 += sum2 + negative;
      }

      // 切换sum
      sum1 ^= sum2, sum2 ^= sum1, sum1 ^= sum2;
      negative = *nums;
    } else {
      sum1 += *nums;
    }
  }
  return sum1;
}
