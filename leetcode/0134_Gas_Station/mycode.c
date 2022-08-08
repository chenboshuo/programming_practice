char findTheDifference(char *s, char *t) {
  // int extra;
  int memo[256] = {0};
  while(*s){
    ++memo[*s]; 
    ++s;
  }
  while(*t){
    --memo[*t];
    ++t;
  }
  for(char i=0;i<256;++i){
    if(memo[i]){
      return i;
    }
  }
}