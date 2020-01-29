#include <math.h>
int minFlips(int a, int b, int c){
  int ai,bi,ci,count=0;
  while(a||b||c){
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
// Runtime: 4 ms, faster than 45.83% of C online submissions for Minimum Flips to Make a OR b Equal to c.
// Memory Usage: 6.8 MB, less than 100.00% of C online submissions for Minimum Flips to Make a OR b Equal to c.
// https://leetcode.com/submissions/detail/298406966/
