// reference: https://blog.csdn.net/bdu_zhangAo/article/details/109715079
#include <stdio.h>
#define abs(x) (x > 0 ? x : -x)
int main() {
  int x[4] = { 0, 2020, 11, 2000 };
  int y[4] = { 0, 11, 14, 2000 };
  int spot = 0;
  // 只要遍历下地图，如果某个点到开始的4个点中的一个
  // 的曼哈顿距离小于等于2020，就代表可以扩散到。
  // 注意数据范围可以写大一点，保证不要有遗漏。
  for (int i = -2030; i < 4060; ++i) {
    for (int j = -2030; j < 4060; ++j) {
      for (int k = 0; k < 4; ++k) {
        if (abs(x[k] - i) + abs(y[k] - j) <= 2020) {
          ++spot;
          break;
        }
      }
    }
  }
  printf("%d\n", spot);
  return 0;
}
