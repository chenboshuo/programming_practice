/**
 * Definition for a binary tree node.
 */
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
    in_order_traversal(root, 0);
    for (pair<int, vector<int>> item : memo) { result.push_back(item.second); }
    return result;
  }

 private:
  map<int, vector<int>> memo;
  void in_order_traversal(TreeNode *node, int x) {
    if (!node) { return; }
    memo[x].push_back(node->val);
    in_order_traversal(node->left, x - 1);
    in_order_traversal(node->right, x + 1);
  }
};

// Submission Result: Wrong Answer
// Input:
// [0,8,1,null,null,3,2,null,4,5,null,null,7,6]
// Output:
// [[8],[0,3,6],[1,4,5],[7,2]]
// Expected:
// [[8],[0,3,6],[1,4,5],[2,7]]
