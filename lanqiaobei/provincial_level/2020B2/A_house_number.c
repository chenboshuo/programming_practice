#include<stdio.h>
int counter = 0;

int digits_counter(int d){
  while(d){
    if (d % 10 == 2){
      ++counter;
    }
    d /= 10;
  }
}


int main(int argc, char const *argv[]) {
  // digits_counter(2012);
  for(int i=1;i<=2020;++i){
    digits_counter(i);
  }
  printf("%d\n",counter);
  
  return 0;
}