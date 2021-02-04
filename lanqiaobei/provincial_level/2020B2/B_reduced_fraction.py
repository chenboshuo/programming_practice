## B 既约分数

# 如果一个分数的分子和分母的最大公约数是1，
# 这个分数称为既约分数。
# 例如，`3/4` , `5/2` , `1/8` , `7/1`都是既约分数。
# 请问，有多少个既约分数，
# 分子和分母都是`1` 到`2020` 之间的整数（包括`1`和`2020`）？
from itertools import product

def gcd(bigger,smaller):
    if bigger < smaller:
        smaller,bigger = bigger,smaller
    
    if smaller==0:
        return bigger
    return gcd(smaller,bigger%smaller)

c = 0
for i,j in product(range(1,2021),range(1,2021)):
    if gcd(i,j) == 1:
        c += 1

print(c) 
# output
# 2481215