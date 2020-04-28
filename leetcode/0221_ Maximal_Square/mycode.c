#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrix_size, int* matrix_col_size) {
  if (!matrix_size) {
    return 0;
  }
  int side_length = 0;
  int memo[matrix_size + 1][*matrix_col_size + 1];
  for (int i = 0; i < matrix_size + 1; ++i) {
    for (int j = 0; j < *matrix_col_size + 1; ++j) {
      if (i == 0 || j == 0 || matrix[i - 1][j - 1] == '0') {
        memo[i][j] = 0;
      } else {
        memo[i][j] =
            min(min(memo[i - 1][j], memo[i][j - 1]), memo[i - 1][j - 1]) + 1;
        side_length = max(side_length, memo[i][j]);
      }
    }
  }

  return side_length * side_length;
}

// 69 / 69 test cases passed.
// Status: Accepted
// Runtime: 12 ms
// Memory Usage: 7.2 MB
