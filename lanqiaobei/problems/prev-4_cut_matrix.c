/*
  试题 历届试题 剪格子
      
  资源限制
  时间限制：1.0s   内存限制：256.0MB
  问题描述
  如下图所示，3 x 3 的格子中填写了一些整数。

  +--*--+--+
  |10* 1|52|
  +--****--+
  |20|30* 1|
  *******--+
  | 1| 2| 3|
  +--+--+--+
  我们沿着图中的星号线剪开，得到两个部分，每个部分的数字和都是60。

  本题的要求就是请你编程判定：对给定的m x n 的格子中的整数，是否可以分割为两个部分，使得这两个区域的数字和相等。

  如果存在多种解答，请输出包含左上角格子的那个区域包含的格子的最小数目。

  如果无法分割，则输出 0。

  输入格式
  程序先读入两个整数 m n 用空格分割 (m,n<10)。

  表示表格的宽度和高度。

  接下来是n行，每行m个正整数，用空格分开。每个整数不大于10000。

  输出格式
  输出一个整数，表示在所有解中，包含左上角的分割区可能包含的最小的格子数目。
  样例输入1
  3 3
  10 1 52
  20 30 1
  1 2 3
  样例输出1
  3
  样例输入2
  4 3
  1 1 1 1
  1 30 80 2
  1 1 1 100
  样例输出2
  10
*/
#include<stdio.h>
int matrix[10][10];
char is_selected[10][10];
long total=0;
int line_size,col_size;

#define FOUND 1
#define NOT_FOUND 0
/** search for solution
@param sum the initial sum
@param cur the "return" sum
*/
char search(int i, int j, long sum){
  if(i>=line_size|| i<0|| j>=col_size||j<0||is_selected[i][j]){
    return NOT_FOUND;
  }
  long cur = sum + matrix[i][j];
  if(cur > total/2){
    return NOT_FOUND;
  }
  is_selected[i][j] = 1;
  if(cur == total/2){
    return FOUND;
  }
  if(!search(i+1,j,cur) && !search(i-1,j,cur) 
      && !search(i,j+1,cur) && !search(i,j-1,cur)){
        is_selected[i][j] = 0;
        return NOT_FOUND;
      }



}

int main(int argc, char const *argv[]) {
  
  scanf("%d %d",&line_size,&col_size);
  // init the selected matrix

  // input
  int i,j;
  for(i=0;i<line_size;++i){
    for(j=0;j<col_size;++j){
      is_selected[i][j] = 0;
      int in;
      scanf("%d",&in);
      total += in;
      matrix[i][j] = in;
    }
  }
  if(total & 1){
    printf("0\n");
    return 0;
  }
  char has_found = search(0,0,0);
  if(!has_found){
    printf("0\n");
    return 0;
  }
  
  
  // count
  int count = 0;
  for(i=0;i<line_size;++i){
    for(j=0;j<col_size;++j){
      count += is_selected[i][j];
    }
  }
  printf("%d\n",count);

  return 0;
}


// 评测点序号	评测结果	得分	CPU使用	内存使用	下载评测数据
// 1	正确	33.33	0ms	2.171MB	输入 输出
// 2	错误	0.00	0ms	1.957MB	VIP特权
// 3	正确	33.33	0ms	1.960MB	VIP特权