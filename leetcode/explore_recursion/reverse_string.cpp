/**
 * Reverse String
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 */
#include <stdio.h>
void reverseString(char* s, int sSize) {
  char temp;
  if (sSize == 2) {
    temp = *s;
    *s = *(s+1);
    *(s+1) = temp;
    return;
  }else if(sSize == 3){
    temp = *s;
    *s = *(s+2);
    *(s+2) = temp;
    return;
  }
  reverseString(s+1,sSize-1);
}
int main(int argc, char const *argv[]) {
  char a[] = "hello";
  reverseString(a,5);
  printf("%s\n", a);
  return 0;
}
// output
// heoll
