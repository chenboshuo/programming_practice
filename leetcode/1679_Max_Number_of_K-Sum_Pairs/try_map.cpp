#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxOperations(vector<int> &nums, int k) {
    unordered_map<int, int> memo;
    for (int num : nums) { memo[num]++; }

    int ans = 0;
    for (pair<int, int> it : memo) {
      int num = it.first;
      if (num <= k / 2) {
        if (memo.count(k - num)) {
          if (k - num == num) {
            ans += memo[num] / 2;
          } else {
            ans += min(memo[num], memo[k - num]);
          }
        }
      }
    }
    return ans;
  }
};

// 51 / 51 test cases passed.
// Status: Accepted
// Runtime: 296 ms
// Memory Usage: 68.1 MB
