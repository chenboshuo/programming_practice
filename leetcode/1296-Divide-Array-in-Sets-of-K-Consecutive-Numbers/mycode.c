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
  int final[len_sets]; // 每一组的最后一个数
  // int *final = (int*)calloc(len_sets, sizeof(int));
  int begin = 0; //
  int end = 0;
  int i;
  int pre = -1; // 记录前一个数

  while(numsSize--){
    // 应该不能偷懒
    // if(*nums != pre && *nums != pre+1){
    //   i = begin;
    // }

    for(i=begin;i<end; ++i){
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
// Input
// [16,5,15,15,20,16,20,14,21,20,19,20,12,17,13,15,11,17,18,18,11,13,13,14,14,9,20,18,10,4,4,6,15,19,8,15,7,17,15,9,24,2,23,22,26,8,21,22,14,13,16,2,25,23,17,19,17,3,22,23,19,12,21,12,16,27,28,10,13,8,24,3,22,6,10,9,14,7,11,22,11,5,16,19,21,2,8,24,16,21,7,29,18,9,10,18,6,17,21,20]
// 10
// Output
// true
// Expected
// false
//
// https://leetcode.com/submissions/detail/298981067/
