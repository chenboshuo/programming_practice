// ## F 成绩统计
// (15分)
// ### 问题描述
// 小蓝给学生们组织了一场考试，
// 卷面总分为 100 分，
// 每个学生的得分都是
// 一个 0 到 100 的整数。
// 如果得分至少是 60 分，则称为及格。
// 如果得分至少为 85 分，则称为优秀。
// 请计算及格率和优秀率，用百分数表示，
// 百分号前的部分四舍五入保留整数。
//
// ### 输入格式
// 输入的第一行包含一个整数 n，表示考试人数。
// 接下来 n 行，每行包含一个 0 至 100 的整数，表示一个学生的得分。
//
// ### 输出格式
// 输出两行，每行一个百分数，
// 分别表示及格率和优秀率。
// 百分号前的部分四舍五入保留整数。
//
// ### 样例输入
// ```plt
// 7
// 80
// 92
// 56
// 74
// 88
// 100
// 0
// ```
//
// ### 样例输出
// ```plt
// 71%
// 43%
// ```
//
// ### 评测用例规模与约定
// 对于50% 的评测用例， 1 ≤ n ≤ 100。
// 对于所有评测用例，1 ≤ n ≤10000。

#include <math.h>
#include <stdio.h>

// int percentage(long num,int size){
//   num *= 100;
//   double a = num*1.0 / size;
//   long  base = a;
//   return base + (a - base >= 0.5);
// }

int main() {
  int size;
  long excellent = 0, pass = 0;
  scanf("%d", &size);
  long t = size;
  while (t--) {
    int score;
    scanf("%d", &score);
    if (score >= 60) { ++pass; }
    if (score >= 85) { ++excellent; }
  }
  // printf("%d",percentage(pass,size));
  printf("%d", (int)round(pass * 100.0 / size));
  puts("%");
  printf("%d", (int)round(excellent * 100.0 / size));
  // printf("%d",percentage(excellent,size));
  puts("%");
}
