/*
【例9.2】数字金字塔
时间限制: 1 Sec  内存限制: 128 MB
提交: 5  解决: 3
[提交] [状态] [讨论版] [命题人:admin]
题目描述
观察下面的数字金字塔。写一个程序查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以从当前点走到左下方的点也可以到达右下方的点。

在上面的样例中,从13到8到26到15到24的路径产生了最大的和86。

输入
第一个行包含R(1≤ R≤1000)，表示行的数目。
后面每行为这个数字金字塔特定行包含的整数。
所有的被供应的整数是非负的且不大于100。

输出
单独的一行，包含那个可能得到的最大的和。

样例输入
5
13
11 8
12 7  26
6  14 15 8
12 7  13 24 11

样例输出
86
 */
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (a) > (b) ? (a) : (b)  // comment

int main(int argc, char const *argv[]) {
  freopen("input", "r", stdin);
  int sum = 0;
  int line;
  scanf("%d", &line);
  int **a = (int**)malloc(sizeof(int*) * line);
  int x;  // 代表当前选定数组的下标

  for(int i = 0; i < line; ++i){
    a[i] = (int *)malloc(sizeof(int) * (i+1));
    for(int j = 0; j < i+1; ++j){
      scanf("%d", a[i] + j);
    }
    if (i == 0) {
      sum += a[0][0];
      x = 0;
    }else{
      if (a[i][x] > a[i][x+1]) {
        sum += a[i][x];
        printf("%d\n", a[i][x]);
      } else {
        sum += a[i][x+1];
        printf("%d\n", a[i][x+1]);
        ++x;
      }
    }
  }

  printf("%d\n", sum);
  return 0;
}
