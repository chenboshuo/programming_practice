// ### 问题描述
// 平面上有 N 条直线，其中第 i 条直线是 y = Ai· x +
// Bi。请计算这些直线将平面分成了几个部分。

// ### 输入格式
// 第一行包含一个整数 N。
// 以下 N 行，每行包含两个整数 Ai, Bi。

// ### 输出格式
// 一个整数代表答案。

// ### 样例输入
// ```plt
// 3
// 1 1
// 2 2
// 3 3
// ```

// ### 样例输出
// ```plt
// 6
// ```

#include <cstdio>
#include <set>
using namespace std;
#define COINCIDENCE 1
#define NOT_COINCIDENCE 0

set<pair<double, double>> cross_points;
int add_cross_point(int ai, int aj, int bi, int bj) {
  double d = aj - ai;
  double dx = bi - bj;
  if (d != 0) {
    double dy = -ai * bj + aj * bi;
    cross_points.insert(make_pair(dx / d, dy / d));
    return NOT_COINCIDENCE;
  }
  // D=0
  if (dx == 0) { return COINCIDENCE; }
  return NOT_COINCIDENCE;  // parallel
}

int main() {
  int lines_num;
  scanf("%d", &lines_num);
  double param_a[lines_num];
  double param_b[lines_num];

  long cross_pre = 0;
  long long plane_count = 1;
  for (int i = 0; i < lines_num; ++i) {
    scanf("%lf %lf", &param_a[i], &param_b[i]);

    bool has_coincidence = false;
    for (int j = 0; j < i; ++j) {
      if (add_cross_point(param_a[i], param_a[j], param_b[i], param_b[j]) ==
          COINCIDENCE) {
        has_coincidence = true;
        break;
      }
    }
    if (!has_coincidence) {
      long cross_delta = cross_points.size() - cross_pre;
      plane_count += (cross_delta + 1);
    }
  }
  printf("%lld", plane_count);
}
