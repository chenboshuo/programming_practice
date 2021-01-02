from collections import defaultdict
count = int(input())
record = defaultdict(int)
# round_memo = dict()
winner_score = -float('inf')
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

# Test: #10, time: 278 ms., memory: 36 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
# Input
# 50
# ys 535
# gczuitwphlv -706
# fzcgiyqdsddncqeccyegireaj -712
# gczuitwphlv 127
# mxcdbcgzfpgnfumhz 134
# gczuitwphlv -185
# gczuitwphlv 19
# ys 708
# wwsopulbmausryy -461
# mxcdbcgzfpgnfumhz 840
# fzcgiyqdsddncqeccyegireaj -911
# mxcdbcgzfpgnfumhz -762
# fzcgiyqdsddncqeccyegireaj -926
# fzcgiyqdsddncqeccyegireaj 761
# mxcdbcgzfpgnfumhz -82
# ys -339
# wwsopulbmausryy -774
# ys -946
# ys -43
# wwsopulbmausryy 989
# ys -746
# gczuitwphlv 91
# wwsopulbmausryy -929
# wwsopulbmausryy -463
# mxcdbcgzfpgnfumhz 835
# gczuitwphlv -84
# mx...
# Output
# mxcdbcgzfpgnfumhz
# Answer
# gczuitwphlv
# Checker Log
# wrong answer 1st words differ - expected: 'gczuitwphlv', found: 'mxcdbcgzfpgnfumhz'
