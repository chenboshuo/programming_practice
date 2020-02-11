struct Counter{
  int value;
  int count;
};

int by_value(void const*a, void const*b){
  return *(int*)a - *(int*)b;
}

int by_count(void const *a, void const*b){
  return ((struct Counter*)b) -> count - ((struct Counter*)a) -> count;
}

int minSetSize(int* arr, int arrSize){
  qsort(arr, arrSize, sizeof(int), by_value);
  struct Counter counter[arrSize];
  struct Counter *p = counter-1;
  int pre = 0;
  int counter_size = 0;
  int half = arrSize/2;
  while(arrSize--){
    if(*arr == pre){
      ++(p->count);
    }else{
      ++p;
      p->value = *arr;
      p->count = 1;
      pre = *arr;
      ++counter_size;
    }
    ++arr;
  }

  qsort(counter, counter_size, sizeof(struct Counter), by_count);
  int sum = 0;
  for(int i=0; i<counter_size; ++i){
    sum += counter[i].count;
    if(sum >= half){
      return i+1;
    }
  }
  return counter_size;
}
// Runtime: 140 ms, faster than 52.63% .
// Memory Usage: 16.8 MB, less than 100.00% .
