#define INIT -2
#define max(a, b) ((a) > (b) ? (a) : (b))

int findMaxLength(int *nums, int nums_size) {
  int d = 0;  // d = m-n, where m in the number of m, n is the number of n
  int memo[nums_size * 2 + 1];     // record the index that memo[index] == d
  int *p_memo = memo + nums_size;  // enable the negative subscription
  int max_length = 0;              // storage the max length

  // initialize memo
  for (int i = 0; i < nums_size * 2 + 1; ++i) { memo[i] = INIT; }

  // manage the cases begin with 0th element
  p_memo[0] = -1;

  for (int i = 0; i < nums_size; ++i) {
    if (nums[i] == 1) {
      ++d;
    } else {
      --d;
    }

    if (p_memo[d] != INIT) {
      max_length = max(i - p_memo[d], max_length);
    } else {
      p_memo[d] = i;
    }
  }
  return max_length;
}

// /Runtime: 84 ms, faster than 94.08% of C online submissions for Contiguous
// Array. Memory Usage: 9.9 MB, less than 100.00% of C online submissions for
// Contiguous Array.issions for Contiguous Array.
