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
        for (int i : y_val.second) { values.push_back(i); }
      }
      sort(values.begin(), values.end());
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

// [0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7]
// Output:
// [[7,9],[5,6],[0,2,4],[1,3],[8]]
// Expected:
// [[9,7],[5,6],[0,2,4],[1,3],[8]]
