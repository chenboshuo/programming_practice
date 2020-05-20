#include <string.h>

char * removeKdigits(char * num, int k){
  if(k == strlen(num)){
    return "0";
  }
  int slow = 0;
  int fast;
  for(fast=1;num[fast];++fast){
    if(num[fast] < num[slow] && k){
      num[slow] = num[fast];
      --k;
    }else{
      num[++slow] = num[fast];
    }
  }
  num[slow+1] = '\0';
  while(*num == '0' && *(num+1)){
    ++num;
  }
  return num;
}
