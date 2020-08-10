// reference
// https://leetcode.com/problems/water-bottles/discuss/743148/JavaPython-3-O(logN)-and-O(1)-codes-w-brief-explanation-and-analysis.
int numWaterBottles(int numBottles, int numExchange) {
  return numBottles + (numBottles - 1) / (numExchange - 1);
}

// time: 0 ms, faster than 100.00% of C online submissions for Water Bottles.
// Memory Usage: 5 MB, less than 89.84% of C online submissions for Water
// Bottles. Next challenges:
