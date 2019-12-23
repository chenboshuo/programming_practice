#include <stdbool.h>
#include <stdlib.h>

int comp(const void* a, const void*b){
  return *(int*)a - *(int*)b;
}

bool isPossibleDivide(int* nums, int numsSize, int k){
  if(numsSize % k != 0){
    return false;
  }
  bool* has_visited = (bool*) malloc(sizeof(bool) * numsSize);
  for(int i = 0; i<numsSize;++i){
    has_visited[i] = false;
  }
  qsort(nums, numsSize, sizeof(int), comp);
  while(1){
    int begin;
    for(begin=0; begin< numsSize; ++begin){
      if(!has_visited[begin]){
        break;
      }
    }
    // if(begin == numsSize){ // 如果自然结束循环, 说明所有元素均正常访问
    //   return true;
    // }

    has_visited[begin] = true;
    int count = 1;
    int pre = nums[begin];
    int i=0;
    for(i=1; begin+i<numsSize;++i){
      if(count == k){
        break;
      }
      if(nums[begin+i] == pre + 1){
        has_visited[begin+i] = true;
        pre = nums[begin+i];
        ++count;
      }
    }
    // 上一个循环没有达到条件, 错误
    if(count != k){
      return false;
    }
    if(begin+i == numsSize){
      return true;
    }

  }
}
