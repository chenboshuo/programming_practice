// ## H 子串分值和
// 时间限制: 1.0s 内存限制: 256.0MB 本题总分：20 分

// ### 问题描述
// 对于一个字符串 `S`，
// 我们定义 `S` 的分值 `f(S)`
// 为 S 中出现的不同的字符个数。
// 例如 `f(”aba”) = 2`，`f(”abc”) = 3`,
// `f(”aaa”) = 1`。
// 现在给定一个字符串`S [0…n − 1]`（长度为 n），
// 请你计算对于所有 `S` 的非空子串 `S [i… j]
// (0 ≤ i ≤ j < n)`，`f(S [i… j])` 的和是多少。

// ### 输入格式
// 输入一行包含一个由小写字母组成的字符串 S。

// ### 输出格式
// 输出一个整数表示答案。

// ### 样例输入
// ```plt
// ababc
// ```

// ### 样例输出
// ```plt
// 28
// ```

// ### 样例说明
// 子串   f值
// a      1
// ab     2
// aba    2
// abab   2
// ababc  3
//  b     1
//  ba    2
//  bab   2
//  babc  3
//   a    1
//   ab   2
//   abc  3
//    b   1
//    bc  2
//     c  1
// ```
#include<stdio.h>

int main(){
  char s[100001];
  scanf("%s",s);
  int left = 0;
  long long total = 0;
  while(s[left]){
    int right = left;
    int score = 0;
    int record[26] = {0};
    while(s[right]){
      if(!record[s[right] - 'a']){
        record[s[right] - 'a'] = 1;
        ++score;
      }
      total += score;
      ++right;
    }     
    ++left;
  }
  printf("%lld\n",total);

  return 0;
}

// test1 passed(5.8013210000353865 ms)
// test2 passed(2.292712000780739 ms)
// test 3 (11561.953512995387 ms)