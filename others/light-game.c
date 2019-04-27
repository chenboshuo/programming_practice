/*
 * 开灯游戏
 * 问题描述：
 * 有n盏灯，放在一排，从1到n依次顺序编号。有m个人也从1到m依次顺序编号。
 * 第1个人（1号）将灯全部关闭；
 * 第2个人（2号）将凡是2的倍数的灯打开；
 * 第3个人（3号）将凡是3的倍数的灯作相反处理
 * （该灯如是打开的，则将它关闭；如是关闭的，则将它打开）。
 * 以后的人都和3号一样，将凡是自己编号倍数的灯作相反处理。
 * 试计算当第m个人操作后，哪几盏灯是亮的？
 * 输入输出要求：
 * 输入：从键盘输入n、m的值。（n、m均为正整数，且n>=m）
 * 输出：在同一行输出亮着的灯的编号。（没有灯亮则输出“NO”）
 * 输入输出样例：
 * 输入：5 3
 * 输出：2 3 4
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  int n;  // n盏灯
  int m;  // m个人
  int light_on = 0; // 记录有没有灯
  scanf("%d %d", &n, &m);
  int *a = (int *)malloc(sizeof(int) * (n+1));
  for(int i = 1; i <= n; ++i){
    a[i] = -1;  // 一号把灯全部关闭
    for(int j = 2; j <= m; ++j){  // 从2号开始
      if (i % j == 0) {
        a[i] *= -1;
      }
    }
    if(a[i] == 1){
      light_on = 1;
      printf("%d ", i);
    }
  }
  if (!light_on) {
    printf("No\n");
  }
  return 0;
}
/**
 * 输入：5 3
 * 输出：2 3 4
 * Finished in 4 ms
 *
 * 输入: 5000 3000
 * Finished in 56 ms
 */
