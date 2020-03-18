// reference
// https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem
#define max(a, b) (((a) > (b)) ? (a) : (b))

void init(int* ones) {
  ones[0] = 0;
  for (int i = 1; i < 512; ++i) {
    ones[i] = ones[i >> 1] + (i & 1);
  }
}

int maxStudents(char** seats, int seatsSize, int* seatsColSize) {
  int count_ones[512];  // array of the one's in the bits
  init(count_ones);

  // caulate the valid seats
  int valid[seatsSize];  // bit 1: empty seats
  for (int i = 0; i < seatsSize; ++i) {
    int cur = 0;
    for (int j = 0; j < *seatsColSize; ++j) {
      cur = (cur << 1) + (seats[i][j] == '.');
    }
    valid[i] = cur;
  }

  // initialize dp array
  int cases_size = (1 << *seatsColSize) + 1;
  int dp[seatsSize + 1][cases_size];
  for (int i = 0; i < seatsSize + 1; ++i) {
    for (int j = 0; j < cases_size; ++j) {
      dp[i][j] = -1;
    }
  }
  dp[0][0] = 0;

  // find cases
  for (int i = 1; i <= seatsSize; ++i) {
    for (int cur = 0; cur < cases_size; ++cur) {
      if (!(cur & (cur >> 1))  // no adjacent
          && ((cur & valid[i - 1]) == cur)) {
        for (int pre = 0; pre < cases_size; ++pre) {
          if (dp[i - 1][pre] != -1 &&     // pre is valid
              ((pre << 1) & cur) == 0 &&  // no upper right
              ((pre >> 1) & cur) == 0     // no upper left
          ) {
            dp[i][cur] = max(dp[i][cur], dp[i - 1][pre] + count_ones[cur]);
          }
        }
      }
    }
  }

  // find max in dp[seatsSize]
  int the_max = 0;
  for (int i = 0; i < cases_size; ++i) {
    if (dp[seatsSize][i] > the_max) {
      the_max = dp[seatsSize][i];
    }
  }
  return the_max;
}
// https://leetcode.com/submissions/detail/313559250/
// Runtime: 4 ms, faster than 50.00% of C online submissions for Maximum
// Students Taking Exam. Memory Usage: 5.2 MB, less than 100.00% of C online
// submissions for Maximum Students Taking Exam.