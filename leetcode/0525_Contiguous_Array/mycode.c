int next_n(int* nums, int nums_size, int n, int index){
  for(++index;index<nums_size;++index){
    if(nums[index] == n){
      return index;
    }
  }
  return -1;
}

int findMaxLength(int* nums, int nums_size){
  int zero_i = -1, one_i = -1,count=0;
  while((zero_i = next_n(nums, nums_size,0,zero_i)) != -1 && 
        (one_i = next_n(nums, nums_size,1,zero_i) != -1)){
    count+=2;
  }
  return count;
}

// 259 / 555 test cases passed.
// Status: Wrong Answer
// Submitted: 3 hours, 20 minutes ago
// Input:
// [0,0,1,0,0,0,1,1]
// Output:
// 10
// Expected:
// 6