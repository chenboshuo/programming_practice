// reference https://leetcode.com/problems/minimum-cost-for-tickets/discuss/226659/Two-DP-solutions-with-pictures
// reference https://leetcode.com/problems/minimum-cost-for-tickets/discuss/228421/Python-solution
// reference https://leetcode.com/problems/minimum-cost-for-tickets/discuss/630868/explanation-from-someone-who-took-2-hours-to-solve
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define max(a,b) (((a)>(b))? (a): (b))
#define min(a,b) (((a)<(b))? (a): (b))
int mincostTickets(int* days, 
    int daysSize, 
    int* costs, 
    int costsSize){
  int least_day = days[daysSize-1];
  bool* is_in_plan = calloc(least_day+1,sizeof(bool));
  for(int i=0;i<daysSize;++i){
    is_in_plan[days[i]] = true;
  }

  int* dp = calloc(least_day+1,sizeof(int));
  

  for(int i=1;i<=least_day;++i){
    if(!is_in_plan[i]){
      dp[i] = dp[i-1];
    }else{
      dp[i] = min(
                min(
                  dp[max(0,i-1)] + costs[0],
                  dp[max(0,i-7)]+ costs[1]
                ),
                dp[max(0,i-30)]+ costs[2]
              );     
    }

  }
  return dp[least_day];
}