#include "stdio.h"

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
