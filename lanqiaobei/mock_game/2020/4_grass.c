/*
问题描述
　　小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
　　请告诉小明，k 个月后空地上哪些地方有草。
输入格式
　　输入的第一行包含两个整数 n, m。
　　接下来 n 行，每行包含 m
个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为
g，表示种了草。 　　接下来包含一个整数 k。 输出格式 　　输出 n 行，每行包含 m
个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为
g，表示长了草。
样例输入
4 5
.g...
.....
..g..
.....
2
样例输出
gggg.
gggg.
ggggg
.ggg.
评测用例规模与约定
　　对于 30% 的评测用例，2 <= n, m <= 20。
　　对于 70% 的评测用例，2 <= n, m <= 100。
　　对于所有评测用例，2 <= n, m <= 1000，1 <= k <= 1000。
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i, j;
  int m = 4;
  int n = 5;
  scanf("%d %d\n", &m, &n);

  int max_col = (1 << n) - 1;
  int grass[m + 1];  // bit 1 grass
  char c;
  int temp = 0, pre = 0;

  // input
  for (i = 0; i < m; ++i) {
    grass[i] = 0;
    for (j = 0; j < n; ++j) {
      c = getchar();
      grass[i] = (grass[i] << 1) + (c == 'g');
    }
    getchar();
    // printf("%d\n", grass[i]);
  }
  grass[m] = 0;

  int t;
  scanf("%d", &t);
  while (t--) {
    for (i = 0; i < m; ++i) {
      temp = grass[i];
      grass[i] |= pre;
      pre = temp;
      grass[i] |= (temp << 1);
      grass[i] |= (temp >> 1);
      grass[i] |= (grass[i + 1]);
      grass[i] &= max_col;  // handle overflow
      // printf("%d\n", grass[i]);
    }
  }

  for (i = 0; i < m; i++) {
    for (j = (1 << (n - 1)); j > 0; j >>= 1) {
      if (grass[i] & j) {
        printf("g");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  return 0;
}