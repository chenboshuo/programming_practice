// reference
// https://leetcode.com/problems/remove-covered-intervals/discuss/451277/JavaC%2B%2BPython-Sort-Solution
#include <algorithm>
// #include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    int count = 0;
    int left = -1;
    int right = -1;
    // map<int, int> interval_end;
    for (vector<int> interval : intervals) {
      if (interval[0] > left && interval[1] > right) {
        left = interval[0];
        ++count;
      }
      right = max(right, interval[1]);
    }
    return count;
  }
};

// Runtime: 60 ms, faster than 51.88% of C++ online submissions for Remove
// Covered Intervals. Memory Usage: 12.3 MB, less than 29.35% of C++ online
// submissions for Remove Covered Intervals.
