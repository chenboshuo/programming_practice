/*
 * I 后缀表达式
 * 时间限制: 1.0s 内存限制: 256.0MB 本题总分：25 分
 *
 * 【问题描述】
 *
 * 给定 N 个加号、M 个减号以及 N + M + 1 个整数 A 1 ,A 2 ,··· ,A N+M+1 ，小
 * 明想知道在所有由这 N 个加号、M 个减号以及 N + M +1 个整数凑出的合法的
 * 后缀表达式中，结果最大的是哪一个？ 请你输出这个最大的结果。 例如使用1 2 3 +
 * -，则 “2 3 + 1 -” 这个后缀表达式结果是 4，是最大的。
 *
 * 【输入格式】
 *
 * 第一行包含两个整数 N 和 M。 第二行包含 N + M + 1 个整数 A 1 ,A 2 ,··· ,A
 * N+M+1 。
 *
 * 【输出格式】
 *
 * 输出一个整数，代表答案。
 *
 * 【样例输入】
 *
 * 1 1
 * 1 2 3
 *
 * 【样例输出】
 *
 * 4
 *
 * 【评测用例规模与约定】
 *
 * 对于所有评测用例，0 ≤ N, M ≤ 100000，−109 ≤ Ai ≤ 10 9 。
 */
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
  return *(long int *)a - *(long int *)b;
}


/**
 * 寻找后缀表达式最大值
 * @param  nums      数组
 * @param  nums_size 数组大小
 * @param  minus     减号数量
 * @return           表达式的最大值
 */
long long int max_RPN(long int *nums, size_t nums_size, size_t minus) {
  long long int ans = 0;

  // 没有`-`的情况
  if (minus == 0) {
    for (size_t i = 0; i < nums_size; ++i) {
      ans += nums[i];
    }
    return ans;
  }

  // 接下来所有情况可以通过 -(a-b) = -a + b 转换为一个`-`
  qsort(nums, nums_size, sizeof(long int), comp);

  // 没有负数的情况
  if (*nums >= 0) {
    // printf("no negitive\n");
    return max_RPN(nums + 1, nums_size - 1, 0) - *nums;
  }

  // 接下来负数相加
  size_t i;
  for (i = 0; nums[i] < 0 && i < nums_size; ++i) {
    ans += nums[i];
  }
  // nums[i] = 最小正数

  // 没有正数
  if (i == nums_size) {
    ans -= nums[i - 1];  // 从结果中去掉第最后一项
    // printf("no positive");
    return nums[i - 1] - ans;  // `-`给最后一项
  }

  // `-`给负数让他变成正数
  nums[i - 1] = -ans;
  return max_RPN(nums + i - 1, nums_size - (i - 1), 0);
}

/**
 * 测试函数
 * 测试结果:
 *
 * {1,2,3,+,-}:    4
 * {2, -3, -4, +, -}:      9
 * {-1,-2,-3,+,-}: 4
 * {-1,-2,0,-,-}:  3
 *
 */
void test() {
  long int a1[3] = {1, 2, 3};
  printf("{1,2,3,+,-}:\t%lld\n", max_RPN(a1, 3, 1));

  long a2[3] = {2, -3, -4};
  printf("{2, -3, -4, +, -}:\t%lld\n", max_RPN(a2, 3, 1));

  long a3[3] = {-1, -2, -3};
  printf("{-1,-2,-3,+,-}:\t%lld\n", max_RPN(a3, 3, 1));

  long a4[3] = {-1, -2, 0};
  printf("{-1,-2,0,-,-}:\t%lld\n", max_RPN(a4, 3, 2));
}

int main(int argc, char const *argv[]) {
  // test();

  size_t plus, minus;
  scanf("%ld %ld", &plus, &minus);
  long int nums[plus + minus + 1];
  for (size_t i = 0; i < plus + minus + 1; ++i) {
    scanf("%ld", nums + i);
  }

  printf("%lld\n", max_RPN(nums, plus + minus + 1, minus));

  return 0;
}
