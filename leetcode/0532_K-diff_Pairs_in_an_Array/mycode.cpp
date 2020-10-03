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
      match[x-k] += 1;
    }

    if(k != 0){
      for(int x: nums){
        if(match[x]){
          ++count;
          match[x] = 0;
        }
      }
    }else{
      for(int x:nums){
        if(match[x] > 1){
          ++count;
          match[x] = 0;
        }
      }
    }


    return count;
  }
};

// https://leetcode.com/submissions/detail/403889457/?from=/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3482/
// Runtime: 92 ms
// Memory Usage: 14.8 MB
