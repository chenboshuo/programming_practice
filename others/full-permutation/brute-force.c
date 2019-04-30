#include <stdio.h>
#include <stdlib.h>
int *p;
/**
 * 代替for循环
 * @param a   目标数组
 * @param len 数组长度
 * @param n   全排列的目标值
 */
void array(int* a, int len,int n){
  if (len == 0) {
    for(int i = 0; i < n; ++i){
      printf("%d ", p[i]);
    }
    return;
  }
  for(*a = 1; *a <= n; (*a)++){
    array(a+1,len-1,n);
  }
  return;
}
int main(int argc, char const *argv[]) {
  int n;
  // scanf("%d", &n);
  n = 2;
  int *a = (int*) malloc(sizeof(int) * (n + 1));
  p = a;
  array(a,n,n);
  return 0;
}
/**
 * 失败的输出
 * 1 2
 * 2 1 3
 * 3 1 2
 * 2 1
 */
