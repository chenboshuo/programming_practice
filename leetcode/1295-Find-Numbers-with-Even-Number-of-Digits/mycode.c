int findNumbers(int* nums, int numsSize){
  int count = 0;
  for(int i=0; i<numsSize;++i){
    int digit = 1;
    while(nums[i] /= 10){
      ++digit;
    }
    if((digit & 1) == 0){
      ++count;
    }
  }
  return count;
}


// Runtime: 8 ms, faster than 48.39% of C online submissions
// for Find Numbers with Even Number of Digits.
// Memory Usage: 7.1 MB, less than 100.00% of C online submissions
// for Find Numbers with Even Number of Digits.
