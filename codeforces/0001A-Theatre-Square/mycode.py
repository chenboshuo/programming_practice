from math import ceil

m, n, a = list(map(int, input().split()))

print(ceil(m/a) * ceil(n/a))

# Test:  # 1, time: 93 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 6 6 4
# Output
# 4
# Answer
# 4
# Checker Log
# ok 1 number(s): "4"
# Test:  # 2, time: 108 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1 1 1
# Output
# 1
# Answer
# 1
# Checker Log
# ok 1 number(s): "1"
# Test:  # 3, time: 93 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 2 1 1
# Output
# 2
# Answer
# 2
# Checker Log
# ok 1 number(s): "2"
# Test:  # 4, time: 93 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1 2 1
# Output
# 2
# Answer
# 2
# Checker Log
# ok 1 number(s): "2"
# Test:  # 5, time: 77 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 2 2 1
# Output
# 4
# Answer
# 4
# Checker Log
# ok 1 number(s): "4"
# Test:  # 6, time: 92 ms., memory: 16 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 2 1 2
# Output
# 1
# Answer
# 1
# Checker Log
# ok 1 number(s): "1"
# Test:  # 7, time: 109 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1 1 3
# Output
# 1
# Answer
# 1
# Checker Log
# ok 1 number(s): "1"
# Test:  # 8, time: 93 ms., memory: 28 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 2 3 4
# Output
# 1
# Answer
# 1
# Checker Log
# ok 1 number(s): "1"
# Test:  # 9, time: 93 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1000000000 1000000000 1
# Output
# 1000000000000000000
# Answer
# 1000000000000000000
# Checker Log
# ok 1 number(s): "1000000000000000000"
# Test:  # 10, time: 108 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 12 13 4
# Output
# 12
# Answer
# 12
# Checker Log
# ok 1 number(s): "12"
# Test:  # 11, time: 93 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 222 332 5
# Output
# 3015
# Answer
# 3015
# Checker Log
# ok 1 number(s): "3015"
# Test:  # 12, time: 93 ms., memory: 4 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1000 1000 10
# Output
# 10000
# Answer
# 10000
# Checker Log
# ok 1 number(s): "10000"
# Test:  # 13, time: 93 ms., memory: 20 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1001 1000 10
# Output
# 10100
# Answer
# 10100
# Checker Log
# ok 1 number(s): "10100"
# Test:  # 14, time: 93 ms., memory: 8 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 100 10001 1000000000
# Output
# 1
# Answer
# 1
# Checker Log
# ok 1 number(s): "1"
# Test:  # 15, time: 93 ms., memory: 20 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1000000000 1000000000 1000000000
# Output
# 1
# Answer
# 1
# Checker Log
# ok 1 number(s): "1"
# Test:  # 16, time: 92 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1000000000 1000000000 999999999
# Output
# 4
# Answer
# 4
# Checker Log
# ok 1 number(s): "4"
# Test:  # 17, time: 77 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1000000000 1000000000 192
# Output
# 27126743055556
# Answer
# 27126743055556
# Checker Log
# ok 1 number(s): "27126743055556"
# Test:  # 18, time: 93 ms., memory: 4 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 1000000000 987654321 1
# Output
# 987654321000000000
# Answer
# 987654321000000000
# Checker Log
# ok 1 number(s): "987654321000000000"
# Test:  # 19, time: 78 ms., memory: 4 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 456784567 1000000000 51
# Output
# 175618850864484
# Answer
# 175618850864484
# Checker Log
# ok 1 number(s): "175618850864484"
# Test:  # 20, time: 77 ms., memory: 20 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 39916800 134217728 40320
# Output
# 3295710
# Answer
# 3295710
# Checker Log
# ok 1 number(s): "3295710"
