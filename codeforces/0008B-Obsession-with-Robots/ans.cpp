#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib> // abs
using namespace std;

int main(int argc, char const *argv[])
{
  string s;
  cin >> s;
  int cur_x = 0,cur_y=0;
  int length = s.size()+1;
  int memo_x[length];
  int memo_y[length];
  memo_x[0]=0,memo_y[0] = 0;
  
  for(int i=0;i<s.size(); ++i){
    switch(s[i]){
      case 'L':
        --cur_x;
        break;
      case 'R':
        ++cur_x;
        break;
      case 'D':
        --cur_y;
        break;
      case 'U':
        ++cur_y;
    }
    memo_x[i+1] = cur_x;
    memo_y[i+1] = cur_y;
  }
  for(int i = 0; i < length; ++i){
    for (int j = 0; j < length;++j){
      if(abs(i-j)>1 
        && abs(memo_x[i]-memo_x[j]) + abs(memo_y[i] -memo_y[j]) < 2){
          printf("BUG\n");
          return 0;
        }
    }
  }
  printf("OK");
  return 0;
}
