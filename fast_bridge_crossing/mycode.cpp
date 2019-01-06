/*
  速度最快的先通过或返回
 */
#include "stdio.h"

int a[1000], b[1000],len_a,len_b;//设为全局变量方便函数调用

int max(int a, int b){
  if(a > b){
    return a;
  }
  else{
    return b;
  }
}

/**
 * 冒泡排序:将数据由小到大排列
 * @param p   要排序的字符串
 * @param len 字符串长度
 */
void bubble_sort(int *p, int len) {
  int _,i, j;
  for (i = 0; i < len-1; i++) {
    for (j = 0; j < len-1-i; j++) {
      if (*(p+j) > *(p+j+1)) {
        _ = *(p+j);*(p+j) = *(p+j+1);*(p+j+1) =_;
      }
    }
  }
}

/**
 * 删除前number项并返回长度
 * @param  a      数组名
 * @param  len    数组长度
 * @param  number 要删掉的项数
 * @return        数组长度
 */
int remove(int *a,int len,int number) {
  for (int i = 0; i < len-number; i++) {
    a[i] = a[i+number];
  }
  return len - number;
}

int across_river(int *a, int *b,int len_a, int len_b) {
  if (len_a == 1) {
    *(b+len_b) = *a;
    len_a = remove(a,len_a,1);
    len_b++;
    bubble_sort(b,len_b);
    return *(b);
  } else {
    *(b+len_b) = *a;
    *(b+len_b+1) = *(a+1);
    len_a = remove(a,len_a, 2);
    len_b += 2;
    bubble_sort(b,len_b);
    return *(b+1);// 排序后,b的前两项为过河的人,第二个为时间较长的人
  }
}

int go_back(int *a, int *b,int len_a, int len_b){
  *(a+len_a) = *b;
  bubble_sort(a,len_a);
  len_b = remove(b,len_b, 1);
  return *a;
}

int main(int argc, char const *argv[]) {
  int count;
  scanf("%d\n", count);
  while (count--) {
    // 输入
    scanf("%d\n", &len_a);
    for (int i = 0; i < len_a; i++) {
      scanf("%d\n", a+i);
    }
  }
  return 0;
}
