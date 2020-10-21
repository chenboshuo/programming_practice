/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
#include <stdlib.h>

struct Node {
  int val;
  int numNeighbors;
  struct Node **neighbors;
};

struct Node *_cloneGraph(struct Node *s, struct Node **memo) {
  if (!s) { return NULL; }
  if (memo[s->val]) { return memo[s->val]; }
  struct Node *copy = (struct Node *)malloc(sizeof(struct Node));
  copy->val = s->val;
  memo[s->val] = copy;
  copy->numNeighbors = s->numNeighbors;
  copy->neighbors =
      (struct Node **)calloc(s->numNeighbors, sizeof(struct Node *));
  for (int i = 0; i < copy->numNeighbors; ++i) {
    copy->neighbors[i] = _cloneGraph(s->neighbors[i], memo);
  }

  return copy;
}

struct Node *cloneGraph(struct Node *s) {
  struct Node **memo = (struct Node **)calloc(101, sizeof(struct Node *));
  return _cloneGraph(s, memo);
}

// 22 / 22 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 7.1 MB
