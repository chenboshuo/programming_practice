// reference https://leetcode.com/problems/find-numbers-with-even-number-of-digits/discuss/458811/4ms-7.1MB-C-code
int findNumbers(int* nums, int numsSize){
  int count = 0,i;
  for(i=0; i<numsSize;++i){
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

// Runtime: 4 ms, faster than 96.77% of C online submissions
// for Find Numbers with Even Number of Digits.
// Memory Usage: 7.4 MB, less than 100.00% of C online submissions
// for Find Numbers with Even Number of Digits.
