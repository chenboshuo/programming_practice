
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
  while(i<j){
    ans[i] = ans[j] = (factorials(rowIndex)/ factorials(i)) / factorials(j);
    ++i,--j;
  }
  return ans;
}

// Input:
// 0
// Output:
// [-1094795586]
// Expected:
// [1]