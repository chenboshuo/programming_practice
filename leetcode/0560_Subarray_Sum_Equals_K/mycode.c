int subarraySum(int* nums, int nums_size, int k) {
  int count = 0;
  for (int i = 0; i < nums_size; ++i) {
    int sum = 0;
    for (int j = i; j < nums_size; ++j) {
      if ((sum += nums[j]) == k) {
        ++count;
        continue;
      }
    }
  }
  return count;
}

// Wrong Answer
// Details 
// Input
// [0,0,0,0,0,0,0,0,0,0]
// 0
// Output
// 10
// Expected
// 55