> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [leetcode.com](https://leetcode.com/problems/binary-trees-with-factors/)

> Level up your coding skills and quickly land a job. This is the best place to expand your knowledge a......

Given an array of unique integers, `arr`, where each integer `arr[i]` is strictly greater than `1`.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return _the number of binary trees we can make_. The answer may be too large so return the answer **modulo** `109 + 7`.

**Example 1:**

```
[2], [4], [4, 2, 2]
```

**Example 2:**

```
[2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2]
```

**Constraints:**

*   `1 <= arr.length <= 1000`
*   `2 <= arr[i] <= 109`
*   All the values of `arr` are **unique**.