import sys
num = int(sys.stdin.readline())
times = list(map(int,sys.stdin.readline().strip().split()))
left = 0
right = num-1
time_left = 0
time_right = 0
 
 
 
 
while left<=right:
    time_left += times[left]
    left += 1
    while right >= 0  and time_right + times[right] <= time_left:
        right -= 1
 
 
alice_eating = left
print(alice_eating,num-alice_eating)
 
 

# 4
# Time: 154 ms, memory: 0 KB
# Verdict: WRONG_ANSWER
# Input
# 3
# 1 1 1
# Participant's output
# 1 2
# Jury's answer
# 2 1
# Checker comment
# wrong answer 1st numbers differ - expected: '2', found: '1'