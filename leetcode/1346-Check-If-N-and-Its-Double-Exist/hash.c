#include <stdbool.h>
bool checkIfExist(int* arr, int arrSize) {
  bool exist[4000 + 1] = {false};
  for (int i = 0; i < arrSize; ++i) {
    int num = arr[i];
    if (exist[2000 + num * 2] || (!(num & 1) && exist[2000 + num / 2])) {
      return true;
    }
    exist[2000 + num] = true;
  }
  return false;
}

// Runtime: 4 ms, faster than 92.13% of C online submissions for Check If N and
// Its Double Exist. Memory Usage: 7.2 MB, less than 100.00% of C online
// submissions for Check If N and Its Double Exist.