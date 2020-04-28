#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximalSquare(char** matrix, int matrix_size, int* matrix_col_size) {
  int memo[matrix_size + 1][*matrix_col_size + 1];
  for (int i = 0; i < matrix_size + 1; ++i) {
    for (int j = 0; j < *matrix_col_size + 1; ++j) {
      if (i == 0 || j == 0) {
        memo[i][j] = 0;
      } else if (matrix[i - 1][j - 1] == '1' &&
                 memo[i][j - 1] == memo[i - 1][j] &&
                 (i == 1 || matrix[i - 2][i - 1] == '1') &&
                 (j == 1 || matrix[i - 1][i - 2] == '1')) {
        memo[i][j] = memo[i - 1][j - 1] + 1;
      } else {
        memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
      }
    }
  }
  int side_length = memo[matrix_size][*matrix_col_size];
  return side_length * side_length;
}