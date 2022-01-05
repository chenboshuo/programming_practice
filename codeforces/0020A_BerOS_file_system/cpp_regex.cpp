#include <string>
#include <iostream>
#include <regex>
#include <iterator>
using namespace std;

int main(){
  string raw;
  cin >> raw;
  regex filename_pattern_regex("(\\w+)");
  auto begin_path = sregex_iterator(raw.begin(),raw.end(),filename_pattern_regex);
  auto end_path = sregex_iterator(); 
  for(auto p = begin_path;p!=end_path;++p){
    cout << '/' << p->str();
  }//usr///local//nginx/sbin
  cout << "\n";
}

/**
 * 
 * Test: #4, time: 0 ms., memory: 136 KB, exit code: 0, checker exit code: 2, verdict: WRONG_ANSWER
 * Input
 * /
 * Output
 * 
 * Answer
 * /
 * Checker Log
 * wrong output format Unexpected end of file - token expected
**/
