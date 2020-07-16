> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [leetcode.com](https://leetcode.com/problems/number-of-good-pairs/)

Given an array of integers `nums`.

A pair `(i,j)` is called _good_ if `nums[i]` == `nums[j]` and `i` < `j`.

Return the number of _good_ pairs.

**Example 1:**

```
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
```

**Example 2:**

```
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: 0
```

**Constraints:**

*   `1 <= nums.length <= 100`
*   `1 <= nums[i] <= 100`