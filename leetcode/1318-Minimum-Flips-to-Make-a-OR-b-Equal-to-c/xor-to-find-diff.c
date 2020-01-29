int minFlips(int a, int b, int c){
  int ans = a | b;
  int delta = ans ^ c;
  int count = 0;
  while(delta){
    if(delta % 2 == 1){
      if(c % 2 == 1){
        ++ count;
      }else{
        count += 2;
      }
    }
    c >>= 1;
    delta >>= 1;
  }
  return count;
}



// 9 / 64 test cases passed.
// Status: Wrong Answer
// Submitted: 2 weeks, 3 days ago
// Input:
// 8
// 3
// 5
// Output:
// 5
// Expected:
// 3
// https://leetcode.com/contest/weekly-contest-171/submissions/detail/293403612/
