/**
 * 把 2019 分解成 3 个各不相同的正整数之和，并且要求每个正整数都不包
 * 含数字 2 和 4，一共有多少种不同的分解方法？
 * 注意交换 3 个整数的顺序被视为同一种方法，例如 1000+1001+18 和
 * 1001+1000+18 被视为同一种。
 * 【答案提交】
 * 这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一
 * 个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。
 */
#include <stdbool.h>
#include <stdio.h>

/**
 * n中每一位是否有2或4
 * @param  n 数
 * @return   是或否
 */
bool has_4_2(int n) {
  while (n) {
    if ((n % 10 == 4) || (n % 10 == 2)) {
      return false;
    }
    n /= 10;
  }
  return true;
}

/**
 * 寻找符合条件的数的个数并输出
 * @param  sum 三个数的和
 * @return     符合条件的个数
 */
int find_sum(int sum) {
  int count = 0;
  for (size_t i = sum / 3; i < sum; ++i) {
    for (size_t j = 1; j < i; ++j) {
      int k = sum - i - j;
      if (j > k && has_4_2(i) && has_4_2(j) && has_4_2(k) && k > 0) {
        printf("%d %d %d\n", i, j, k);
        ++count;
      }
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  printf("%d\n", find_sum(2019));

  return 0;
}
