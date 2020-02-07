/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

struct row{
  int value;
  int index;
};

int comp(const void *a, const void *b){
  return ((struct row*)a)->value - ((struct row*)b)->value;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
  *returnSize = k;
  int *ans = (int*)malloc(sizeof(int)*k);
  struct row rows[matSize];

  // 计数
  for(int i=0;i < matSize; ++i){
    int score = 0;
    for(int j=0; j< *matColSize; ++j){
      if(mat[i][j]){
        ++score;
      }
    }
    rows[i].value = score;
    rows[i].index = i;
  }

  // 排序
  qsort(rows, matSize, sizeof(struct row), comp);

  // 答案
  for(int i=0; i<k;++i){
    ans[i] = rows[i].index;
  }
  return ans;
}

// Runtime: 12 ms, faster than 95.24% of C online submissions for The K Weakest Rows in a Matrix.
// Memory Usage: 8.1 MB, less than 100.00% of C online submissions for The K Weakest Rows in a Matrix.
