# 1528. Shuffle String

Given a string `s` and an integer array `indices` of the **same length**.

The string `s` will be shuffled such that the character at the `ith` position moves to `indices[i]` in the shuffled string.

Return _the shuffled string_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/07/09/q1.jpg)

```
indices
```

**Example 2:**

```
indices
```

**Example 3:**

```
indices
```

**Example 4:**

```
indices
```

**Example 5:**

```
indices
```

**Constraints:**

*   `s.length == indices.length == n`
*   `1 <= n <= 100`
*   `s` contains only lower-case English letters.
*   `0 <= indices[i] < n`
*   All values of `indices` are unique (i.e. `indices` is a permutation of the integers from `0` to `n - 1`).
