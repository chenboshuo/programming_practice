/*
试题 历届试题 带分数

资源限制
时间限制：1.0s   内存限制：256.0MB
问题描述
100 可以表示为带分数的形式：100 = 3 + 69258 / 714。

还可以表示为：100 = 82 + 3546 / 197。

注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

类似这样的带分数，100 有 11 种表示法。

输入格式
从标准输入读入一个正整数N (N<1000*1000)

输出格式
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。

注意：不要求输出每个表示，只统计有多少表示法！

样例输入1
100
样例输出1
11
样例输入2
105
样例输出2
6
提交代码

*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

void swap(char *nums, int a, int b) {
  nums[a] ^= nums[b];
  nums[b] ^= nums[a];
  nums[a] ^= nums[b];
}

bool next_permutation(char *nums, int nums_size) {
  // find the valley
  int valley;
  for (valley = nums_size - 2; valley >= 0 && nums[valley] > nums[valley + 1];
       --valley) {
    ;
  }
  if (valley < 0) {
    return false;
  }

  int larger;  // nums[larger] is the smallist integer
               // than nums[valley] to the right of nums[larger]
  for (larger = nums_size - 1; nums[valley] > nums[larger]; --larger) {
    ;
  }

  // interchange nums[valley] and nums[larger]
  swap(nums, valley, larger);

  // sort the right part
  int right = nums_size - 1;
  int left = valley + 1;
  while (right > left) {
    swap(nums, left, right);
    --right;
    ++left;
  }

  return true;
}

long int pow_10(int exponent){
  long int base = 1;
  while(exponent--){
    base *= 10;
  }
  return base;
}

int main(int argc, char const *argv[]) {
  char input[10] = "100"; // 作为字符串输入
  int target_size =  strlen(input); // 记录目标值的位数
  int target = atoi(input); // 将目标转化为整数
  char p[10] = "123456789"; // 初始化排列
  int count = 0;
  
  int integer_size; // 整数应有的位数
  do{
    long int permutation = atoi(p);
    for(integer_size = 1; integer_size <= target_size; ++integer_size){
      long int fraction_filter = 1000000000L /*10^9*/ / pow_10(integer_size);
      long int integer = permutation / fraction_filter;  // 前 integer_size 位分给整数
      long int fraction_digits = permutation % fraction_filter;
      if(integer > target){ // 整数比目标大, 退出
        continue;
      }
      
      /*
       *   1. y != 1
       *   x+y = f
       *   x-y = t
       *
       *   2y = f - t
       *   (f-t) | 2
       *
       *   x : numerator_size 分子位数
       *   y: denominator_size 分母位数
       *   f: fraction_size 分数位数
       *   t: target size 目标值位数
       *   |整数|分子|分母
       */
      int fraction_size = 9 - integer_size; // 分数部分应该有的位数
      // 分母为一位数的情况
      int a_digit = permutation % 10;
      int other_digits = permutation % pow_10(fraction_size) / 10;
      if(other_digits % a_digit == 0 && 
        integer + other_digits / a_digit == target){
        ++count;
      }
      // debug
      printf("%ld %ld\t %d\t", permutation, integer, other_digits);
      // debug
      // 分母不是1
      if(fraction_size % 2 != 0){
        continue;
      }
      int denominator_size = (fraction_size - target_size) / 2;
      
      if (denominator_size <= 1){
        continue;
      } 
      int numerator_size = target_size + denominator_size;
      long int denominator_filter = pow_10(denominator_size);
      long int denominator = fraction_digits % denominator_size; // ? TODO 0
      long int numerator = fraction_digits / denominator;
      
      if (numerator % numerator != 0){ // 分数部分结果不是整数,舍去
        continue;
      }
      if(integer + numerator /denominator == target){
        ++count;
      }
    }

  }while(next_permutation(p,9));
  printf("%d\n",count);
  return 0;
}
