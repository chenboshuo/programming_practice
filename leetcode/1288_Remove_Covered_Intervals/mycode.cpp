#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    map<int, int> interval_end;
    for (vector<int> interval : intervals) {
      int cur_begin = interval[0];
      int cur_end = interval[1];
      bool need_add = true;

      for (pair<int, int> item : interval_end) {
        int begin = item.first;
        int end = item.second;
        if (cur_end <= end) { need_add = false; }
        if (cur_begin == begin && cur_end >= end) { interval_end.erase(begin); }
      }
      if (need_add) {
        // interval_end[cur_begin] = interval_end[cur_end];
        interval_end.insert(pair<int, int>(cur_begin, cur_end));
      }
    }
    return interval_end.size();
  }
};

// 32 / 32 test cases passed.
// Status: Accepted
// Runtime: 52 ms(66.9%)
// Memory Usage: 12.3 MB
// Submitted: 0 minutes ago
