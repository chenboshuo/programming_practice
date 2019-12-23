
int findNumbers(int* nums, int numsSize){
  int count = 0;
  for(int i=0; i<numsSize;++i){
    int digit = 1;
    while(nums[i] /= 10){
      ++digit;
    }
    if(digit % 2 == 0){
      ++count;
    }
  }
  return count;
}

// Runtime: 12 ms (6.5%)
// Memory Usage: 7.4 MB
