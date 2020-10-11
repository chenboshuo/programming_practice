#include <limits.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int comp(const void *a, const void *b) {
  int *point_a = (int *)a;
  int *point_b = (int *)b;
  int diff = point_a[0] - point_b[0];
  if (diff) {
    return diff;
  } else {
    return point_a[1] - point_b[1];
  }
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize) {
  qsort(points, pointsSize, sizeof(int *), comp);
  int left = INT_MIN;
  int right = INT_MIN;
  int count = 0;
  for (int i = 0; i < pointsSize; ++i) {
    if (points[i][0] <= right) {
      left = points[i][0];
      right = min(right, points[i][1]);
    } else {
      left = points[i][0];
      right = points[i][1];
      ++count;
    }
  }
  return count;
}

// Input:
// [[-2147483648,2147483647]]
// Output:
// 0
// Expected:
// 1
