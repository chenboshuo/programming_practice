#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// #define DEFRAGMENT 1
// #define ALLOC 2
// #define ERASE 3

int id=1;
int* memory;
int memo_size;
void alloc(int size){
  int i=0,j=0;
  while(i<memo_size){
    while(i<memo_size && memory[i] != 0){
      ++i;
    }
    for(j=0;j<size && i+j < memo_size && memory[i+j] == 0;++j){;}
    if(j == size){
      for(int k=i;k<i+j;++k){
        memory[k] = id; 
      }
      printf("%d\n",id++);
      return;
    }else{
      i += j;
    }
  }
  printf("NULL\n");
}

void erase(int id){
  int i;
  for(i=0;i<memo_size && memory[i] != id;++i){;}
  if(i == memo_size){
    printf("ILLEGAL_ERASE_ARGUMENT\n");
    return;
  }
  while(i<memo_size && memory[i] == id){
    memory[i++] = 0;
  }

}
void defragment(){
  int quick=0;
  for(int slow=0;slow<memo_size; ++slow){
    while(quick < memo_size && memory[quick] == 0){
      ++quick;
    }
    if(quick == memo_size){
      return;
    }
    int t = memory[quick];
    memory[quick++] = 0;
    memory[slow] = t;
  }
}

void input(){
  char op[15];
  int op_num;
  scanf("%s",op);
  // printf("s=%s",op);
  if (!strcmp(op,"defragment")){
    // printf("defragment:\t");
    defragment();
    return ;
  }
  scanf("%d",&op_num);
  if(!strcmp(op,"alloc")){
    // printf("alloc:\t");
    alloc(op_num);
  }else {
    // printf("erase:\t");
    erase(op_num);
  }
}

int main(int argc, char const *argv[]) {
  int times;
  scanf("%d %d",&times,&memo_size);
  memory = (int*)calloc(memo_size,sizeof(int));
  while(times--){
    input();
  }
  
  return 0;
}


// Test: #3, time: 30 ms., memory: 0 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
// Input
// 14 100
// alloc 99
// alloc 1
// alloc 1
// erase 2
// alloc 1
// erase 4
// erase 1
// alloc 100
// alloc 1
// alloc 99
// defragment
// erase 4
// alloc 100
// alloc 99
// Output
// 1
// 2
// NULL
// 3
// ILLEGAL_ERASE_ARGUMENT
// NULL
// 4
// NULL
// 5
// NULL
// Answer
// 1
// 2
// NULL
// 3
// ILLEGAL_ERASE_ARGUMENT
// NULL
// 4
// NULL
// NULL
// NULL