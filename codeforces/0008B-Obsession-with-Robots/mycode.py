import sys
import re
import logging
logging.root.setLevel(level=logging.INFO)

movements = sys.stdin.readline().strip()
cur_x = 0
cur_y = 0
memo = set()
move = {
    'L':(-1,0),
    'R':(1,0),
    'U':(0,1),
    'D':(0,-1)
}
logging.info(f"move={move}")

t=(0,0)
for i in movements:
    memo.add(t)
    cur_x += move[i][0]
    cur_y += move[i][1]
    t = (cur_x,cur_y)
    if t in memo:
        print('BUG')
        exit(0)
logging.info(f"memo={memo}")

print('OK')

# Time: 278 ms, memory: 5812 KB
# Verdict: WRONG_ANSWER
# Input
# RUL
# Participant's output
# OK
# Jury's answer
# BUG
# Checker comment
# wrong answer 1st words differ - expected: 'BUG', found: 'OK'
