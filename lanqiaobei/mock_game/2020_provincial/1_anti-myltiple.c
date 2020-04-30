/*
问题描述
　　给定三个整数 a, b, c，如果一个整数既不是 a 的整数倍也不是 b 的整数倍还不是 c
的整数倍，则这个数称为反倍数。 　　请问在 1 至 n 中有多少个反倍数。 输入格式
　　输入的第一行包含一个整数 n。
　　第二行包含三个整数 a, b, c，相邻两个数之间用一个空格分隔。
输出格式
　　输出一行包含一个整数，表示答案。
样例输入
30
2 3 6
样例输出
10
样例说明
　　以下这些数满足要求：1, 5, 7, 11, 13, 17, 19, 23, 25, 29。
评测用例规模与约定
　　对于 40% 的评测用例，1 <= n <= 10000。
　　对于 80% 的评测用例，1 <= n <= 100000。
　　对于所有评测用例，1 <= n <= 1000000，1 <= a <= n，1 <= b <= n，1 <= c <= n。
*/

#include <stdbool.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  long int range;
  scanf("%ld", &range);
  bool is_multiple[1000001] = {false};
  long int abc[3];
  scanf("%ld %ld %ld", abc, abc + 1, abc + 2);
  long int num, i;
  for (num = 0; num < 3; ++num) {
    for (i = abc[num]; i <= range; i += abc[num]) {
      is_multiple[i] = true;
    }
  }

  // count
  long int count = 0;
  for (i = 1; i <= range; ++i) {
    if (!is_multiple[i]) {
      ++count;
    }
  }
  printf("%ld\n", count);

  return 0;
}