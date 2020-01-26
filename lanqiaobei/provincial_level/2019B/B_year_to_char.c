#include <stdlib.h>
#include <stdio.h>

// 10 进制转类 26 进制 (AA) = 1*26 + 1
// int main(int argc, char *argv[]){
//   int a = 2019;
//   while(a){
//     printf("%c", a%26 + 'A' -1);
//     a /= 26;
//   }
//   printf("\n");
// }

// QYB
// 注意倒序

void year_to_char(int a){
  if (a == 0) return;
  year_to_char(a/26);
  printf("%c", a%26 + 'A' -1);
}

int main(int argc, char *argv[]){
  year_to_char(2019);
  printf("\n");
}


// BYQ


