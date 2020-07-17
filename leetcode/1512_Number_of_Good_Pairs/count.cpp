#include <unordered_map>
using namespace std;
class Solution {
 public:
  int numIdenticalPairs(vector<int> &nums) {
    int out = 0;
    unordered_map<int, int> count;
    for (int num : nums) { out += count[num]++; }
    return out;
  }
};
