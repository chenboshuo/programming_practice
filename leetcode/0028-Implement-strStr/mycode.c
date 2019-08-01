int strStr(char * haystack, char * needle){
  int j;
  for(int i=0; haystack[i];++i){
    for(j=0; haystack[i] == needle[j];++j ){
      ;
    }
    if(!needle[j]){ // needle[j] == '\0' 代表遍历完成
      return i;
    }
  }
  return -1;
}

// https://leetcode.com/submissions/detail/248040331/
// Wrong Answer
//
// Input
// ""
// ""
// Output
// -1
// Expected
// 0
