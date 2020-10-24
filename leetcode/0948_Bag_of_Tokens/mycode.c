#include <stdlib.h>
#define max(a, b) ((a > b) ? (a) : (b))
int by_value(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int bagOfTokensScore(int *tokens,  //
                     int tokensSize, int P) {
  qsort(tokens, tokensSize, sizeof(int), by_value);
  int up_max_score =
      -1;  // the point nearest to P=0 from face up_max_score direction
  int down_max_score = -1;
  int score = 0;
  for (int i = 0; i < tokensSize; ++i) {
    P -= tokens[i];
    ++score;
    if (P < 0 && up_max_score == -1) { up_max_score = score - 1; }
  }
  if (up_max_score > 0) {
    for (int i = tokensSize - 1; i >= 0; --i) {
      if (P >= 0 && down_max_score == -1) { down_max_score = score; }
      P += 2 * tokens[i];
      score -= 2;
    }
  }
  return max(up_max_score, down_max_score);
}
// Input:
// []
// 85
// Output:
// -1
// Expected:
// 0
