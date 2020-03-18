

int countNegatives(int **grid, int gridSize, int *gridColSize) {
  int count = 0;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = *gridColSize - 1; j > -1; --j) {
      if (grid[i][j] < 0) {
        ++count;
      } else {
        break;
      }
    }
  }
  return count;
}

// https://leetcode.com/submissions/detail/313568619/
// Runtime: 16 ms, faster than 96.04% of C online submissions for Count Negative
// Numbers in a Sorted Matrix. Memory Usage: 6.7 MB, less than 100.00% of C
// online submissions for Count Negative Numbers in a Sorted Matrix.