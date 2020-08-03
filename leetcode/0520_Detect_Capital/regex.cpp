#include <regex>
#include <string>

using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    const regex pattern("[A-Z]*|.[a-z]*");
    return regex_match(word, pattern);
  }
};

// Runtime: 276 ms, faster than 50.58% of C++ online submissions for Detect
// Capital. Memory Usage: 32.7 MB, less than 6.98% of C++ online submissions for
// Detect Capital.
