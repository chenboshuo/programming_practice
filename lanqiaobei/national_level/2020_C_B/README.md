# 蓝桥杯2020国赛C、C++ B组
## 目录 :clipboard:

-   [A 美丽的 2](#A-美丽的-2)
-   [B 扩散](#B-扩散)
-   [C 阶乘约数](#-C-阶乘约数)

## A 美丽的 2

### 题目

小蓝特别喜欢 2，今年是公元 2020 年，他特别高兴。
他很好奇，在公元 1 年到公元 2020 年（包含）中，有多少个年份的数位中包含数字 2？

### 我的答案
```plt
563
```
-   [python 代码](./A_beautiful_2.py)

## B 扩散

### 问题描述
小蓝在一张无限大的特殊画布上作画。
这张画布可以看成一个方格图，每个格子可以用一个二维的整数坐标表示。
小蓝在画布上首先点了一下几个点：
(0, 0), (2020, 11), (11, 14), (2000, 2000)。
只有这几个格子上有黑色，其它位置都是白色的。
每过一分钟，黑色就会扩散一点。具体的，如果一个格子里面是黑色，它
就会扩散到上、下、左、右四个相邻的格子中，使得这四个格子也变成黑色
（如果原来就是黑色，则还是黑色）。
请问，经过 2020 分钟后，画布上有多少个格子是黑色的

### 我的答案
20312088
### 代码
-   [区分内点和边界点](./B_spread.py)
```plt
python B_spread.py  94.97s user 4.04s system 58% cpu 2:49.59 total
```
-   [曼哈顿距离(方格距离)](./B_spread_Manhattan_distance.c)

```plt
0.14s user 0.00s system 98% cpu 0.146 total
```

## 试题 C 阶乘约数

### 问题描述
定义阶乘 n! = 1 × 2 × 3 × · · · × n。
请问 100! （100 的阶乘）有多少个约数。

### 我的分析

-  [公式渲染(github不支持latex，这里仅供备份)](https://demo.hedgedoc.org/zxlG6B8HReu6b-EO6vUuzA)

```markdown
设
$100!
= p_{1}^{n_{1}} p_{2}^{n_{2}}
\cdots p_{m}^{n_{m}}$

1. $p_i(i=1,\dots,m) \leq 100$
证明：
假设$\exists i,p_i > 100$
由于$p_i | 100!$,
$\exists n \in \{1,2,\dots,100\}$,
$p_i | n$,
$p_i \leq n_i \leq 100$,与假设矛盾

2. 求$n_i(i=1,\dots,m)$
设 $k=\prod_{i=1}^{n} p_i^{n^{(k)}_i}$
$$
  \begin{aligned}
    100! &= \prod_{k=1}^{100} k \\
      &= \prod_{k=1}^{100}
        \prod_{i=1}^{n} p_i^{n^{(k)}_i} \\
      &= \prod_{i=1}^{n} p_i^{n_i} \\
  \end{aligned}
$$
其中
$$
n_i = \sum_{k=1}^{100} n_i^{k}
$$
3. 最终100!的所有因数为 $\prod_{i=1}^m (1+n_i)$
```

### 我的答案
```plt
39001250856960000
```

-   [C_factors.py](./C_factors.py)


## 参考
-   [2020第十一届蓝桥杯大赛软件类国赛题目 C/C++ B 组](https://blog.csdn.net/weixin_43985130/article/details/109695805)
-   [第十一届蓝桥杯国赛C语言组B类B题扩散](https://blog.csdn.net/bdu_zhangAo/article/details/109715079)
-   [第十一届蓝桥杯国赛C++B组C题阶乘约数](https://blog.csdn.net/Steve_Liu12399/article/details/109731270)
