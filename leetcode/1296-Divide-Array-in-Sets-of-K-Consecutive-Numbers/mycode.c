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

      if(nums[begin+i] == pre + 1){
        has_visited[begin+i] = true;
        pre = nums[begin+i];
        ++count;
      }
      if(count == k){
        break;
      }
    }
    if(begin+i == numsSize){
      return true;
    }

    // 上一个循环没有达到条件, 错误
    if(count != k){
      return false;
    }


  }
}

// Runtime Error Message:
// AddressSanitizer: heap-buffer-overflow on address 0x60200000011f at pc 0x000000401b46 bp 0x7ffc1ba90db0 sp 0x7ffc1ba90da8
// Last executed input:
// [10,9,8,1,2,3,2,3,4,4,5,6,10,11,12]
// 3
