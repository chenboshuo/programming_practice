#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    map<char, vector<int>> alphas;
    for (int i = 0; i < s.length(); ++i) { alphas[s[i]].push_back(i); }
    vector<bool> remains(s.length());
    int loc = 0;
    for (pair<int, vector<int>> item : alphas) {
      // int front_loc = item.second.front();
      // if (loc < front_loc) {
      //   loc = front_loc;
      //   remains[front_loc] = true;
      // }
      vector<int> locs = item.second;
      if (locs.size() == 1) {
        remains[locs[0]] = true;
        loc = max(loc, locs[0]);
      }

      // try to find minimum i such that locs[i] > loc
      int i;
      for (i = 0; i < locs.size(); ++i) {
        if (locs[i] > loc) {
          remains[locs[i]] = true;
          loc = i;
          break;
        }
      }
      // not found
      if (i == locs.size()) {
        loc = locs.size() - 1;
        remains[locs.back()] = true;
      }
    }
    string ans;
    for (int i = 0; i < remains.size(); ++i) {
      if (remains[i] == true) { ans.push_back(s[i]); }
    }
    return ans;
  }
};
