#include <stdio.h>
#include <stdlib.h>
void print(int n){
  if (n == 1) {
    printf("%d ", 1);
    return;
  }
  print(n-1);
  printf("%d\n", n);
  printf("%d ", n);
  print(n-1);
}
int main(int argc, char const *argv[]) {
  int n;
  // scanf("%d", &n);
  n = 3;
  int *a = (int*) malloc(sizeof(int) * n);
  print(n);
  return 0;
}
/**
 * 失败的输出
 * 1 2
 * 2 1 3
 * 3 1 2
 * 2 1
 */
