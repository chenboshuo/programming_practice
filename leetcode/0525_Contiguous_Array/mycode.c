#define INIT -2

int findMaxLength(int* nums, int nums_size) {
  int d = 0;  // d = m-n, where m in the number of m, n is the number of n
  int memo[nums_size * 2 + 4];         // record the index that memo[index] == d
  int* p_memo = memo + nums_size + 2;  // enable the negatve subscription
  int max_length = 0;                  // storage the max length

  // initialize memo
  for (int i = 0; i < nums_size * 2 + 4; ++i) {
    memo[i] = INIT;
  }

  // manage the cases begin with 0th element
  p_memo[0] = -1;

  for (int i = 0; i < nums_size; ++i) {
    if (nums[i] == 1) {
      ++d;
    } else {
      --d;
    }

    if (p_memo[d] != INIT) {
      int length = i - p_memo[d];

      if (length > max_length) {
        max_length = length;
      }
    } else {
      p_memo[d] = i;
    }
  }
  // return d;
  return max_length;
}


// 555 / 555 test cases passed.
// Status: Accepted
// Runtime: 88 ms
// Memory Usage: 10 MB
// Submitted: 24 minutes ago