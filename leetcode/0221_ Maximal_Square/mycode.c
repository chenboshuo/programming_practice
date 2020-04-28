#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int maximalSquare(char** matrix, int matrix_size, int* matrix_col_size) {
  if (!matrix_size) {
    return 0;
  }
  int side_length = 0;
  char memo[*matrix_col_size + 1];
  int pre = 0;
  memset(memo, 0, *matrix_col_size + 1);
  for (int i = 1; i < matrix_size + 1; ++i) {
    for (int j = 1; j < *matrix_col_size + 1; ++j) {
      int temp = memo[j];
      if (matrix[i - 1][j - 1] == '1') {
        memo[j] = min(min(memo[j], memo[j - 1]), pre) + 1;
        side_length = max(side_length, memo[j]);
      } else {
        memo[j] = 0;
      }
      pre = temp;
    }
  }

  return side_length * side_length;
}

// Runtime: 16 ms, faster than 88.75% of C online submissions for Maximal Square.
// Memory Usage: 7.1 MB, less than 100.00% of C online submissions for Maximal Square.