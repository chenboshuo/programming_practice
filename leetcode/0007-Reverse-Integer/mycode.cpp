/**
 * 7. Reverse Integer
Easy

1958

2890

Favorite

Share
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Accepted
619,510
Submissions
2,462,844
 */
#include <stdio.h>
int reverse(int x) {
    int out = 0;
    do{
        out += x % 10;
        out *= 10;
    }while(x /= 10);
    if(x >=0) return out/10;
    else return out/10*-1;
}
int main(int argc, char const *argv[]) {
  int test = 1534236469;
  printf("%d\n", reverse(test));
  return 0;
}
// 没有考虑溢出的情况
