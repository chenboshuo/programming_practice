# 题目 翻煎饼

PC/UVa IDs: 110402/120,
Popularity: B, Success rate:high Level: 2
测试地址：
https://vjudge.net/problem/UVA-120

[问题描述]（老师已经为宝宝们翻译好啦）
Stacks and Queues are often considered the bread andbutter of data structures
and find use in architecture, parsing,operating systems,
 and discrete event simulation.Stacks are also important in thetheory of formal languages.
堆栈和队列通常被认为是数据结构的面包和黄油，可用于体系结构、解析，操作系统和离散事件模拟。堆栈在形式语言
理论中也很重要。

This problem involves both butter and sustenance inthe form of pancakes rather
 than bread in addition to a finicky server who flips pancakesaccording to a unique, but
 complete set of rules.
现在的问题涉及黄油和煎饼(而不是面包)，同时还有一个根据唯一但完整的规则来翻煎饼的服务器。

Given a stack of pancakes, you are to write a programthat indicates how the stack can be sorted
so that the largest pancake is on the bottom and thesmallest pancake is on the top.
给你一栈的煎饼，请你编写一个程序用于指示这个栈如何被排序以使得最大的煎饼在最下面而最小的煎饼在最上面。

The size of a pancake is given by the pancake’sdiameter.
煎饼的直径将被给出。

All pancakes in a stack have different diameters.
栈中的所有煎饼的直径都不一样。

Sorting a stack is done by a sequence of pancake“flips”.
对栈排序是通过一系列"翻转"来完成的。

A flip consists of inserting a spatula between twopancakes in a stack
and flipping (reversing) all the pancakes on thespatula (reversing the sub-stack).
一次翻转的意思是：在两个煎饼之间插入铲子，然后将铲子上面的一堆煎饼整体翻过来。
也就是指定一个位置，其上的子栈整体翻转。

A flip is specified by giving the position of thepancake on the bottom of the sub-stack to
be flipped (relative to the whole stack).
翻转的位置将会被给出。

The pancake on the bottom of the whole stack hasposition 1
and the pancake on the top of a stack of n pancakeshas position n.
位置是这样定义的：栈底编号为1，栈顶编号为n

A stack is specified by giving the diameter of eachpancake in the stack in the order in which
the pancakes appear.
一个栈的煎饼的给出方式，是从上到下给出煎饼的直径。

For example, consider the three stacks of pancakesbelow (in which pancake 8 is the top-most
pancake of the left stack):
举例来说，这是三个栈，左边的栈的最上面的煎饼直径为8
8 7 2
4 6 5
6 4 8
7 8 4
5 5 6
2 2 7

The stack on the left can be transformed to the stackin the middle via flip(3).
The middle stack can be transformed into the right stack via the commandflip(1).
左侧栈，可在位置3（即直径7）处翻转，得到中间的那个栈，
而中间那个栈可在位置1（即直径2）处翻转，得到右侧的栈。

Input（输入）
The input consists of a sequence of stacks ofpancakes.
Each stack will consist of between 1 and 30 pancakes and each pancake
will have an integerdiameter between 1 and 100. The input is terminated by end-of-file.
Each stack is given as a single lineof input with the top pancake on a stack appearing
first on a line, the bottom pancake appearing last,and all pancakes separated by a space.
输入由多个煎饼栈组成。每个栈有1到30个煎饼，每个煎饼的直径在1-100之间。以文档结束为输入结束。
每个栈，独占一行，从左到右依次代表从栈顶到栈底的煎饼的直径，空格隔开。

Output（输出）
For each stack of pancakes, the output should echo theoriginal stack on one line, followed by
some sequence of flips that results in the stack ofpancakes being sorted so that the largest
diameter pancake is on the bottom and the smallest on top. For eachstack the sequence of flips
 should be terminated by a ‘0’ (indicating no more flips necessary). Once astack is sorted, no
 more flips should be made.
对于每个煎饼栈，输出首先应原样将栈的数据打印成一行。
随后的一行是翻转位置的次序，空格隔开，以0结束。（结束的目标是最大直径在最下面，最小直径在最上面）。
```
Sample Input
1 2 3 4 5
5 4 3 2 1
5 1 2 3 4
Sample Output
1 2 3 4 5
0
5 4 3 2 1
1 0
5 1 2 3 4
1 2 0
```


# **我的思路**
寻找最大值,然后翻到第一位(如果最大值在第一位,跳过)
然后将最大值放到对应位置
