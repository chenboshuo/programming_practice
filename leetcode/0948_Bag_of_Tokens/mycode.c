#include <stdlib.h>
#define max(a, b) ((a > b) ? (a) : (b))
int by_value(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int bag_of_tokens_score(int *tokens, int left, int right, int p) {
  if (p < 0) { return -1; }
  if (left > right) { return 0; }
  if (left == right) { return p >= tokens[left]; }
  int face_down = 0;
  if (p >= tokens[left]) {
    face_down = bag_of_tokens_score(
        tokens, left + 1, right - 1,
        p + tokens[right] - tokens[left]);  // use the least to face down
  }
  int face_up =
      bag_of_tokens_score(tokens, left + 1, right, p - tokens[left]) + 1;
  return max(face_down, face_up);
}
int bagOfTokensScore(int *tokens,  //
                     int tokensSize, int P) {
  qsort(tokens, tokensSize, sizeof(int), by_value);
  return bag_of_tokens_score(tokens, 0, tokensSize - 1, P);
}
// time limmit exceed
// [2897,6861,2070,5292,3402,9784,9718,2089,5660,3294,9685,9245,5861,7200,6813,3533,9163,8994,3306,7473,90,8163,5648,9523,3631,6257,3230,7827,6007,9874,10,1407,436,1258,9293,9486,4804,9466,8183,7786,7472,1876,5488,4238,9497,1738,1698,6588,1574,1100]
// 5039
