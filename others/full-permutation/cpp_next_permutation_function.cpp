#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int *a = new int[n];
  for(int i = 0; i < n; ++i){
    a[i] = i+1;
  }
  do {
    for(int i = 0; i < n; ++i){
      cout << a[i] << " ";
    }
    cout << endl;
  } while(next_permutation(a, a+n));
  return 0;
}
