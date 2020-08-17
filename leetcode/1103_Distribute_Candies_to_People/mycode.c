#include <stdbool.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *distributeCandies(int candies, int num_people, int *returnSize) {
  int *ans = (int *)calloc(sizeof(int), num_people);
  *returnSize = num_people;
  int cur = 1;
  while (candies) {
    for (int i = 0; i < num_people; ++i) {
      int give = min(candies, cur);
      ans[i] += give;
      candies -= give;
      ++cur;
    }
  }
  return ans;
}
// 27 / 27 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// Memory Usage: 5.5 MB
// Submitted: 0 minutes ago
