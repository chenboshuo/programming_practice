#define max(a, b) (((a) > (b)) ? (a) : (b))

int maximalSquare(char** matrix, int matrix_size, int* matrix_col_size) {
  if (!matrix_size) {
    return 0;
  }
  int memo[matrix_size + 1][*matrix_col_size + 1];
  for (int i = 0; i < matrix_size + 1; ++i) {
    for (int j = 0; j < *matrix_col_size + 1; ++j) {
      if (i == 0 || j == 0) {
        memo[i][j] = 0;
      } else if (matrix[i - 1][j - 1] == '1' &&
                 memo[i][j - 1] == memo[i - 1][j] &&
                 (memo[i][j - 1] == 0 || (matrix[i - 2][i - 1] == '1') &&
                                             (matrix[i - 1][i - 2] == '1'))) {
        memo[i][j] = memo[i - 1][j - 1] + 1;
      } else {
        memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
      }
    }
  }
  int side_length = memo[matrix_size][*matrix_col_size];
  return side_length * side_length;
}

// 20 / 69 test cases passed.
// Status: Runtime Error
// Submitted: 5 hours, 57 minutes ago
// Runtime Error Message:
// AddressSanitizer: heap-buffer-overflow on address 0x602000000c94 at pc 0x000000401f9c bp 0x7ffe5be22a20 sp 0x7ffe5be22a10
// Last executed input:
// [["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]
