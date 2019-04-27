int removeDuplicates(int* nums, int numsSize){
  int *pre = nums, *q = nums;
  for(int i = 1; i < numsSize; i++){
    if (*pre == *q) {
      ++q;
    }
    else {
      ++q;
      *pre = *q;
      ++pre;
    }
  }
  return pre - nums + 1;
}
