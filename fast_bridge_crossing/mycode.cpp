/*
  速度最快的先通过或返回
 */
#include "stdio.h"

int a[1000], b[1000],len_a,len_b=0,person1=0,person2=0,sum=0;//设为全局变量方便函数调用

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

// int across_river(int *a, int *b,int len_a, int len_b) {
//   if (len_a == 1) {
//     len_b++;
//     *(b+len_b) = *a;
//     person1 = *a;
//     person2 = 0;
//     len_a = remove(a,len_a,1);
//     bubble_sort(b,len_b);
//     return *(b);
//   } else {
//     *(b+len_b) = *a;
//     *(b+len_b+1) = *(a+1);
//     len_b += 2;
//     if (len_b) {// test
//       printf("\n%s\n", "--a--");
//       for (int k = 0; k < len_a; k++) {
//         printf("%d  ", a[k]);
//       }
//       printf("\n%s\n", "----");
//       printf("%s\n", "--b--");
//       for (int h = 0; h < len_b; h++) {
//         printf("%d ", b[h]);
//       }
//       printf("\n%s\n", "---b--");
//     }
//     person1 = *a;
//     person2 = *(a+1);
//     len_a = remove(a,len_a, 2);
//     bubble_sort(b,len_b);
//     return *(b+1);// 排序后,b的前两项为过河的人,第二个为时间较长的人
//   }
// }
//
// int go_back(int *a, int *b,int len_a, int len_b){
//   *(a+len_a) = *b;
//   person1 = *b;
//   person2 = 0;
//   bubble_sort(a,len_a);
//   len_b = remove(b,len_b, 1);
//   return *a;
// }

int main(int argc, char const *argv[]) {
  int count;
  int temp[10000][2]={0};// 存储每一组需要的时间
  scanf("%d\n", &count);
  while (count--) {
    // 输入
    scanf("%d\n", &len_a);
    for (int i = 0; i < len_a; i++) {
      scanf("%d", a+i);
    }

    // 过河的数据存到数组里
    int i=0;
    while (len_a) {
      // sum += across_river(a, b,len_a,len_b);////////////////////////////////////////
      if (len_a == 1) {
        len_b++;
        *(b+len_b) = *a;
        temp[i][0] = *a;
        temp[i][1] = 0;
        len_a = remove(a,len_a,1);
        bubble_sort(b,len_b);
        sum += *(b);
      } else {
        *(b+len_b) = *a;
        *(b+len_b+1) = *(a+1);
        len_b += 2;
        if (len_b) {// test
          printf("\n%s\n", "--a--");
          for (int k = 0; k < len_a; k++) {
            printf("%d  ", a[k]);
          }
          printf("\n%s\n", "----");
          printf("%s\n", "--b--");
          for (int h = 0; h < len_b; h++) {
            printf("%d ", b[h]);
          }
          printf("\n%s\n", "---b--");
        }
        temp[i][0] = *a;
        temp[i][1] = *(a+1);
        len_a = remove(a,len_a, 2);
        bubble_sort(b,len_b);
        sum += *(b+1);// 排序后,b的前两项为过河的人,第二个为时间较长的人
      }
      i++;
      // test
      printf("%s\n", "====");
      //

      // 最快的回来
      *(a+len_a) = *b;
      temp[i][0] = *b;
      temp[i][1] = 0;
      bubble_sort(a,len_a);
      len_b = remove(b,len_b, 1);
      sum += *a;
      // sum += go_back(a, b, len_a, len_b);
      i ++;
    }

    // 输出
    printf("%d\n", sum);
    for (int j = 0; j < i; j++) {
      printf("%d", temp[j][0]);
      if (temp[j][1]) {
        printf("%d", temp[j][1]);
      }
      printf("\n");
    }
  }
  return 0;
}
