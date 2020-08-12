
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binomial(int m, int n){
  long long int ans = 1;
  for(int i=1; i<= n;++i){
    ans *= (m--);
    ans /= i;
  }
  return ans;
}

int* getRow(int rowIndex, int* returnSize){
  *returnSize = rowIndex+1;
  int *ans = (int*)malloc(sizeof(int)* (*returnSize));
  int i = 0;
  int j = rowIndex;
  while(i<=j){
    ans[i] = ans[j] = binomial(rowIndex, i);
    ++i,--j;
  }
  return ans;
}