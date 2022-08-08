#define max(a, b) (((a) > (b)) ? (a) : (b))
int rob(int *nums, int numsSize) {
  if (numsSize <= 3) {
    int ans = 0;
    for (int i = 0; i < numsSize; ++i) { ans = max(ans, nums[i]); }
    return ans;
  }
  int pre = 0, cur = 0;
  for (int i = 2; i < numsSize - 4; ++i) {
    int temp = cur;
    cur = max(pre + nums[i], cur);
    pre = temp;
  }
}
