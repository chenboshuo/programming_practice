int cascade(void const*a, void const*b){
  return *(int*)a - *(int*)b;
}

int descend(void const*a, void const*b){
  return *(int*)b - *(int*)a;
}

int minSetSize(int* arr, int arrSize){
  qsort(arr, arrSize, sizeof(int), cascade);
  int counter[arrSize];
  int pre = 0;
  int counter_size = 0;
  int half = arrSize/2;
  while(arrSize--){
    if(*arr == pre){
      ++counter[counter_size-1];
    }else{
      counter[counter_size] = 1;
      ++counter_size;
      pre = *arr;
    }
    ++arr;
  }
  // ++counter_size;

  qsort(counter, counter_size, sizeof(int), descend);
  int sum = 0;
  for(int i=0; i<counter_size; ++i){
    sum += counter[i];
    if(sum >= half){
      return i+1;
    }
  }
  return counter_size;
}
// https://leetcode.com/submissions/detail/302299822/
// Runtime: 140 ms, faster than 52.63% of C online submissions for Reduce Array Size to The Half.
// Memory Usage: 16.2 MB, less than 100.00% of C online submissions for Reduce Array Size to The Half.
