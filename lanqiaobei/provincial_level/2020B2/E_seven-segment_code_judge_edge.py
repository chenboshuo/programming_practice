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

# 每个边需要检查的边构成的数码
edges = {       # gfedcba
    1:34,       # 0100010
    2:69,       # 1000101
    4:74,       # 1001010
    8:20,       # 0010100
    16:104,     # 1101000
    32:81,      # 1010001
    64:54       # 0110110
}

def edges_of(i):
    """get i's every binary digits

    :param i: num
    :type i: int
    """
    mask = 1
    while mask <= i:
        if(mask & i):
            yield mask
        mask <<= 1

def is_valid(cur_edges,check_edges):
    if (check_edges & cur_edges) == 0:
        return False
    cur_edges &= (~check_edges)
    if cur_edges == 0:
        return True
    # check the extra cases
    adjcent = edges[check_edges]
    valid = False
    # for i in edges_of(adjcent):
    #     valid |= is_valid(cur_edges,i)
    # return valid
    return any(is_valid(cur_edges,i) for i in edges_of(adjcent))


count = 0
# for case in range(1,4):
for case in range(1,128):
    # 注释掉的代码无法保证初始的边一定能遍历所有结果，
    # 如g,f,d,c c开始就无法到达d
    # edge = next(edges_of(case))
    # count += is_valid(case,edge)
    count += any(is_valid(case,edge) for edge in edges_of(case))
print(count)
# 80
