# ## C 蛇形填数
# 本题总分：10 分

# ### 问题描述

# 如下图所示，
# 小明用从1 开始的正整数“蛇形”填充无限大的矩阵。
# 1   2   6   7   15
# 3   5   8   14
# 4   9   13
# 10  12
# 11

# 容易看出矩阵第二行第二列中的数是5。请你计算矩阵中第20 行第20 列的数是多少？

SIZE = 45
m = [[0]* SIZE for _ in range(SIZE)]

num = 1 # 填入的数字
s = 2 # 横纵坐标的和
while s+1 < SIZE:
    for j in range(1,s): # 一开始纵坐标增大
        i = s - j
        m[i][j] = num
        num += 1
    s += 1
    for j in reversed(range(1,s)):
        i = s-j
        m[i][j] = num
        num += 1
    s += 1

view = 5
for i in range(view):
    print(*m[i][:view],sep="\t")

# 0       0       0       0       0
# 0       1       2       6       7
# 0       3       5       8       14
# 0       4       9       13      18
# 0       10      12      19      25

print(m[20][20])
# 761

for i in range(1,20):
    print(m[i][i]-m[i-1][i-1],end=" ")
# 1 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72