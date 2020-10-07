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
  struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  newNode->val = val;
  newNode->left = NULL;
  newNode->right = NULL;

  if (root == NULL) return newNode;

  struct TreeNode *parent = NULL;
  struct TreeNode *current = root;
  while (current != NULL) {
    parent = current;
    if (val < current->val)
      current = current->left;
    else
      current = current->right;
  }

  if (val < parent->val)
    parent->left = newNode;
  else
    parent->right = newNode;

  return root;
}
