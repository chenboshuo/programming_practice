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
    while right >= 0  and time_right < time_left:
        time_right += times[right]
        right -= 1
 
 
alice_eating = left + bool((left == right) and (time_left <= time_right))
print(alice_eating,num-alice_eating)
 
 

