/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
#include <stdlib.h>

struct TreeNode *insertIntoBST(struct TreeNode *root, int val) {
  if (!root) {
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  if (val > root->val) {
    root->right = insertIntoBST(root->right, val);  // change right
  } else {
    root->left = insertIntoBST(root->left, val);
  }
  return root;
}

// https://leetcode.com/submissions/detail/405471062/
// 35 / 35 test cases passed.
// Status: Accepted
// Runtime: 48 ms
// Memory Usage: 22.9 MB
// Submitted: 0 minutes ago
