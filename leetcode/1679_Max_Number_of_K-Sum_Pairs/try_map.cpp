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
        if (memo[k - num] > 0) {
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

// Input:
// [73,74,74,71,68,67,45,1,24,2,26,48,82,82,28,60,19,36,26,9,12,83,1,86,18,78,14,66,20,26,4,80,44,35,53,48,74,25,75,47,31,20,59,10,35,24,26,3,48,69,78,43,12,86,37,49,1,90,20,35,58,20,2,20,16,18,88,25,44,63,12,16,64,41,86,87,2,23,14,63,43,60,47,7,23,11,64,53,71,78,82,56,65,25,27,52,89,68,63,14,48]
// 44
// Output:
// 4
// Expected:
// 11
