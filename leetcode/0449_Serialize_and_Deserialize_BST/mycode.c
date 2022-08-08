/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

char *serialize(struct TreeNode *root) {
  if (!root) { return NULL; }
  char *s = (char *)calloc(50000, sizeof(char));
  int top = 0;
  void encode(struct TreeNode * node) {
    s[top++] = node->val + '0';
    if (node->left || node->right) {
      s[top++] = '(';
      if (node->left) { encode(node->left); }
      s[top++] = ',';
      if (node->right) { encode(node->right); }
      s[top++] = ')';
    }
  }
  encode(root);
  return s;
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data) {
  if (!data) { return NULL; }
  if (*data == ',' || *data == ')') {
    ++data;
    return NULL;
  }
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = *(data++) - '0';
  if (*data == '(') {
    ++data;
    node->left = deserialize(data);
    node->right = deserialize(data);
  }
  return node;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
