/*
 * H 等差数列
 *
 * 数学老师给小明出了一道等差数列求和的题目。
 * 但是粗心的小明忘记了一部分的数列，只记得其中 N个整数。
 * 现在给出这 N个整数，小明想知道包含这 N个整数的最短的等差数列有几项?
 * 输入：
 *
 * 输入的第一行包含一个整数 N。 第二行包含N个整数A1,A2,···,An。
 * (注意A1 ~ An并不一定是按等差数列中的顺序给出)
 *
 * 输出格式：
 *
 * 输出一个整数表示答案。
 *
 * 样例输入：
 * ```plt
 * 5
 * 2 6 4 10 20
 * ```
 * 样例输出：
 * ```plt
 * 10
 * ```
 * 样例说明：
 * 包含 2、6、4、10、20 的最短的等差数列是 2、4、6、8、10、12、14、16、 18、20。
 * 数据范围：
 * 对于所有评测用例，2 ≤ N≤ 100000，0 ≤ Ai≤ 10^9。
 */

#include <limits.h>
#include <stdio.h>

#define abs(x) ((x < 0) ? -(x) : (x))

/**
 * 求a,b 最大公因数, |a| < |b|.
 * @param  a 较小的数
 * @param  b 较大的数
 * @return   a,b 的最大公因数
 */
long long int gcd(long long int a, long long int b) {
  if (abs(a) > abs(b)) {
    return gcd(b, a);
  }
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

size_t ap_size(long long int *nums, size_t nums_size) {
  long long int min = LLONG_MAX;
  long long int max = LLONG_MIN;
  long long int divisor = 0;
  while (nums_size--) {
    if (*nums < min) {
      min = *nums;
    }
    if (*nums > max) {
      max = *nums;
    }
    divisor = gcd(divisor, *nums);
    ++nums;
  }
  if (divisor == 0) {
    return nums_size;
  }
  return (max - min) / divisor + 1;
}

int main(int argc, char const *argv[]) {
  long long int nums[5] = {2, 6, 4, 10, 20};
  // printf("%lld\n", gcd(1, 3));
  // printf("%d\n", gcd(-1, -3));
  printf("%ld", ap_size(nums, 5));

  return 0;
}
