# s = 'lanqiao'
s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhf"\
"iadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqij"\
"gihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmad"\
"vrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl"

# 记录每个字母出现的位置
loc = [[] for i in range(26)]
for i,c in enumerate(s):
    loc[ord(c)-ord('a')].append(i)
# print(loc)

def search(begin_index, pre_loc) -> int:
    """递归搜索函数

    分别计算选中该字母和选不中该字母两种情况

    :param begin_index: 开始的字母在loc中的索引
    :param pre_loc: 当前字符串的所在序列
    :return: 总数
    """
    if begin_index == 26:
        return 1
    total = search(begin_index+1,pre_loc) # 跳过当前字母
    for cur_loc in loc[begin_index]:
        if cur_loc > pre_loc:
            total += search(begin_index+1,cur_loc)
            break # 如果选定当前字母，取最小的一个，防止之后计数的重复
    return total

print(search(0,-1)-1) # 最后结果减去空串
# 3616159
