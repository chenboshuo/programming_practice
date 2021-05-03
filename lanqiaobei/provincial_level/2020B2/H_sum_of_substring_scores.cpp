/**
 * 对于一个子串，
 * 同一字母出现多次视为第一个字母分数的贡献
 * 由此计算每一个字符对字符串贡献的点数。
 *
 * (a)b)a)b)c)
 *  ↑
 * 1*5            5
 * a(b(a)b)c)
 *     ↑ 要保证这个a第一次出现
 *   2 * 3        6
 * (a(b)a)b)c)
 *    ↑
 *   2*4          8
 * ab(a(b)c)
 *      ↑
 *    2 * 2       4
 * (a(b(a(b(c)
 *          ↑
 *         5*1    5
 * 最终我们得到这样的信息
 * a: 1,2,3
 * b: 2,2,2
 * c: 5,1
 * 需要计算 1*(2+3) + 2*3,
 * 每个数需要与后边的数想加，
 * 存储累计的值可以简化运算
 */

#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

struct info {
  // int total=0;
  int cur = 0;      // 当前的端点位置
  vector<int> loc;  // 可能的边界点
};

int main() {
  int loc = 1;
  char c;
  unordered_map<char, struct info> summary;
  while ((c = getchar()) != EOF) {
    summary[c].loc.push_back(loc);  // loc  为当前段的位置
    summary[c].cur = loc;
    ++loc;
  }
  long long score = 0;
  unordered_map<char, struct info>::iterator it = summary.begin();
  while (it != summary.end()) {
    it->second.loc.push_back(loc);
    int first_len = it->second.loc[0];
    score += (first_len * (loc - first_len));  // 第一次出现，计算所有的贡献分数
    for (int i = 1; i < it->second.loc.size() - 1; ++i) {
      int cur_len =
          (it->second.loc[i]) - (it->second.loc[i - 1]);  // 表示当前段长
      // 在当前字母出现的长度，表示子串可能开始的可能数
      int right_len = loc - (it->second.loc[i]);
      // 在该字母右边的所有结束点可能数，该字母在这些串第一次出现，所以都是其贡献
      // printf("%d\n",right_len);
      score += (cur_len * right_len);
    }
    ++it;
  }

  printf("%lld", score);

  return 0;
}

// test1 passed(1.6629729980195407 ms)
// test2 passed(1.7400860015186481 ms)
// test3 passed(27.401542000006884 ms)
