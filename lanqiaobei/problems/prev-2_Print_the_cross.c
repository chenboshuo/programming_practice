/**
 * 试题 历届试题 打印十字图

资源限制
时间限制：1.0s   内存限制：256.0MB
问题描述
小明为某机构设计了一个十字型的徽标（并非红十字会啊），如下所示：

..$$$$$$$$$$$$$..
..$...........$..
$$$.$$$$$$$$$.$$$
$...$.......$...$
$.$$$.$$$$$.$$$.$
$.$...$...$...$.$
$.$.$$$.$.$$$.$.$
$.$.$...$...$.$.$
$.$.$.$$$$$.$.$.$
$.$.$...$...$.$.$
$.$.$$$.$.$$$.$.$
$.$...$...$...$.$
$.$$$.$$$$$.$$$.$
$...$.......$...$
$$$.$$$$$$$$$.$$$
..$...........$..
..$$$$$$$$$$$$$..
对方同时也需要在电脑dos窗口中以字符的形式输出该标志，并能任意控制层数。

输入格式
一个正整数 n (n<30) 表示要求打印图形的层数。
输出格式
对应包围层数的该标志。
样例输入1
1
样例输出1
..$$$$$..
..$...$..
$$$.$.$$$
$...$...$
$.$$$$$.$
$...$...$
$$$.$.$$$
..$...$..
..$$$$$..
样例输入2
3
样例输出2
..$$$$$$$$$$$$$..
..$...........$..
$$$.$$$$$$$$$.$$$
$...$.......$...$
$.$$$.$$$$$.$$$.$
$.$...$...$...$.$
$.$.$$$.$.$$$.$.$
$.$.$...$...$.$.$
$.$.$.$$$$$.$.$.$
$.$.$...$...$.$.$
$.$.$$$.$.$$$.$.$
$.$...$...$...$.$
$.$$$.$$$$$.$$$.$
$...$.......$...$
$$$.$$$$$$$$$.$$$
..$...........$..
..$$$$$$$$$$$$$..
提示
请仔细观察样例，尤其要注意句点的数量和输出位置。
 *
*/
#include <stdio.h>
#include <stdlib.h>

void draw_node(char **figure, int size, int x, int y) {
  int i;
  for (i = y; i < y + 3; ++i) {
    figure[x][i] = '$';
    figure[i][x] = '$';
  }
  for (i = x; i < size; ++i) {
    figure[i][y] = '$';
    figure[y][i] = '$';
  }
}

void draw(char **figure, int size) {
  int i, j;
  for (i = 2; i < size; i += 2) {
    draw_node(figure, size, i, i - 2);
  }
}

void print_line(char **figure, int size, int i) {
  int j;
  for (j = 0; j < size; j++) {
    printf("%c", figure[i][j]);
  }
  j--;
  while (j--) {
    printf("%c", figure[i][j]);
  }
  printf("\n");
}

void print(char **figure, int size) {
  int i;
  for (i = 0; i < size; ++i) {
    print_line(figure, size, i);
  }
  i--;
  while (i--) {
    print_line(figure, size, i);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int size = 2 * n + 3;
  int i, j;
  char **figure = (char **)malloc(sizeof(char *) * size);
  for (i = 0; i < size; ++i) {
    figure[i] = (char *)malloc(sizeof(char) * size);
    for (j = 0; j < size; ++j) {
      figure[i][j] = '.';
    }
  }
  draw(figure, size);

  print(figure, size);

  return 0;
}