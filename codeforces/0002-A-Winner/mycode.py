
from collections import defaultdict
count = int(input())
record = defaultdict(int)
round_memo = dict()
for round_ in range(count):
    name,score = input().split()
    record[name] += int(score)
    round_memo[name] = round_

winner_score = 0
winner_round = count
for name,score in record.items():
    if score > winner_score:
        winner = name
        winner_score = score
        winner_round = round_memo[name]
    elif score == winner_score and round_memo[name] < winner_round:
        winner = name
        winner_round = round_memo[name]
        winner_score = score
print(winner)


# Test: #6, time: 280 ms., memory: 288 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
# Input
# 15
# aawtvezfntstrcpgbzjbf 681
# zhahpvqiptvksnbjkdvmknb -74
# aawtvezfntstrcpgbzjbf 661
# jpdwmyke 474
# aawtvezfntstrcpgbzjbf -547
# aawtvezfntstrcpgbzjbf 600
# zhahpvqiptvksnbjkdvmknb -11
# jpdwmyke 711
# bjmj 652
# aawtvezfntstrcpgbzjbf -1000
# aawtvezfntstrcpgbzjbf -171
# bjmj -302
# aawtvezfntstrcpgbzjbf 961
# zhahpvqiptvksnbjkdvmknb 848
# bjmj -735
# Output
# jpdwmyke
# Answer
# aawtvezfntstrcpgbzjbf
# Checker Log
# wrong answer 1st words differ - expected: 'aawtvezfntstrcpgbzjbf', found: 'jpdwmyke'
