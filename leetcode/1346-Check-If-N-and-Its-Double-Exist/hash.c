#include <stdbool.h>
bool checkIfExist(int* arr, int arrSize) {
  bool exist[4000 + 1] = {false};
  for (int i = 0; i < arrSize; ++i) {
    if (exist[2000 + arr[i] * 2] ||
        (!(arr[i] & 1) && exist[2000 + arr[i] / 2])) {
      return true;
    }
    exist[2000 + arr[i]] = true;
  }
  return false;
}
// Runtime: 8 ms, faster than 58.43% of C online submissions for Check If N and
// Its Double Exist. Memory Usage: 7.3 MB, less than 100.00% of C online
// submissions for Check If N and Its Double Exist.