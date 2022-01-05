#include <iostream>
#include <iterator>
#include <regex>
#include <string>
using namespace std;

int main() {
  string raw;
  cin >> raw;
  regex filename_pattern_regex("(\\w+)");
  auto begin_path =
      sregex_iterator(raw.begin(), raw.end(), filename_pattern_regex);
  auto end_path = sregex_iterator();
  if (begin_path == end_path) { cout << "/"; }
  for (auto p = begin_path; p != end_path; ++p) {
    cout << '/' << p->str();
  }  // usr///local//nginx/sbin
  cout << "\n";
}

/**
 *
 * 30 ms	200 KB
 **/
