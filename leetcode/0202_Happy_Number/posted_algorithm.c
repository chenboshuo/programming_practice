// reference
// https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)
// explain
// https://leetcode.com/problems/happy-number/discuss/56919/Explanation-of-why-those-posted-algorithms-are-mathematically-valid
int sum_squares(int n) {
  int ans = 0;
  while (n) {
    int temp = n % 10;
    ans += temp * temp;
    n /= 10;
  }
  return ans;
}

bool isHappy(int n) {
  int fast = sum_squares(n);
  int slow = n;
  while (fast != slow) {
    fast = sum_squares(sum_squares(fast));
    slow = sum_squares(slow);
  }
  return fast == 1;
}
