m, n, a = list(map(int, input().split()))

print(((m//a)+1) * ((m//a)+1))

# Test:  # 1, time: 77 ms., memory: 0 KB, exit code: 0, checker exit code: 0, verdict: OK
# Input
# 6 6 4
# Output
# 4
# Answer
# 4
# Checker Log
# ok 1 number(s): "4"
# Test:  # 2, time: 77 ms., memory: 0 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
# Input
# 1 1 1
# Output
# 4
# Answer
# 1
# Checker Log
# wrong answer 1st numbers differ - expected: '1', found: '4'
