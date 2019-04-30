#include <stdio.h>
#include <stdlib.h>

// qsort 需要的比较函数
int compare(const void* a, const void* b){
  return  *(int *)a-*(int *)b;
}

int main(int argc, char const *argv[]) {
  int size;

  // 输入
  scanf("%d\n", &size);
  int *a = (int*) malloc(sizeof(int)*size);
  for(int i = 0; i < size; ++i){
    scanf("%d", a+i);
  }

  // 排序（C的快速排序不好调用，但确实效率高
  qsort(a, size, sizeof(int),compare);

  // 去重
  int *p = a;  // 快指针
  int *q = a;  // 慢指针
  while(size--){
    if (*p != *q) {
      ++q;
      *q = *p;  // 修改值
    }
    ++p;
  }
  size = q - a + 1;
  printf("%d\n", size);
  for(int i = 0; i < size; ++i){
    printf("%d ", a[i]);
  }

  return 0;
}
