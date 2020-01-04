#include <stdbool.h>

bool canReach(int* arr, int arrSize, int start){
  if(arr[start] == 0){
    return true;
  }
  if(arr[start] == -1){
    return false;
  }
  int to = arr[start];
  arr[start] = -1;

  return  ((start+to < arrSize)  && canReach(arr, arrSize, start+to) )
          ||( (start-to > -1) && canReach(arr, arrSize, start-to)); // 递归-1 参与运算
}

// Runtime: 44 ms
// Memory Usage: 10 MB
