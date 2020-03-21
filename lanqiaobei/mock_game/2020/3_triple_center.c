/*
问题描述
　　在数列 a[1], a[2], ..., a[n] 中，如果对于下标 i, j, k 满足 0<i<j<k<n+1 且
a[i]<a[j]<a[k]，则称 a[i], a[j], a[k] 为一组递增三元组，a[j]为递增三元组的中心。
　　给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
输入格式
　　输入的第一行包含一个整数 n。
　　第二行包含 n 个整数 a[1], a[2], ...,
a[n]，相邻的整数间用空格分隔，表示给定的数列。 输出格式
　　输出一行包含一个整数，表示答案。
样例输入
5
1 2 5 3 5
样例输出
2
样例说明
　　a[2] 和 a[4] 可能是三元组的中心。
评测用例规模与约定
　　对于 50% 的评测用例，2 <= n <= 100，0 <= 数列中的数 <= 1000。
　　对于所有评测用例，2 <= n <= 1000，0 <= 数列中的数 <= 10000。
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int nums_size;
  scanf("%d", &nums_size);

  int nums[nums_size];
  int i;
  for (i = 0; i < nums_size; ++i) {
    scanf("%d", &nums[i]);
  }

  int min_of_before[nums_size];
  int max_of_after[nums_size];

  int min = nums[0];
  for (i = 0; i < nums_size; ++i) {
    if (nums[i] <= min) {
      min = nums[i];
      min_of_before[i] = 1;
    } else {
      min_of_before[i] = 0;
    }
  }

  int max = nums[nums_size - 1];
  for (i = nums_size - 1; i >= 0; --i) {
    if (nums[i] >= max) {
      max = nums[i];
      max_of_after[i] = 1;
    } else {
      max_of_after[i] = 0;
    }
  }

  int count = 0;
  for (i = 0; i < nums_size; ++i) {
    if (!min_of_before[i] && !max_of_after[i]) {
      ++count;
    }
  }

  printf("%d\n", count);

  return 0;
}