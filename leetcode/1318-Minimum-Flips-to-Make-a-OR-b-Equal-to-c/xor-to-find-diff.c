int minFlips(int a, int b, int c){
  int a_or_b = a | b;
  int count = 0;
  for(int diff = c ^ a_or_b; diff; diff >>= 1,a>>=1,b>>=1,c>>=1){
    // 如果有差别, 处理
    if(diff & 1){
      // 如果c最低位为1, 则说明 a|b 最后一位为0,只需一位变成1
      if(c&1){
        ++count;
      }else{
        // a,b 最后一位都是1, c最低位为0,改2个
        if(a&b&1){
          count+=2;
        }else{
          ++count;
        }
      }
    }

  }
  return count;

}




// Runtime: 4 ms, faster than 45.83% of C online submissions for Minimum Flips to Make a OR b Equal to c.
// Memory Usage: 6.8 MB, less than 100.00% of C online submissions for Minimum Flips to Make a OR b Equal to c.
// https://leetcode.com/submissions/detail/298397390/
