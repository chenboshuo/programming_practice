import sys
num = int(sys.stdin.readline())
times = list(map(int,sys.stdin.readline().strip().split()))
left = 0
right = num-1
time_left = 0
time_right = 0
 
 
 
while left < right:
    time_left += times[left]
    left += 1
    while right >= 0  and time_right + times[right] <= time_left:
        right -= 1
        time_right += times[right]
 
 
alice_eating = left + bool((left == right) and (time_left <= time_right))
print(alice_eating,num-alice_eating)
 
 

# Test: #8, time: 186 ms., memory: 0 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
# Input
# 3
# 6 8 4
# Output
# 2 1
# Answer
# 1 2
# Checker Log
# wrong answer 1st numbers differ - expected: '1', found: '2'