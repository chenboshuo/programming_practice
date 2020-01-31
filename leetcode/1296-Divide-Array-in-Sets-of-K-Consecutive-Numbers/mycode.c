#include <stdbool.h>
#include <stdlib.h>

int comp(const void* a, const void*b){
  return *(int*)a - *(int*)b;
}


bool isPossibleDivide(int* nums, int numsSize, int k){
  if(numsSize % k != 0){
    return false;
  }

  qsort(nums, numsSize, sizeof(int), comp);
  int len_sets = numsSize / k;   // 每组最大长度
  int *len = (int*)calloc(len_sets, sizeof(int)); // 每一组的长度
  // int final[numsSize/k];
  int *final = (int*)calloc(len_sets, sizeof(int)); // 每一组的最后一个数
  int begin = 0; //
  int end = 0;
  int i;
  int pre = -1; // 记录前一个数

  while(numsSize--){
    if(*nums != pre && *nums != pre+1){
      i = begin;
    }

    for(;i>begin-1 &&i<end; ++i){
      if (*nums == final[i] + 1){
        final[i] = *nums;
        if(++len[i] == k){ // 一组存满, 表示开始的指针后移
          ++begin;
        }
        break;
      }
    }
    if(i == end){
      if(++end > len_sets){
        return false;
      }else{
        final[i] = *nums;
        ++len[i];
      }

    }

    pre = *nums;
    ++nums;
  }

  return true;
}

// Wrong Answer
// Details
// Input
// [1,2,3,3,4,4,5,6]
// 4
// Output
// false
// Expected
// true
//
// https://leetcode.com/submissions/detail/298980137/
