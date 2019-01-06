# 每周一题之6 快速过桥
- [微信原文](https://mp.weixin.qq.com/s?__biz=MzU2NjEwMTc5MQ==&mid=2247483745&idx=2&sn=0ad9f7b35de529368a9bcad35af06a5c&chksm=fcb0d311cbc75a0735418fcd145501662ea5800766f82ccbcb64d39893e2a520a0541124ba86&mpshare=1&scene=23&srcid=0106rr1psznzde1TqtoSKa2K#rd)

PC/UVa IDs: 110403/10037,

Popularity: B,

Success rate: low Level: 3

测试地址：https://vjudge.net/problem/UVA-10037

[问题描述]
A group of n people wish to cross a bridge at night.
n个人的队伍想在晚上通过一座大桥。

At most two people may cross at any time, and each group must have a flashlight.
任何时间最多有2人通过，每组必须有一个手电筒。

Only one flashlight is available among the n people, so some sort of shuttle arrangement must be arranged in order to return the flashlight so that more people may cross.
很可怜，这n个人只有一个手电筒可用，因此必须合理地安排，让手电筒能回到另一端，这样才能让更多人通过大桥。

Each person has a different crossing speed; the speed of a group is determined by the speed of the slower member.
每个人有不同的速度，编组后，一个组的速度等于慢的那个人的速度。

Your job is to determine a strategy that gets all n people across the bridge in the minimum time.
你的任务是实现一种策略，让所有人在最短时间内通过。

[输入]
The input begins with a single positive integer on a line by itself indicating the number of test cases, followed by a blank line. There is also a blank line between each two consecutive inputs.
第一行是一个单独的数字，代表测试案例的个数；随后是一个空行。后面每两个输入之间都有一个空行。

The first line of each case contains n, followed by n lines giving the crossing times for each of the people. There are not more than 1,000 people and nobody takes more than 100 seconds to cross the bridge.
每个测试案例的第一行是n的值，随后n行是每个人单独通过大桥的时间。人数≤1000，时间≤100s

【输出】
For each test case, the first line of output must report the total number of seconds required for all n people to cross the bridge.
对每个案例，首行是n个人通过的时间。

Subsequent lines give a strategy for achieving this time. Each line contains either one or two integers, indicating which person or people form the next group to cross.
随后是你的通过和返回次序，每一行是一个或者两个整数，对应着人（通过时间代表人）。返回也要占一行。

Each person is indicated by the crossing time specified in the input.Although many people may have the same crossing time, this ambiguity is of no consequence.
虽然不同的人可能有相同的速度，但这没有影响（看做一种人就好了）。

Note that the crossings alternate directions, as it is necessary to return the flashlight so that more may cross.
注意方向，意思就是说返回情况也要占一行。

If more than one strategy yields the minimal time, any one will do.
多种方案都是最短时间的，任选其一皆可。

The output of two consecutive cases must be separated by a blank line.
案例之间空行分界。
```
【样例输入】
1

4
1
2
5
10

【样例输出】
17
1 2
1
5 10
2
1 2

【解释】
17    秒
1 2   2秒
1     1秒
5 10  10秒
2     2秒
1 2   2秒
```
## 我的思路
速度最快的先通过或返回
