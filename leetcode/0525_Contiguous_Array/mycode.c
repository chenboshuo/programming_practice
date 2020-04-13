#define INIT -2

int findMaxLength(int* nums, int nums_size) {
  int d = 0;  // d = m-n, where m in the number of m, n is the number of n
  int memo[nums_size + 2];  // record the index that memo[index] == d
  int* p_memo = memo + nums_size / 2 + 1;  // enable the negatve subscription
  int max_length = 0;                      // storage the max length

  // initialize memo
  for (int i = 0; i < nums_size + 2; ++i) {
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


// 6 / 555 test cases passed.
// Status: Runtime Error
// Submitted: 15 minutes ago
// Runtime Error Message:
// AddressSanitizer: dynamic-stack-buffer-overflow on address 0x7fff9e619908 at pc 0x000000401ae6 bp 0x7fff9e6198b0 sp 0x7fff9e6198a0
// Last executed input:
// [1,1,1,1,1,1,1,1]