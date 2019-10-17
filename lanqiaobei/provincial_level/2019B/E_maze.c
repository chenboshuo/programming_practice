#include <stdio.h>
#include <time.h>

#define LINESIZE 30
#define COLUMNSIZE 50
#define PATHSIZE 50000000
#define VISITED '3'  // 记录已访问

char path[PATHSIZE];                      // 存储迷宫路径
int pp = 0;                               // path的角标
char maze[LINESIZE + 2][COLUMNSIZE + 2];  // 存储迷宫

void search(int i, int j);  // 搜索函数
void back(int i, int j);    // 发现无路可走,回退

int main(int argc, char const *argv[]) {
  // 计时
  time_t start, end;
  start = time(NULL);

  // 迷宫边框初始化为'1'
  for (int i = 0; i < LINESIZE + 2; ++i) {
    maze[i][COLUMNSIZE + 1] = '1';
    maze[i][0] = '1';
  }
  for (int j = 0; j < COLUMNSIZE + 2; ++j) {
    maze[0][j] = '1';
    maze[LINESIZE + 1][j] = '1';
  }

  // 从文件中读取其他位置的元素
  freopen("maze.txt", "r", stdin);

  for (int i = 1; i < LINESIZE + 1; ++i) {
    for (int j = 1; j < COLUMNSIZE + 1; ++j) {
      maze[i][j] = getchar();
    }
    getchar();  // 处理行尾部回车
  }

  // 关文件
  fclose(stdin);

  // 搜索
  search(1, 1);

  // 查看迷宫
  // for (int i = 0; i < LINESIZE + 2; ++i) {
  //   for (int j = 0; j < COLUMNSIZE + 2; ++j) {
  //     printf("%c", maze[i][j]);
  //   }
  //   printf("\n");
  // }

  // 打印
  for (int i = 0; i < pp; ++i) {
    printf("%c", path[i]);
  }

  // 计时
  end = time(NULL);
  printf("\nduration: %lf s\n", difftime(end, start));
  return 0;
}

void back(int i, int j) {
  switch (path[--pp]) {
    case 'D':
      search(i - 1, j);
      return;
    case 'L':
      search(i, j + 1);
      return;
    case 'R':
      search(i, j - 1);
      return;
    case 'U':
      search(i + 1, j);
      return;
  }
}

void search(int i, int j) {
  if ((i == LINESIZE - 2) && (j == COLUMNSIZE - 2)) {  // 到达终点
    return;
  }

  // 标记访问
  maze[i][j] = VISITED;
  // 按 D,L,R,U方向寻找
  if (maze[i + 1][j] == '0') {  // 向下搜索
    path[pp++] = 'D';
    search(i + 1, j);
    return;
  }
  if (maze[i][j - 1] == '0') {  // 向左搜索
    path[pp++] = 'L';
    search(i, j - 1);
    return;
  }
  if (maze[i][j + 1] == '0') {
    path[pp++] = 'R';
    search(i, j + 1);
    return;
  }
  if (maze[i - 1][j] == '0') {
    path[pp++] = 'U';
    search(i - 1, j);
    return;
  }
  // 无路可走,回退
  back(i, j);
  return;
}
