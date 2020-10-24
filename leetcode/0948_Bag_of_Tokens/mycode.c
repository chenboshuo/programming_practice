#include <stdlib.h>
#define max(a, b) ((a > b) ? (a) : (b))
int by_value(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int bag_of_tokens_score(int *tokens, int left, int right, int p) {
  if (p < 0) { return -1; }
  if (left > right) { return 0; }
  if (left == right) { return p >= tokens[left]; }
  int face_down = bag_of_tokens_score(
      tokens, left + 1, right - 1,
      p + tokens[right] - tokens[left]);  // use the least to face down
  int face_up =
      bag_of_tokens_score(tokens, left + 1, right, p - tokens[left]) + 1;
  return max(face_down, face_up);
}
int bagOfTokensScore(int *tokens,  //
                     int tokensSize, int P) {
  qsort(tokens, tokensSize, sizeof(int), by_value);
  return bag_of_tokens_score(tokens, 0, tokensSize - 1, P);
}
// Input:
// [71,55,82]
// 54
// Output:
// 1
// Expected:
// 0
