#include <stdio.h> 
#define min(a,b) (a<b ? a:b)
int main(){
  int node_size,min_height;
  scanf("%d %d",&node_size,&min_height);
  long long memo[node_size+1][min_height+1];
  for(int hi=1;hi<=min_height;++hi){
    memo[0][hi] = 0;
    memo[1][hi] = 0;
  }
  memo[0][0] = 1;
  memo[1][0] = 1;
  memo[1][1] = 1;
  // for(int i=0;i<=n;++i){
  //   for(int j=0;j<=h;++j){
  //     printf("%lld ",memo[i][j]);
  //   }
  //   printf("\n");
  // }
  for(int n=2;n<=node_size;++n){
    for(int h=1;h<=min_height;++h){
      memo[n][h] = 0 ; 
      for(int i=0;i<n;++i){
        memo[n][h] += memo[i][h-1]*memo[n-1-i][0];
        memo[n][h] += memo[i][0]*memo[n-1-i][h-1];
        memo[n][h] -= memo[i][h-1]*memo[n-1-i][h-1];
      }
    }
    memo[n][0] = memo[n][1];
  }
  // for(int i=0;i<=n;++i){
  //   for(int j=0;j<=h;++j){
  //     printf("%lld ",memo[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%lld",memo[node_size][min_height]);
}
