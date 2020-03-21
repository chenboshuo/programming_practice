/*
问题描述
　　小明对类似于 hello
这种单词非常感兴趣，这种单词可以正好分为四段，第一段由一个或多个辅音字母组成，第二段由一个或多个元音字母组成，第三段由一个或多个辅音字母组成，第四段由一个或多个元音字母组成。
　　给定一个单词，请判断这个单词是否也是这种单词，如果是请输出yes，否则请输出no。
　　元音字母包括 a, e, i, o, u，共五个，其他均为辅音字母。
输入格式
　　输入一行，包含一个单词，单词中只包含小写英文字母。
输出格式
　　输出答案，或者为yes，或者为no。
样例输入
lanqiao
样例输出
yes
样例输入
world
样例输出
no
评测用例规模与约定
　　对于所有评测用例，单词中的字母个数不超过100。
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int alpha[256] = {0};
  alpha['a'] = 1;
  alpha['e'] = 1;
  alpha['i'] = 1;
  alpha['o'] = 1;
  alpha['u'] = 1;

  char s[100];
  scanf("%s", s);

  int i = 0;
  int part1 = 0, part2 = 0, part3 = 0, part4 = 0;

  while (s[i] && alpha[s[i]] == 0) {
    ++i;
    part1 = 1;
  }
  while (s[i] && alpha[s[i]] == 1) {
    ++i;
    part2 = 1;
  }
  while (s[i] && alpha[s[i]] == 0) {
    ++i;
    part3 = 1;
  }
  while (s[i] && alpha[s[i]] == 1) {
    ++i;
    part4 = 1;
  }
  if (!s[i] && part1 && part2 && part3 && part4) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return 0;
}