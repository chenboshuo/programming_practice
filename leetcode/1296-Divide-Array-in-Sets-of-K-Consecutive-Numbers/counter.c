#include <stdbool.h>
#include <stdlib.h>
int comp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

bool isPossibleDivide(int* nums, int numsSize, int k) {
  if (numsSize % k != 0) {
    return false;
  }

  qsort(nums, numsSize, sizeof(int), comp);

  // 统计数字出现次数
  int count[numsSize * 2];
  size_t ptr_count = 0;
  // int pre = *nums;
  count[0] = 1;
  int pre = *nums;
  ++nums;
  while (--numsSize) {
    if (*nums == pre) {
      ++count[ptr_count];
    } else if (*nums == pre + 1) {
      ptr_count++;
      count[ptr_count] = 1;
    } else {  // 有可能数字间断, 那存储的时候也间断
      ptr_count++;
      count[ptr_count] = 0;
      ptr_count++;
      count[ptr_count] = 1;
    }
    pre = *nums;
    ++nums;
  }

  // 验证
  int minus;
  for (size_t begin = 0; begin < ptr_count; ++begin) {
    if ((minus = count[begin]) > 0) {
      for (size_t i = begin; i < begin + k; ++i) {
        if (count[i] < minus) {
          return false;
        }
        count[i] -= minus;
      }
    }
  }

  return true;
}

// Runtime: 80 ms, faster than 80.00% of C online submissions for Divide Array
// in Sets of K Consecutive Numbers.
// Memory Usage: 13.4 MB, less than 100.00% of
// C online submissions for Divide Array in Sets of K Consecutive Numbers.
// https://leetcode.com/submissions/detail/300135774/
