
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long int factorials(int x){
  long long int ans = 1;
  for(int i=1;i<=x;++i){
    ans *= i;
  }
  return ans;
}

int* getRow(int rowIndex, int* returnSize){
  *returnSize = rowIndex+1;
  int *ans = (int*)malloc(sizeof(int)* (*returnSize));
  int i = 0;
  int j = rowIndex;
  while(i<=j){
    ans[i] = ans[j] = (factorials(rowIndex)/ factorials(i)) / factorials(j);
    ++i,--j;
  }
  return ans;
}

// Runtime Error Message:
// Line 4: Char 9: runtime error: signed integer overflow: 2432902008176640000 * 21 cannot be represented in type 'long long int' (solution.c)
// Last executed input:
// 21