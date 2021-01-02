# reference https://github.com/Sarthak30/Codeforces/blob/master/winner.py
import sys
from collections import defaultdict
times = int(sys.stdin.readline())
records = [sys.stdin.readline().strip() for i in range(times)]

scores = defaultdict(int)
memory = []
for record in records:
    name,score = record.split()
    score = int(score)
    scores[name] += score
    memory.append((name,scores[name]))

winner_score = max(scores.values())
for name,score in memory:
    if score >= winner_score and scores[name] == winner_score:
        print(name)
        exit(0)

print(times,records)