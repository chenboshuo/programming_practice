#define FRESH 1
#define ROTTEN 2
#define VISITING 3
#define EMPTY 0
#define max(a, b) ((a) > (b) ? (a) : (b))

int orangesRotting(int **grid, int gridSize, int *gridColSize) {
  void rot(int i, int j, int rotten_time) {
    if (i < 0 || i >= gridSize || j < 0 || j >= *gridColSize ||
        grid[i][j] == EMPTY || grid[i][j] == VISITING ||
        (grid[i][j] < 0 && grid[i][j] > rotten_time)) {
      return;
    }
    if (grid[i][j] == FRESH) {
      grid[i][j] = rotten_time;
      // ++rotten;
    } else if (grid[i][j] < 0) {
      grid[i][j] = max(rotten_time, grid[i][j]);
    } else {  // the orange has rotten
      grid[i][j] = VISITING;
    }

    rot(i + 1, j, rotten_time - 1);
    rot(i - 1, j, rotten_time - 1);
    rot(i, j + 1, rotten_time - 1);
    rot(i, j - 1, rotten_time - 1);
    if (grid[i][j] == VISITING) {  // restore
      grid[i][j] = ROTTEN;
    }
  }

  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < *gridColSize; ++j) {
      if (grid[i][j] == ROTTEN) { rot(i, j, 0); }
    }
  }

  int max_minute = 0;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < *gridColSize; ++j) {
      if (grid[i][j] == FRESH) { return -1; }
      max_minute = max(max_minute, -grid[i][j]);
    }
  }

  return max_minute;
}

// 303 / 303 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 5.5 MB
// Submitted: 0 minutes ago
