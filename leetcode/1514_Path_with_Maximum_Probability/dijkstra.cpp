// reference
// https://leetcode.com/problems/path-with-maximum-probability/discuss/731706/C%2B%2B-Modified-Djikstra-O(edges-*-log(n))-or-Max-Heap-or-Explanations
#include <queue>
#include <unordered_map>
#include <utility>  // pair
#include <vector>
using namespace std;
class Solution {
 public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &successor_prob, int start, int end) {
    // double access_prob[n]; // the access Probability of each node
    vector<double> access_prob(n);
    vector<unordered_map<int, double>> edges_weight(n);

    for (size_t i = 0; i < edges.size(); ++i) {
      edges_weight[edges[i][0]][edges[i][1]] = successor_prob[i];
      edges_weight[edges[i][1]][edges[i][0]] = successor_prob[i];
    }

    access_prob[start] = 1;
    priority_queue<pair<double, int>> heap;
    heap.push({ (double)1.0, start });
    int cur = start;

    while (!heap.empty() and cur != end) {
      pair<double, int> top = heap.top();
      heap.pop();
      double prob = top.first;
      int cur = top.second;

      for (pair<int, double> item : edges_weight[cur]) {
        int neighbor = item.first;
        double next_p = item.second;
        double new_p = prob * next_p;
        if (new_p > access_prob[neighbor]) {
          access_prob[neighbor] = new_p;
          heap.push({ access_prob[neighbor], neighbor });
        }
      }
    }
    return access_prob[end];
  }
};

// Runtime: 472 ms, faster than 77.99% of C++ online submissions for Path with
// Maximum Probability. Memory Usage: 73.8 MB, less than 6.52% of C++ online
// submissions for Path with Maximum Probability.
