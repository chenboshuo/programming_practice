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
        time_right += times[right]
 
 
alice_eating = left
print(alice_eating,num-alice_eating)
 
 

# 1
# Time: 154 ms, memory: 0 KB
# Verdict: WRONG_ANSWER
# Input
# 5
# 2 9 8 2 7
# Participant's output
# 3 2
# Jury's answer
# 2 3
# Checker comment
# wrong answer 1st numbers differ - expected: '2', found: '3'