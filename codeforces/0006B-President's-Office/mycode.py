import sys
info = sys.stdin.readline().split()
length = int(info[0])
width = int(info[1])
color = info[2]

lines = []
for _ in range(length):
    lines.append(sys.stdin.readline().strip())

different_color = set([color,'.'])

def count(i,j):
    global lines
    global different_color
    if i < length and i >=0 and j>= 0 and j < width:
        different_color.add(lines[i][j])

def adjcent(i,j):
    count(i-1,j)
    count(i+1,j)
    count(i,j-1)
    count(i,j+1)


for i in range(length):
    for j in range(length):
        if lines[i][j] == color:
            adjcent(i,j)

print(len(different_color)-2)
# Time: 124 ms, memory: 0 KB
# Verdict: WRONG_ANSWER
# Input
# 1 10 H
# ....DDHHHH
# Participant's output
# 0
# Jury's answer
# 1
# Checker comment
# wrong answer 1st numbers differ - expected: '1', found: '0'
