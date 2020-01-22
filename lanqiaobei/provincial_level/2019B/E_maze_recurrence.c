#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define ROW_SIZE 4
#define COLUMN_SIZE 3
// #define END '4'
#define VISITED '_'  // 记录已访问

char maze[ROW_SIZE][COLUMN_SIZE];  // 存储迷宫

bool search(int i, int j);  // 搜索函数

int main(int argc, char const *argv[]) {
  // 计时
  time_t start, end;
  start = time(NULL);


  // 从文件中读取其他位置的元素
  freopen("maze.txt", "r", stdin);

  for (int i = 0; i < ROW_SIZE; ++i) {
    for (int j = 0; j < COLUMN_SIZE; ++j) {
      maze[i][j] = getchar();
    }
    getchar();  // 处理行尾部回车
  }

  // 关文件
  fclose(stdin);

  // 定义出口
  // maze[ROW_SIZE-1][COLUMN_SIZE-1] = END;


  // 搜索
  search(0, 0);

  printf("\n");
  // 查看迷宫
  for (int i = 0; i < ROW_SIZE; ++i) {
    for (int j = 0; j < COLUMN_SIZE; ++j) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }

  // 计时
  end = time(NULL);
  printf("\nduration: %lf s\n", difftime(end, start));
  return 0;
}

bool search(int i, int j) {
  // 越界回退
  if((i<0) || (i>ROW_SIZE-1)
     || (j<0) || (j>COLUMN_SIZE-1)
     || (maze[i][j]== VISITED) || (maze[i][j] == '1')){
    printf("\b");
    // printf("-");
    return false;
  }


  // 标记访问
  maze[i][j] = VISITED;

  // 返回
  if(
    // (maze[i][j] == END)
    ((i == ROW_SIZE-1) && (j == COLUMN_SIZE-1))
    || (printf("D"), search(i+1, j)) // 向下搜索
    || (printf("L"), search(i,j-1)) // 向左搜索
    || (printf("R"), search(i,j+1)) // 向右搜索
    || (printf("U"), search(i-1, j)) // 向上搜索
  ){
    return true;
  }else{
    printf("\b");
    return false;
  }

}
// 000
// 100
// 001
// 000

// RDDDRUU
// __0
// 1_0
// __1
// ___
