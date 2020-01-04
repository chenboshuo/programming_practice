// reference: https://leetcode.com/problems/jump-game-iii/discuss/464083/C%2B%2BJava-3-lines-recursion
#include <stdbool.h>

bool canReach(int* arr, int arrSize, int start){

  if(start<0 || start>arrSize-1 || arr[start]==-1){
    return false;
  }
  int delta = arr[start];
  arr[start] = -1;

  return  (delta == 0)
        || canReach(arr, arrSize, start+delta)
        || canReach(arr, arrSize, start-delta);
}

// Runtime: 36 ms, faster than 75.00% of C online submissions for Jump Game III.
// Memory Usage: 9.8 MB, less than 100.00% of C online submissions for Jump Game III.
