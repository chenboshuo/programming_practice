#include <stdlib.h>
void makeRotten(int **grid, int **dp, int row, int col, int i, int j,
                int distance) {
  if (i < 0 || i >= row || j < 0 || j >= col) return;

  if (grid[i][j] == 1 && dp[i][j] > distance) {
    dp[i][j] = distance;
    makeRotten(grid, dp, row, col, i - 1, j, distance + 1);
    makeRotten(grid, dp, row, col, i + 1, j, distance + 1);
    makeRotten(grid, dp, row, col, i, j - 1, distance + 1);
    makeRotten(grid, dp, row, col, i, j + 1, distance + 1);
  }
}

#define MAX_INT32 0x7FFFFFFF

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
  if (gridSize == 0) return NULL;

  int row = gridSize;
  int col = *gridColSize;

  int **dp = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++) {
    dp[i] = (int *)calloc(col, sizeof(int));
    for (int j = 0; j < col; j++) { dp[i][j] = MAX_INT32; }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 2) {
        makeRotten(grid, dp, row, col, i - 1, j, 1);
        makeRotten(grid, dp, row, col, i + 1, j, 1);
        makeRotten(grid, dp, row, col, i, j - 1, 1);
        makeRotten(grid, dp, row, col, i, j + 1, 1);
      }
    }
  }

  int days = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 1) {
        if (dp[i][j] == MAX_INT32) {
          days = -1;
          goto exit;
        } else if (days < dp[i][j]) {
          days = dp[i][j];
        }
      }
    }
  }

exit:
  for (int i = 0; i < row; i++) { free(dp[i]); }
  free(dp);
  return days;
}
