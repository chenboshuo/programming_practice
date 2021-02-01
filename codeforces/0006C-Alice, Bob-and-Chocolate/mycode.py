import sys
num = int(sys.stdin.readline())
times = list(map(int,sys.stdin.readline().strip().split()))
left = 0
right = num-1


def get(i):
    t = times[i]
    times[i] = 0
    return t



while left<right:
    a = get(left)
    b = get(right)
    time_pass = min(a,b)
    remain_a = a - time_pass
    remain_b = b - time_pass
    # print(times)
    if remain_a == 0:
        left += 1
    else:
        times[left] = remain_a

    if remain_b == 0:
        right -= 1
    else:
        times[right] = remain_b

# if times[right] != 0:
#     alice_eating = left
# else:
#     alice_eating = left+1
alice_eating = left

print(alice_eating,num-alice_eating)


# Time: 248 ms, memory: 0 KB
# Verdict: WRONG_ANSWER
# Input
# 1
# 1
# Participant's output
# 0 1
# Jury's answer
# 1 0
# Checker comment
# wrong answer 1st numbers differ - expected: '1', found: '0'
