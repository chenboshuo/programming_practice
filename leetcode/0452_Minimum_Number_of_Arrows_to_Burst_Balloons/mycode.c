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
  if (pointsSize == 0) { return 0; }
  qsort(points, pointsSize, sizeof(int *), comp);
  int left = INT_MIN;
  int right = INT_MAX;
  int count = 1;
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
// [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
// Output:
// 1
// Expected:
// 2
