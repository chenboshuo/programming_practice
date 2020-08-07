/**
 * Definition for a binary tree node.
 */
#include <bits/stdc++.h>  // sort

#include <map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> result;

    in_order_traversal(root, 0, 0);

    for (pair<int, map<int, vector<int>>> item : memo) {
      vector<int> values;
      for (pair<int, vector<int>> y_val : item.second) {
        sort(y_val.second.begin(), y_val.second.end());
        for (int i : y_val.second) { values.push_back(i); }
      }
      result.push_back(values);
    }
    return result;
  }

 private:
  map<int, map<int, vector<int>>> memo;  // memo[x][y] = val
  void in_order_traversal(TreeNode *node, int x, int y) {
    if (!node) { return; }
    memo[x][y].push_back(node->val);
    in_order_traversal(node->left, x - 1, y + 1);
    in_order_traversal(node->right, x + 1, y + 1);
  }
};

// https://leetcode.com/submissions/detail/377366279/?from=/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3415/
// 30 / 30 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 15 MB
