# 全排列问题

## 题目描述
输出自然数1到n所有不重复的排列，即n的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

## 输入
包含多组测试数据，每组测试数据包含一个正整数n(1≤n≤9)。

## 输出
由1～n组成的所有不重复的数字序列，每行一个序列。

## 样例输入
3

## 样例输出
```plt
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

## 相关库
python 的 [itertools.permutations(iterable, r=None)](https://docs.python.org/3/library/itertools.html#itertools.permutations)函数

c++ 的 [next_permutation](http://www.cplusplus.com/reference/algorithm/next_permutation/)函数
