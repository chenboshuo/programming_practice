1288. Remove Covered Intervals
 [leetcode.com](https://leetcode.com/problems/remove-covered-intervals/)

Given a list of `intervals`, remove all intervals that are covered by another interval in the list.

Interval `[a,b)` is covered by interval `[c,d)` if and only if `c <= a` and `b <= d`.

After doing so, return _the number of remaining intervals_.

**Example 1:**

```text
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

**Example 2:**

```text
Input: intervals = [[1,4],[2,3]]
Output: 1
```

**Example 3:**

```text
Input: intervals = [[0,10],[5,12]]
Output: 2
```

**Example 4:**

```text
Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2
```

**Example 5:**

```text
Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1
```

**Constraints:**

*   `1 <= intervals.length <= 1000`
*   `intervals[i].length == 2`
*   `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
*   All the intervals are **unique**.
