#include <map>
#include <vector>
using namespace std;
class Solution {
 public:
  int findPairs(vector<int> &nums, int k) {
    map<int, int> match;
    int count = 0;

    // create the map
    for(int x:nums){
      if(match[x] && k == 0){
        ++count;
        match[x] = 0;
      }
      match[x-k] = 1;
    }

    for(int x: nums){
      if(match[x] && k!=0){
        ++count;
        match[x] = 0;
      }
    }

    return count;
  }
};

// [1,1,1,1,1]
// 0
