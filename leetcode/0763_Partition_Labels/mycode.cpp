#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> partitionLabels(string S) {
    map<char, pair<int, int>> char_span;
    map<char, bool> has_find;

    // record the letter's span
    for (int i = 0; i < S.size(); ++i) {
      if (has_find[S[i]]) {
        char_span[S[i]].second = max(char_span[S[i]].second, i);
      } else {
        char_span[S[i]].first = i;
        char_span[S[i]].second = i;
        has_find[S[i]] = true;
      }
    }

    // sort the spans
    vector<pair<int, int>> spans;
    for (pair<char, pair<int, int>> it : char_span) {
      spans.push_back(it.second);
    }
    sort(spans.begin(), spans.end());

    vector<int> ans;
    int begin = spans[0].first;
    int end = spans[0].second;
    for (pair<int, int> span : spans) {
      if (span.first > end) {
        ans.push_back(end - begin + 1);
        begin = span.first;
        end = span.second;
      } else {
        end = max(end, span.second);
      }
    }
    ans.push_back(end - begin + 1);
    return ans;
  }
};

// 116 / 116 test cases passed.
// Status: Accepted
// Runtime: 20 ms
// Memory Usage: 7.3 MB
// Submitted: 0 minutes ago
