/*
问题描述
　　如果一个序列的奇数项都比前一项大，偶数项都比前一项小，则称为一个摆动序列。即
a[2i]<a[2i-1], a[2i+1]>a[2i]。 　　小明想知道，长度为 m，每个数都是 1 到 n
之间的正整数的摆动序列一共有多少个。 输入格式 　　输入一行包含两个整数 m，n。
输出格式
　　输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
样例输入
3 4
样例输出
14
样例说明
　　以下是符合要求的摆动序列：
　　2 1 2
　　2 1 3
　　2 1 4
　　3 1 2
　　3 1 3
　　3 1 4
　　3 2 3
　　3 2 4
　　4 1 2
　　4 1 3
　　4 1 4
　　4 2 3
　　4 2 4
　　4 3 4
评测用例规模与约定
　　对于 20% 的评测用例，1 <= n, m <= 5；
　　对于 50% 的评测用例，1 <= n, m <= 10；
　　对于 80% 的评测用例，1 <= n, m <= 100；
　　对于所有评测用例，1 <= n, m <= 1000。
*/
#include <stdio.h>
int main(int argc, char const *argv[]) {
  int length;
  int range;
  scanf("%d %d", &length, &range);
  int memo[range + 1][length + 2];  // pre_num <= range, index <= length+1

  int index, pre_num;
  for (pre_num = 0; pre_num <= range; pre_num++) {
    for (index = 0; index < length + 1; ++index) {
      memo[pre_num][index] = 0;
    }
    // index == length + 1, 表示索引在长度之外 -> 数没有用完
    memo[pre_num][index] = 1;
  }

  // int next_num(int pre_num, int index) {
  //   if (memo[pre_num][index] != -1) {
  //     return memo[pre_num][index];
  //   }
  //   int i;
  //   int count = 0;
  //   if (index & 1) {  // 奇数比前一项大
  //     for (i = pre_num + 1; i <= range; ++i) {
  //       count = (count + next_num(i, index + 1)) % 10000;
  //     }
  //   } else {  // 偶数项比前小
  //     for (i = 1; i < pre_num; ++i) {
  //       count = (count + next_num(i, index + 1)) % 10000;
  //     }
  //   }
  //   memo[pre_num][index] = count;
  //   return count;
  // }

  for(int index = length+1;index> -1; --index){
    for(int pre_num = 0; pre_num <= range; ++pre_num){
      if (index & 1) {  // 奇数比前一项大
        for(int i= pre_num + 1;i<=range;++i){
          memo[pre_num][index] =
              (memo[pre_num][index] + memo[i][index + 1]) % 10000;
        }
      } else {  // 偶数项比前小
        for(int i=1;i<pre_num;++i){
          memo[pre_num][index] =
              (memo[pre_num][index] + memo[i][index + 1]) % 10000;
        }
      }
    }
  }

  printf("%d\n", memo[0][1]);  // index 从1开始,前一位当做0
  return 0;
}

// recursive
// time ./4_series.out
// 999 899
// 5210
// ./4_series.out  3.44s user 0.01s system 26% cpu 11.370 total

// dp
// $ time ./4_series.out
// 999 899
// 5210
// ./4_series.out  2.64s user 0.01s system 39% cpu 6.739 total