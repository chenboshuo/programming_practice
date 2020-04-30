/*
问题描述
　　对于一个 n 行 m
列的表格，我们可以使用螺旋的方式给表格依次填上正整数，我们称填好的表格为一个螺旋矩阵。
　　例如，一个 4 行 5 列的螺旋矩阵如下：
　　1 2 3 4 5
　　14 15 16 17 6
　　13 20 19 18 7
　　12 11 10 9 8
输入格式
　　输入的第一行包含两个整数 n, m，分别表示螺旋矩阵的行数和列数。
　　第二行包含两个整数 r, c，表示要求的行号和列号。
输出格式
　　输出一个整数，表示螺旋矩阵中第 r 行第 c 列的元素的值。
样例输入
4 5
2 2
样例输出
15
评测用例规模与约定
　　对于 30% 的评测用例，2 <= n, m <= 20。
　　对于 70% 的评测用例，2 <= n, m <= 100。
　　对于所有评测用例，2 <= n, m <= 1000，1 <= r <= n，1 <= c <= m。
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main(int argc, char const* argv[]) {
  int ln_size;
  int col_size;
  scanf("%d %d", &ln_size, &col_size);

  int** matrix = (int**)calloc(ln_size, sizeof(int*));
  int i;

  for (i = 0; i < ln_size; ++i) {
    matrix[i] = (int*)calloc(col_size, sizeof(int));
  }
  // int matrix[ln_size][col_size];
  i = 0;
  int j = 0;
  int num = 1;
  void fill(int increase_i, int increase_j) {
    bool has_move = false;
    while (i > -1 && i < ln_size && j > -1 && j < col_size &&
           matrix[i][j] == 0) {
      matrix[i][j] = num;
      i += increase_i;
      j += increase_j;
      ++(num);
      has_move = true;
    }
    if (has_move) {
      i -= increase_i;
      j -= increase_j;
      // --num;
    }
  }

  int times = min(ln_size, col_size) / 2 + 1;
  while (times--) {
    fill(0, 1);
    ++i;
    fill(1, 0);
    --j;
    fill(0, -1);
    --i;
    fill(-1, 0);
    ++j;
  }

  // for (size_t ii = 0; ii < ln_size; ++ii){
  //   for (size_t jj = 0;jj<col_size;++jj){
  //     printf("%d\t",matrix[ii][jj]);
  //   }
  //   printf("\n");
  // }

  int get_i, get_j;
  scanf("%d %d", &get_i, &get_j);
  printf("%d\n", matrix[get_i - 1][get_j - 1]);

  return 0;
}
