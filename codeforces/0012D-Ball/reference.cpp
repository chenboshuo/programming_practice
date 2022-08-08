// https://www.quora.com/How-do-I-solve-Ball-12D-on-CodeForces
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

#define all(v) (v).begin() + 1, (v).end()
#define LEFT(n) (2 * n)
#define RIGHT(n) (2 * n + 1)

using namespace std;

const int MAX_N = 5e5 + 15;
int max_tree[3 * MAX_N];

struct info {
  int beauty, richness, intelligence;
};

int sort_by_beauty(info &a, info &b) { return (a.beauty < b.beauty); }

void insert_richness(int n, int left, int right, int index, int value) {
  if (index < left || right < index) { return; }

  if (left == right) {
    max_tree[n] = max(max_tree[n], value);
    return;
  }

  int mid = (left + right) >> 1;
  insert_richness(LEFT(n), left, right, index, value);
  insert_richness(RIGHT(n), mid+1, right, index, value);

  max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
}

int get_max_richness(int n, int left, int right, int query_left,
                     int query_right) {
  if (right < query_left || query_right < left || right < left) { return 0; }
  if (query_left <= left && right <= query_right) { return max_tree[n]; }

  int mid = (left + right) >> 1;
  int left_max = get_max_richness(LEFT(n), left, mid, query_left, query_right);
  int right_max = get_max_richness(RIGHT(n),mid+1, right, query_left,query_right);

  return max(left_max, right_max);
}

int main() {
  int no_of_ladies;
  scanf("%d", &no_of_ladies);

  vector<info> lady(no_of_ladies);
  for (int i = 1; i <= no_of_ladies; ++i) scanf("%d", &lady[i].beauty);
  for (int i = 1; i <= no_of_ladies; ++i) scanf("%d", &lady[i].richness);
  for (int i = 1; i <= no_of_ladies; ++i) scanf("%d", &lady[i].intelligence);

  sort(all(lady), sort_by_beauty);

  vector<int> intelligence(no_of_ladies, 0);
  for (int i = 1; i <= no_of_ladies; ++i)
    intelligence[i] = lady[i].intelligence;

  sort(all(intelligence));
  map<int, int> iq_rank;

  for (int i = 1; i <= no_of_ladies; ++i) {
    iq_rank[intelligence[i]] =
        (intelligence[i] == intelligence[i - 1] ? iq_rank[intelligence[i - 1]]
                                                : i);
  }

  memset(max_tree, 0, sizeof(max_tree));

  int suicides = 0;
  for (int i = no_of_ladies; i >= 1;) {
    int j;

    for (int j = i; j >= 1 && lady[i].beauty == lady[j].beauty; --j) {
      int max_richness_with_other_2_greater = get_max_richness(
          1, 1, no_of_ladies, iq_rank[lady[j].intelligence] + 1, no_of_ladies);
      if (max_richness_with_other_2_greater > lady[i].richness) { ++suicides; }
    }
  }
}
