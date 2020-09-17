#define max(a, b) (((a) > (b)) ? (a) : (b))

int findMaximumXOR(int *nums, int numsSize) {
  int m = 0;
  for (int i = 1; i < numsSize; ++i) {
    for (int j = 0; j < i; ++j) {
      m = max(m, nums[i] ^ nums[j]);
      // m = 1;
    }
  }
  return m;
}
