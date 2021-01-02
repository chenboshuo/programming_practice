from collections import defaultdict
count = int(input())
record = defaultdict(int)
# round_memo = dict()
winner_score = 0
for round_ in range(count):
    name,score = input().split()
    score = int(score)
    record[name] += score
    # if score > 0:
        # round_memo[name] = round_
    if record[name] > winner_score:
        winner = name
        winner_score = record[name]

# winner_round = count
# for name,score in record.items():
    # if score > winner_score:
        # winner = name
    #     # winner_score = score
    #     winner_round = round_memo[name]
    # elif score == winner_score and round_memo[name] < winner_round:
    #     winner = name
    #     winner_round = round_memo[name]
    #     winner_score = score
print(winner)
