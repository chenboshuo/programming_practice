/*
问题描述
　　如果一个序列的奇数项都比前一项大，偶数项都比前一项小，则称为一个摆动序列。即 a[2i]<a[2i-1], a[2i+1]>a[2i]。
　　小明想知道，长度为 m，每个数都是 1 到 n 之间的正整数的摆动序列一共有多少个。
输入格式
　　输入一行包含两个整数 m，n。
输出格式
　　输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
样例输入
3 4
样例输出
14
样例说明
　　以下是符合要求的摆动序列：
　　2 1 2
　　2 1 3
　　2 1 4
　　3 1 2
　　3 1 3
　　3 1 4
　　3 2 3
　　3 2 4
　　4 1 2
　　4 1 3
　　4 1 4
　　4 2 3
　　4 2 4
　　4 3 4
评测用例规模与约定
　　对于 20% 的评测用例，1 <= n, m <= 5；
　　对于 50% 的评测用例，1 <= n, m <= 10；
　　对于 80% 的评测用例，1 <= n, m <= 100；
　　对于所有评测用例，1 <= n, m <= 1000。
*/
#include <stdio.h> 
int main(int argc, char const *argv[]) {
  int length;
  int range;
  scanf("%d %d", &length, &range);
  
  
  int next_num(int pre_num, int index){
    if(index == length+1){
      return 1;
    }
    int i;
    int count = 0;
    if(index & 1){ // 奇数比前一项大
      for(i=pre_num+1;i<=range;++i){
        count = (count + next_num(i, index + 1)) % 10000;
      }
    } else {  // 偶数项比前小
      for (i = 1; i < pre_num; ++i) {
        count = (count + next_num(i, index + 1)) % 10000;
      }
    }
    return count;
  }

  printf("%d\n",next_num(0,1));
  return 0;
}