from collections import defaultdict
from itertools import permutations
# upper = 5000
n = 2021041820210418
# n = 4


def find_primes(upper):
    is_prime = [True for i in range(upper)]
    is_prime[0] = False
    is_prime[1] = False

    for i in range(1,upper):
        if is_prime[i]:
            k = 2*i
            while k < upper:
                is_prime[k] = False
                k += i
    return [i for i in range(upper) if is_prime[i]]

# primes = find_primes(5000) # # 根据输出调整搜索质数的范围(直接搜可能跑不完) 
# print(primes)



def find_factors(n):
    factor = defaultdict(int)
    for prime in primes:
        while n % prime == 0:
            factor[prime] += 1
            n //= prime
    return (factor, n)
# print(find_factors(n))
# output
# (defaultdict(<class 'int'>, {2: 1, 3: 3, 17: 1, 131: 1, 2857: 1}), 5882353)
# 2021041820210418 = 2^1 \times 3^3 \times 17^1 \times 131^1 \times 2857^1 \times 5882353^1

primes = find_primes(5882354) # 根据输出调整搜索质数的范围(直接搜可能跑不完)
factors = find_factors(n)[0]
print(factors)

p = [key for key,value in factors.items() for _ in range(value)] 

def prod(nums,left,right):
    ans = 1
    for i in nums[left:right]:
        ans *= i
    return ans

scheme = set()
for permutation in permutations(p):
    for i in range(len(p)+1):
        for j in range(i,len(p)+1):
            scheme.add((prod(permutation,0,i),
                prod(permutation,i,j),
                prod(permutation,j+1,len(permutation))
            ))
print(len(scheme))
# print(scheme)


#search

