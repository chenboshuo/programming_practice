/*
问题描述
　　给定一个单词，请使用凯撒密码将这个单词加密。
　　凯撒密码是一种替换加密的技术，单词中的所有字母都在字母表上向后偏移3位后被替换成密文。即a变为d，b变为e，...，w变为z，x变为a，y变为b，z变为c。
　　例如，lanqiao会变成odqtldr。
输入格式
　　输入一行，包含一个单词，单词中只包含小写英文字母。
输出格式
　　输出一行，表示加密后的密文。
样例输入
lanqiao
样例输出
odqtldr
评测用例规模与约定
　　对于所有评测用例，单词中的字母个数不超过100。
*/
#include <stdio.h>
void encode(char* s) {
  while (*s) {
    int diff = *s - 'a';
    diff = (diff + 3) % 26;
    *s = 'a' + diff;
    ++s;
  }
}

int main(int argc, char const* argv[]) {
  char s[101];
  scanf("%100s", s);
  encode(s);
  printf("%s\n", s);

  return 0;
}