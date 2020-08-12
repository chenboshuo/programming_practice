#include <stdlib.h>
int reverse(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int hIndex(int *citations, int citationsSize) {
  if (citationsSize == 0 || (citationsSize == 1 && citations[0] == 0)) { return 0; }
  qsort(citations, citationsSize, sizeof(int), reverse);
  int left = 0;
  int right = citationsSize - 1;
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (citations[mid] >= mid + 1) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  return left + 1;
}

// Submission Result: Wrong Answer 
// Input:
// [0,0]
// Output:
// 1
// Expected:
// 0