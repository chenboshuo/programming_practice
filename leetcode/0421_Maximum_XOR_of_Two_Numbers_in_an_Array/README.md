# 421.Maximum XOR of Two Numbers in an Array

[leetcode.com](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

Given an integer array `nums`, return _the maximum result of `nums[i] XOR nums[j]`_, where `0 ≤ i ≤ j < n`.

**Follow up:** Could you do this in `O(n)` runtime?

**Example 1:**

```text
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
```

**Example 2:**

```text
Input: nums = [0]
Output: 0
```

**Example 3:**

```text
Input: nums = [2,4]
Output: 6
```

**Example 4:**

```text
Input: nums = [8,10,2]
Output: 10
```

**Example 5:**

```text
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
```

**Constraints:**

*   `1 <= nums.length <= 2 * 104`
*   `0 <= nums[i] <= 231 - 1`
