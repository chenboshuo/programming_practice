#include <stdio.h>
/**
 * 类似斐波那契数列 an = a_(n-1) + a_(n-2) + a_(n-3)
 * 注意, n > 3
 * @param  n 项数
 * @return   第n项的后4位
 */
int fib(int n){
  int a=1,b=1,c=1,cur;
  n-=3;
  while(n--){
    cur = (a+b+c) % 10000;
    // cur = ((a+b+c) & 16383);
    a = b;
    b = c;
    c = cur;
  }
  return cur;

}


int main(int argc, char const *argv[]){
  printf("%d\n", fib(4));
  printf("%d\n", fib(20190324));
}
