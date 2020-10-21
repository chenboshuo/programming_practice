/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#define abs(a) (((a) < 0) ? (-a) : (a))
int *asteroidCollision(int *asteroids, int asteroidsSize, int *returnSize) {
  int *survivor = (int *)malloc(asteroidsSize * sizeof(int));
  int top = 0;
  for (int i = 0; i < asteroidsSize;) {
    if (top == 0 || asteroids[i] > 0 ||
        survivor[top - 1] < 0) {  // no collision
      survivor[top++] = asteroids[i];
      ++i;
    } else {
      while (top > 0 && i < asteroidsSize && survivor[top - 1] > 0 &&
             asteroids[i] < 0) {
        if (survivor[top - 1] + asteroids[i] == 0) {
          --top;
          i++;
        } else if (abs(survivor[top - 1]) < abs(asteroids[i])) {
          --top;
        } else {
          ++i;
        }
      }
    }
  }
  *returnSize = top;
  return survivor;
}

// 275 / 275 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 6.9 MB
// Submitted: 0 minutes ago
