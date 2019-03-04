/**
 * You are given array a1,a2,…,ana1,a2,…,an.
 *  Find the subsegment al,al+1,…,aral,al+1,…,ar
 *   (1≤l≤r≤n1≤l≤r≤n) with maximum arithmetic mean
 * 1/(r−l+1)∑_{i=l}^{r} =ai (in floating-point numbers, i.e. without any rounding).
 * If there are many such subsegments find the longest one.
 *
 * Input
 * The first line contains single integer nn (1≤n≤1051≤n≤105)
 *  — length of the array a.
 *  The second line contains nn integers a1,a2,…,ana1,a2,…,an
 * (0≤ai≤1090≤ai≤109) — the array a.
 *
 * output
 *
 * Print the single integer
 *  — the length of the longest subsegment with maximum possible arithmetic mean.
 *
 * example input
 *
 * 5
 * 6 1 6 6 0
 *
 * Example output
 * 2
 *
 * Note
 *
 * The subsegment [3,4] is the longest among all subsegments with
 *  maximum arithmetic mean.
 *
 * test
 * https://vjudge.net/contest/285968#problem/B

 */
#include <stdio.h>

float arithmetic_mean(int a[], int l, int r){
  int sum = 0;
  for (int i = l; i < r+1; i++) {
    sum += a[i];
  }
  return 1.0/(r-l+1)*sum;
}

int main(int argc, char const *argv[]) {
  // FILE *fp = fopen("2_in.txt","r");
  int len;
  int r,l;
  scanf("%d",&len);
  int a[len];
  for (int i = 0; i < len; i++) {
    scanf("%d", a+i);
  }
  float max=0;
  int max_len = 0;
  float m;

  for (l = 0; l < len; l++) {
    for (r = l; r < len ; r++) {
      m = arithmetic_mean(a,l,r);
      if(m > max){
        max = m;
        max_len = r-l+1;
      }else if(m == max){
        int _ = r-l+1;
        if (_ > max_len) {
          max_len = _;
        }
      }
    }
  }
  printf("%d\n",max_len);

  return 0;
}
