class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string prefix = "";
    for (int idx = 0; strs.size() > 0; prefix += strs[0][idx], idx++)
      for (int i = 0; i < strs.size(); i++)
        if (idx >= strs[i].size() ||
            (i > 0 && strs[i][idx] != strs[i - 1][idx]))
          return prefix;
    return prefix;
  }
};

// https://leetcode.com/problems/longest-common-prefix/discuss/6926/Accepted-c%2B%2B-6-lines-4ms
