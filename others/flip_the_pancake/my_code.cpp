/*
 * 思路
 * 寻找最大值,然后翻到第一位(如果最大值在第一位,跳过)
 * 然后将最大值放到对应位置
 */

#include"stdio.h"

/**
 * 将一部分数据反转
 * @param start 开始的位置
 * @param end   结束的位置
 */
void reverse(int *start,int *end) {
	int _;
	for (;start<end;start++,end--) {
		_ = *start;
		*start = *end;
		*end = _;
	}
}

/**
 * 冒泡排序
 * @param p   要排序的字符串
 * @param len 字符串长度
 */
void bubble_sort(int *p, int len) {
  int _,i, j;
  for (i = 0; i < len-1; i++) {
    for (j = 0; j < len-1-i; j++) {
      if (*(p+j)>*(p+j+1)) {
        _ = *(p+j);*(p+j) = *(p+j+1);*(p+j+1) =_;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
	char c;
while (1) {
	int a[30];// 初始输入
	int sorted[30];// 排序后的数组
	int i;
	int len=0; //保存数组长度
	int *max;//记录最大值位置
	int *pa;//实现对a的操作
	int *amax;//寻找a的最大值

	// 输入
	while (scanf("%d", a+len)  &&(c = getchar()) && c != EOF && c!='\n') {
		len++;
	}

	// 判断结束
	if (!len) {
		break;
	}

	len++;//len+1 作为长度

	// 复制数据 ,输出原始数据
	for (i = 0; i <len; i++) {
		*(sorted+i) = *(a+i);
		printf("%d ", *(a+i));
	}
	printf("\n");

	bubble_sort(sorted,len);
	max = sorted + len-1;
	amax = pa = a + len-1;


	while(max != sorted){//若要处理的最大值不在开头
		int flip = 1;//记录翻煎饼的位置

		//要是最大值在对应位置上就不作处理
		while (*pa == *max && pa > a && max > sorted) {
			max--;pa--;amax--;flip++;
		}

		while (*(amax) != *max && amax > a) {// 寻找最大值
			flip++;amax--;
		}

		// 找到最大值,反转
		if (amax != a) {
			reverse(a,amax);
			printf("%d ", flip);
		}

		// 第二次翻转是把最大值放到对应位置
		if(a != pa){
			reverse(a,pa);
			printf("%d ", a+len-pa);
		}
		amax = pa;// 指针回到开始


	}
	printf("0\n");
}

	return 0;
}
