#include <math.h>
int minFlips(int a, int b, int c){
  int ai,bi,ci,count=0;
  while(c){
    ai = a&1;
    bi = b&1;
    ci = c&1;
    count += ((ai|bi)^ci)*fabs(ai+bi-ci);
    c>>=1;
    b>>=1;
    a>>=1;
  }
  return count;
}
// Wrong Answer
// Details
// Input
// 8
// 3
// 5
// Output
// 2
// Expected
// 3
// https://leetcode.com/submissions/detail/298404236/
