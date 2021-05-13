# 寻找100以内质因数
def find_prime():
    is_prime = [True for i in range(100)]
    is_prime[1] = False
    is_prime[0] = False
    for i in range(2,100):
        k = 2*i
        while k < 100:
            is_prime[k] = False
            k += i
    return [i for i in range(100) if is_prime[i]]

factors = {i:0 for i in find_prime()}
# print(factors)

for factor in factors:
    for num in range(1,101):
        while num % factor == 0:
            factors[factor] += 1
            num //= factor
print(factors)

ans = 1
for times in factors.values():
    ans *= (times+1)
print(ans)
    


