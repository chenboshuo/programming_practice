# 28. Implement strStr()
[题目](https://leetcode.com/problems/implement-strstr/)
Easy


Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
```plaintext
Input: haystack = "hello", needle = "ll"
Output: 2
```
Example 2:
```plaintext
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```
**Clarification**:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

## 参考
### KMP算法
-   [Knuth-Morris-Pratt algorithm](http://www.inf.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm)
-   [动画：七分钟理解什么是KMP算法](https://mp.weixin.qq.com/s?__biz=MzUyNjQxNjYyMg==&mid=2247485939&idx=1&sn=b25f39b5644da92c4047bbbd9936f73c&chksm=fa0e6672cd79ef64dda0a21e23c2817edf4a64cbb75b9bed328d6519c6cd4fef36d03a4cb309)
