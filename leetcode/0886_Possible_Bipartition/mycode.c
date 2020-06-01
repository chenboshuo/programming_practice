#define INIT 2
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool possibleBipartition(int N, int **dislikes, int dislikesSize,
                         int *dislikesColSize) {
  char party[N + 1];
  memset(party, INIT, N + 1);
  for (int i = 0; i < dislikesSize; ++i) {
    switch (((party[dislikes[i][0]] == INIT) << 1) +
            (party[dislikes[i][1]] == INIT)) {
      case 3:
        party[dislikes[i][0]] = 0;
        party[dislikes[i][1]] = 1;
        break;
      case 2: party[dislikes[i][0]] = 1 - party[dislikes[i][1]]; break;
      case 1: party[dislikes[i][1]] = 1 - party[dislikes[i][0]]; break;
      case 0:
        if (party[dislikes[i][0]] == party[dislikes[i][1]]) { return false; }
    }
  }
  return true;
}

// Submission Detail
// 40 / 66 test cases passed.
// Status: Wrong Answer
// Submitted: 4 days, 18 hours ago
// Input:
// 10
// [[4,7],[4,8],[5,6],[1,6],[3,7],[2,5],[5,8],[1,2],[4,9],[6,10],[8,10],[3,6],[2,10],[9,10],[3,9],[2,3],[1,9],[4,6],[5,7],[3,8],[1,8],[1,7],[2,4]]
// Output:
// false
// Expected:
// true
