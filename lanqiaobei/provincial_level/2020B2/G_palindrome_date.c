// ## G 回文日期
// 时间限制: 1.0s 内存限制: 256.0MB 本题总分：20 分
//
// ### 问题描述
// 2020 年春节期间，有一个特殊的日期引起了大家的注意：
// 2020 年 2 月 2日。
// 因为如果将这个日期按 “yyyymmdd” 的格式写成一个 8 位数是 20200202，
// 恰好是一个回文数。
// 我们称这样的日期是回文日期。
// 有人表示 20200202 是 “千年一遇” 的特殊日子。
// 对此小明很不认同，
// 因为不到 2 年之后就是下一个回文日期：
// 20211202 即 2021 年 12 月 2 日。
// 也有人表示 20200202 并不仅仅是一个回文日期，
// 还是一个 ABABBABA型的回文日期。
// 对此小明也不认同，
// 因为大约 100 年后就能遇到下一个ABABBABA 型的回文日期：21211212 即 2121 年 12
// 月 12 日。 算不上 “千年一遇”，顶多算 “千年两遇”。 给定一个 8 位数的日期，
// 请你计算该日期之后下一个回文日期和下一个ABABBABA 型的回文日期各是哪一天。
//
// ### 输入格式
// 输入包含一个八位整数 N，表示日期。
//
// ### 输出格式
// 输出两行，每行 1 个八位数。
// 第一行表示下一个回文日期，第二行表示下一个 ABABBABA 型的回文日期。
//
// ### 样例输入
// 20200202
//
// ### 样例输出
// 20211202
// 21211212
// ### 评测用例规模与约定
// 对于所有评测用例，
// `10000101 ≤ N ≤ 89991231`，
// 保证 N 是一个合法日期的 8 位数表示。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // string.h
#include<stdbool.h> // bool type

bool is_palindrom(char*s){
  int right=7,left=0;
  while(left<right){
    if(s[left] != s[right]){
      return false;
    }
    ++left;
    --right;
  }
  return true;
}

bool is_ababbaba(char *s){
  char a = s[0];
  char b = s[1];
  char target[8] = {a,b,a,b,b,a,b,a};
  return (strcmp(target,s) == 0);
} 


int main() {
  int y, m, d;
  struct tm *given;
  char date[9];
  given = (struct tm *)calloc(1, sizeof(struct tm));
  // 防止内存中随机数改变日期，
  // 也可以获取当前时间来得到一个合法日期，这里calloc将所有项清零

  scanf("%4d%2d%2d", &y, &m, &d);
  // https://www.cplusplus.com/reference/ctime/tm/
  given->tm_year = y - 1900;  // 注意接口结构体的含义
  given->tm_mon = m - 1;
  given->tm_mday = d;
  do{
    ++(given->tm_mday);
    mktime(given);
    strftime(date, 9, "%Y%m%d", given);
  }while(!is_palindrom(date));
  puts(date);

  given->tm_year = y - 1900;  // 注意接口结构体的含义
  given->tm_mon = m - 1;
  given->tm_mday = d;
  do{
    ++(given->tm_mday);
    mktime(given);
    strftime(date, 9, "%Y%m%d", given);
  }while(!is_ababbaba(date));
  puts(date);

  return 0;
}
