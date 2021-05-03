# 小蓝要用七段码数码管来表示一种特殊的文字。

#     a
# --------
# |      |
# | f    | b
# |   g  |
# --------
# |      |
# |e     | c
# |      |
# --------
#     d

# 上图给出了七段码数码管的一个图示，
# 数码管中一共有7 段可以发光的二极管，
# 分别标记为a, b, c, d, e, f, g。
# 小蓝要选择一部分二极管（至少要有一个）发光来表达字符。
# 在设计字符的表达时，
# 要求所有发光的二极管是连成一片的。
# 例如：b 发光，其他二极管不发光可以用来表达一种字符。
# 例如：c 发光，其他二极管不发光可以用来表达一种字符。
# 这种方案与上一行的方案可以用来表示不同的字符，
# 尽管看上去比较相似。
# 例如：a, b, c, d, e 发光，
# f, g 不发光可以用来表达一种字符。
# 例如：b, f 发光，其他二极管不发光则不能用来表达一种字符，
# 因为发光的二极管没有连成一片。
# 请问，小蓝可以用七段码数码管表达多少种不同的字符？
from collections import defaultdict

edges = {
    1:(0,1),
    2:(1,3),
    4:(3,5),
    8:(4,5),
    16:(2,4),
    32:(0,2),
    64:(2,3)
}

def check(nodes):
    single = 0
    for i in nodes.values():
        if i == 1:
            single += 1
    return (single <= 3) # 大多数情况

count = 0
for case in range(1,128):
    nodes = defaultdict(int)
    mask = 1
    while case >= mask:
        if (case & mask):
            edge = edges[mask]
            nodes[edge[0]] += 1
            nodes[edge[1]] += 1
        mask <<= 1
    # print(bin(case))
    count += bool(check(nodes))

print(count)
# 81

# add the case H
# delete
#  ----   |----|
#         |    |
# |----|  |----|
# |    |
# |----|   ----
