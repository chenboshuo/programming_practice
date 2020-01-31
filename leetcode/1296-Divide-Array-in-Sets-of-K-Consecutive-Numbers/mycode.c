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
  // int pre = -1; // 记录前一个数

  while(numsSize--){
    // 应该不能偷懒
    // if(*nums != pre && *nums != pre+1){
    //   i = begin;
    // }

    for(i=begin;i<end; ++i){
      if (*nums == final[i] + 1){
        final[i] = *nums;
        if(++len[i] == k){ // 一组存满, 表示开始的指针后移
          if(i>1 && len[i-1] < len[i]){ // 前一组没有存满, 那一组永远满不了
            return false;
          }
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

    // pre = *nums;
    ++nums;
  }

  return true;
}
// Runtime: 620 ms, faster than 22.22% of C
// online submissions for Divide Array in Sets of K Consecutive Numbers.
// Memory Usage: 13.4 MB, less than 100.00% of C
// online submissions for Divide Array in Sets of K Consecutive Numbers.
// https://leetcode.com/submissions/detail/298983439/
