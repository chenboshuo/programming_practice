#include <stdlb.h>
int by_ends(const void *a, const void *b) {
  return ((int *)a)[1] - ((int *)b)[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize,
                          int *intervalsColSize) {
  qsort(intervals, intervalsSize, sizeof(int **), by_ends);

  int choose = 0;
  int cover_begin = 0;
  int cover_end = 0;
  for(int i=0;i<intervalsSize;++i){
    if(intervals[i][0] >= cover_end){
      ++choose;
      cover_end = intervals[i][1];
    }
  }
  return intervalsSize - choose;
}

// https://leetcode.com/submissions/detail/381604750/?from=/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3425/
// Input:
// [[1,100],[11,22],[1,11],[2,12]]
// Output:
// 3
// Expected:
// 2
