int subarraySum(int* nums, int nums_size, int k){
  long int s[nums_size+1];
  int *sums = s+1;
  int count = 0;
  sums[0] = 0;
  for(int i=0;i<nums_size;++i){
    sums[i] = sums[i-1] + nums[i];
    for(int j=-1;j<=i;++j){
      if(sums[i] - sums[j] == k){
        ++count;
      }
    }
  }
  return count;

}


// 77 / 80 test cases passed.
// Status: Wrong Answer
// Submitted: 1 day, 19 hours ago
// Input:
// [1]
// 0
// Output:
// 1
// Expected:
// 0