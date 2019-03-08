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

reference:https://leetcode.com/problems/reverse-integer/discuss/4109/A-simple-C-solution-with-5ms
 */
#include <climits>
#include <stdio.h>
int reverse(int x) {
    long long out = 0;
    do{
        out = 10* out +x % 10;
        x /= 10;
    }while(x);
    return(out > INT_MAX || out < INT_MIN) ? 0:(int) out;
}
int main(int argc, char const *argv[]) {
  int test = 1534236469;
  printf("%d\n", reverse(test));
  return 0;
}
// output 0
// Runtime: 12 ms, faster than 87.26% of C online submissions for Reverse Integer.
// Memory Usage: 12.4 MB, less than 80.42% of C online submissions for Reverse Integer.
