# 蓝桥杯2020校内赛

[*CodiMD 完整版*](https://demo.codimd.org/G2kYl_1RQKKoTcvD6FUoXw)

## 辅元辅元单词

### 问题描述
　　小明对类似于 `hello` 这种单词非常感兴趣，这种单词可以正好分为四段，第一段由一个或多个辅音字母组成，第二段由一个或多个元音字母组成，第三段由一个或多个辅音字母组成，第四段由一个或多个元音字母组成。

　　给定一个单词，请判断这个单词是否也是这种单词，如果是请输出yes，否则请输出no。
　　元音字母包括 a, e, i, o, u，共五个，其他均为辅音字母。
#### 输入格式
　　输入一行，包含一个单词，单词中只包含小写英文字母。
#### 输出格式
　　输出答案，或者为yes，或者为no。
#### 样例输入
lanqiao
#### 样例输出
yes
#### 样例输入
world
#### 样例输出
no
#### 评测用例规模与约定
　　对于所有评测用例，单词中的字母个数不超过100。
### 代码
```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int alpha[256] = {0};
  alpha['a'] = 1;
  alpha['e'] = 1;
  alpha['i'] = 1;
  alpha['o'] = 1;
  alpha['u'] = 1;

  char s[100];
  scanf("%s", s);

  int i = 0;
  int part1 = 0, part2 = 0, part3 = 0, part4 = 0;

  while (s[i] && alpha[s[i]] == 0) {
    ++i;
    part1 = 1;
  }
  while (s[i] && alpha[s[i]] == 1) {
    ++i;
    part2 = 1;
  }
  while (s[i] && alpha[s[i]] == 0) {
    ++i;
    part3 = 1;
  }
  while (s[i] && alpha[s[i]] == 1) {
    ++i;
    part4 = 1;
  }
  if (!s[i] && part1 && part2 && part3 && part4) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return 0;
}
```

## 递增的数
### 问题描述
　　一个正整数如果任何一个数位不大于右边相邻的数位，则称为一个数位递增的数，例如1135是一个数位递增的数，而1024不是一个数位递增的数。
　　给定正整数 n，请问在整数 1 至 n 中有多少个数位递增的数？
输入格式
　　输入的第一行包含一个整数 n。
输出格式
　　输出一行包含一个整数，表示答案。
#### 样例输入
30
#### 样例输出
26
#### 评测用例规模与约定
```plt
　　对于 40% 的评测用例，1 <= n <= 1000。
　　对于 80% 的评测用例，1 <= n <= 100000。
　　对于所有评测用例，1 <= n <= 1000000。
```

### 代码
```c=
#include <stdio.h>

int is_incerse(int num) {
  int pre = 10;
  int cur;
  while (num) {
    if ((cur = num % 10) > pre) {
      return 0;
    }
    pre = cur;
    num /= 10;
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int i, count = 0;
  for (i = 1; i <= n; ++i) {
    if (is_incerse(i)) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
```

## 递增三元组
### 问题描述
　　在数列 `a[1], a[2], ..., a[n]` 中，如果对于下标 `i, j, k` 满足 `0<i<j<k<n+1` 且
`a[i]<a[j]<a[k]`，则称 `a[i], a[j], a[k]` 为一组递增三元组，`a[j]`为递增三元组的中心。
　　给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
输入格式
　　输入的第一行包含一个整数 n。
　　第二行包含 n 个整数 `a[1], a[2], ...,
a[n]`，相邻的整数间用空格分隔，表示给定的数列。 输出格式
　　输出一行包含一个整数，表示答案。
#### 样例输入
```plt
5
1 2 5 3 5
```
#### 样例输出
2
#### 样例说明
　　`a[2]` 和 `a[4]` 可能是三元组的中心。
#### 评测用例规模与约定
对于 50% 的评测用例，2 <= n <= 100，0 <= 数列中的数 <= 1000。
对于所有评测用例，2 <= n <= 1000，0 <= 数列中的数 <= 10000。

### 我的思路
$$
\exists i<j<k , a_i< a_j < a_k
$$
$$
\exists i<j<k  ,(a_i< a_j) \wedge( a_j< a_k)
$$
若$a_j$ 不是递增三元组中心, 需要满足
$$
\forall i<j ,a_i \ge a_j
$$
或
$$
\forall j<k, a_j \ge a_k
$$

如果$a_j$ 是前$j$ 项的最小值, 是后项的最大值, 他就不可能是三元组中心.

### 代码
```c=
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int nums_size;
  scanf("%d", &nums_size);

  int nums[nums_size];
  int i;
  for (i = 0; i < nums_size; ++i) {
    scanf("%d", &nums[i]);
  }

  int min_of_before[nums_size];
  int max_of_after[nums_size];

  int min = nums[0];
  for (i = 0; i < nums_size; ++i) {
    if (nums[i] <= min) {
      min = nums[i];
      min_of_before[i] = 1;
    } else {
      min_of_before[i] = 0;
    }
  }

  int max = nums[nums_size - 1];
  for (i = nums_size - 1; i >= 0; --i) {
    if (nums[i] >= max) {
      max = nums[i];
      max_of_after[i] = 1;
    } else {
      max_of_after[i] = 0;
    }
  }

  int count = 0;
  for (i = 0; i < nums_size; ++i) {
    if (!min_of_before[i] && !max_of_after[i]) {
      ++count;
    }
  }

  printf("%d\n", count);

  return 0;
}
```

## 草地
### 问题描述
　　小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
　　请告诉小明，k 个月后空地上哪些地方有草。
#### 输入格式
　　输入的第一行包含两个整数 n, m。
接下来 n 行，每行包含 m
个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为
g，表示种了草。 　　接下来包含一个整数 k。 输出格式 　　输出 n 行，每行包含 m
个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为
g，表示长了草。
#### 样例输入
```plt
4 5
.g...
.....
..g..
.....
2
```
#### 样例输出
```plt
gggg.
gggg.
ggggg
.ggg.
```
#### 评测用例规模与约定
```plt
　　对于 30% 的评测用例，2 <= n, m <= 20。
　　对于 70% 的评测用例，2 <= n, m <= 100。
　　对于所有评测用例，2 <= n, m <= 1000，1 <= k <= 1000。
```

### 我的思路
$$
a_{ij}
\begin{cases}
1 & a_{ij} 有草 \\
0 & a_{ij} 无草
\end{cases}
$$
每一行可表示为
$$
a_i = (a_{i1}a_{i_2} \dots a_{in})_2
$$

左边长草可以表示为
```c
a[i] |= (a[i] << 1)
```
注意
-  保存好上一个状态
-  最后要控制溢出
```c
a[i] &= M
```
$$
M = (\underbrace{111 \dots 11}_n)_2
$$

### 代码
```c=
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i, j;
  int m = 4;
  int n = 5;
  scanf("%d %d\n", &m, &n);

  int max_col = (1 << n) - 1;
  int grass[m + 1];  // bit 1 grass
  char c;
  int temp = 0, pre = 0;

  // input
  for (i = 0; i < m; ++i) {
    grass[i] = 0;
    for (j = 0; j < n; ++j) {
      c = getchar();
      grass[i] = (grass[i] << 1) + (c == 'g');
    }
    getchar();
    // printf("%d\n", grass[i]);
  }
  grass[m] = 0;

  int t;
  scanf("%d", &t);
  while (t--) {
    for (i = 0; i < m; ++i) {
      temp = grass[i];
      grass[i] |= pre;
      pre = temp;
      grass[i] |= (temp << 1);
      grass[i] |= (temp >> 1);
      grass[i] |= (grass[i + 1]);
      grass[i] &= max_col;  // handle overflow
      // printf("%d\n", grass[i]);
    }
  }

  for (i = 0; i < m; i++) {
    for (j = (1 << (n - 1)); j > 0; j >>= 1) {
      if (grass[i] & j) {
        printf("g");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  return 0;
}
```

## 数列
#### 问题描述
小明想知道，满足以下条件的正整数序列的数量：
1. 第一项为 n；
2. 第二项不超过 n；
3. 从第三项开始，每一项小于前两项的差的绝对值。

请计算，对于给定的 n，有多少种满足条件的序列。
#### 输入格式
　　输入一行包含一个整数 n。
#### 输出格式
　　输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
#### 样例输入
4
#### 样例输出
7
#### 样例说明
　　以下是满足条件的序列：
```plt
　　4 1
　　4 1 1
　　4 1 2
　　4 2
　　4 2 1
　　4 3
　　4 4
 ```
评测用例规模与约定
```plt
　　对于 20% 的评测用例，1 <= n <= 5；
　　对于 50% 的评测用例，1 <= n <= 10；
　　对于 80% 的评测用例，1 <= n <= 100；
　　对于所有评测用例，1 <= n <= 1000。
```

## 节目

### 问题描述
　　小明要组织一台晚会，总共准备了 n
个节目。然后晚会的时间有限，他只能最终选择其中的 m 个节目。 　　这 n
个节目是按照小明设想的顺序给定的，顺序不能改变。
　　小明发现，观众对于晚上的喜欢程度与前几个节目的好看程度有非常大的关系，他希望选出的第一个节目尽可能好看，在此前提下希望第二个节目尽可能好看，依次类推。
　　小明给每个节目定义了一个好看值，请你帮助小明选择出 m 个节目，满足他的要求。
输入格式
　　输入的第一行包含两个整数 n, m ，表示节目的数量和要选择的数量。
　　第二行包含 n 个整数，依次为每个节目的好看值。
输出格式
　　输出一行包含 m 个整数，为选出的节目的好看值。
#### 样例输入
```plt
5 3
3 1 2 5 4
```
#### 样例输出
```plt
3 5 4
```
#### 样例说明
　　选择了第1, 4, 5个节目。
#### 评测用例规模与约定
```plt
　　对于 30% 的评测用例，1 <= n <= 20；
　　对于 60% 的评测用例，1 <= n <= 100；
　　对于所有评测用例，1 <= n <= 100000，0 <= 节目的好看值 <= 100000。
```

### 思路
应该就是排序两次吧
```plt
3 1 2 5 4 <- 给数值排序
0 1 2 3 4
```
```plt
5 4 3 2 1
3 4 0 2 1

```
取前三个
```plt
5 4 3
3 4 0 <- 按索引排序
```

```
3 5 4
0 3 4
```

### 代码
```c=
#include <stdio.h>
#include <stdlib.h>

struct item {
  long value;
  long index;
};

// decrease sort by value
int by_value(void *a, void *b) {
  return ((struct item *)b)->value - ((struct item *)a)->value;
}

int by_index(void *a, void *b) {
  return ((struct item *)a)->index - ((struct item *)b)->index;
}

int main(int argc, char const *argv[]) {
  long total, select;
  long i;
  scanf("%ld %ld\n", &total, &select);

  struct item items[total];
  for (i = 0; i < total; ++i) {
    scanf("%ld", &items[i].value);
    items[i].index = i;
  }
  qsort(items, total, sizeof(struct item), by_value);

  // for (i = 0; i < total; ++i) {
  //   printf("(i=%d,v=%d )\n", items[i].index, items[i].value);
  // }
  // printf("\n");

  qsort(items, select, sizeof(struct item), by_index);
  for (i = 0; i < select; ++i) {
    printf("%ld ", items[i].value);
  }
  printf("\n");

  return 0;
}
```
