/**
 * 小明对数位中含有 2、0、1、9 的数字很感兴趣（不包括前导 0） ，在 1 到
 40 中这样的数包括 1、2、9、10 至 32、39 和 40，共 28 个，他们的和是 574。
 请问，在 1 到 n 中，所有这样的数的和是多少？

 【输入格式】

 输入一行包含两个整数 n。

 【输出格式】

 输出一行，包含一个整数，表示满足条件的数的和。

 【样例输入】
 ```plt
 40
 ```
 【样例输出】
 ```plt
 574
 ```
 【评测用例规模与约定】
 ```plt
 对于 20% 的评测用例，1 ≤ n ≤ 10。
 对于 50% 的评测用例，1 ≤ n ≤ 100。
 对于 80% 的评测用例，1 ≤ n ≤ 1000。
 对于所有评测用例，1 ≤ n ≤ 10000。
 ```

 * @param  n [description]
 * @return   [description]
 */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/**
 * n是否含2,0,1,9
 * @param  n 数
 * @return   是否
 */
bool is_special(int n) {
  while (n) {
    int lowest = n % 10;
    if ((lowest == 2) || (lowest == 0) || (lowest == 1) || (lowest == 9)) {
      return true;
    }
    n /= 10;
  }
  return false;
}

/**
 * 统计1到n特殊数的和
 * @param  n 之后一个数
 * @return   数的和
 */
int special_sum(int n) {
  // int count = 0;
  int sum = 0;
  for (int i = 1; i < n + 1; ++i) {
    if (is_special(i)) {
      // printf("%d ", i);
      // ++count;
      sum += i;
    }
  }
  // printf("\n%d\n", count);
  return sum;
}

int main(int argc, char const *argv[]) {
  // // 计时
  // time_t start, end;
  // start = time(NULL);

  // printf("%d\n", is_special(1));
  // printf("%d\n", special_sum(10000));
  int in;
  scanf("%d", &in);

  // // 计时
  // end = time(NULL);
  // printf("\nduration: %lf s\n", difftime(end, start));
  return 0;
}
