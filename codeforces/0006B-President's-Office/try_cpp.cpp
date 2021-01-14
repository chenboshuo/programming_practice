#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int length, width;

void count(set<char> &different_color, string lines[], int i, int j) {
  if (i < length && i >= 0 && j >= 0 && j < width) {
    different_color.insert(lines[i][j]);
  }
}

void adjcent(set<char> &different_color, string lines[], int i, int j) {
  count(different_color, lines, i - 1, j);
  count(different_color, lines, i + 1, j);
  count(different_color, lines, i, j - 1);
  count(different_color, lines, i, j + 1);
}

int main(int argc, char const *argv[]) {
  // int length, width;
  char color;
  scanf("%d %d %c", &length, &width, &color);
  // char lines[length][width];
  // vector<string> lines(length,width);
  string lines[length];
  for (int i = 0; i < length; ++i) {
    // scanf("%s",lines[i]);
    cin >> lines[i];
  }

  set<char> different_color;

  different_color.insert(color);
  different_color.insert('.');

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < width; ++j) {
      if (lines[i][j] == color) {
        adjcent(different_color, lines, i, j);
        // printf("hit");
      }
    }
  }

  printf("%ld\n", different_color.size() - 2);

  return 0;
}
// 46 ms	1000 KB
