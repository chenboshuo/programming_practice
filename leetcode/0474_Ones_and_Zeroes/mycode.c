#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
int findMaxForm(char **strs, int strsSize, int m, int n) {
  int pre[m + 1][n + 1];
  int cur[m + 1][n + 1];

  // initize memo
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      pre[i][j] = 0;
      cur[i][j] = 0;
    }
  }

  for (int i = 1; i <= strsSize; ++i) {
    // count the number of 0
    int zero_num = 0, one_num = 0;
    for (int s = 0; strs[i - 1][s]; ++s) {
      if (strs[i - 1][s] == 0) {
        ++zero_num;
      } else {
        ++one_num;
      }
    }

    // mnage can't choose part
    int zero_limit = min(zero_num, m + 1);
    for (int j = 0; j < zero_limit; ++j) {
      for (int k = 0; k < n; ++k) { cur[i][j] = pre[i][j]; }
    }

    for (int j = zero_limit; j < m; ++j) {
      int one_limit = min(one_num, n + 1);
      for (int k = 0; k < one_limit; ++k) { cur[i][j] = pre[i][j]; };
      for (int k = one_limit; k < n; ++k) {
        cur[i][j] = max(pre[k - zero_num][j - one_num] + 1, pre[k][j]);
      }
    }
    void *temp = &pre;
    **pre = &cur;
    **cur = temp;
  }
  return cur[m][n];
}
