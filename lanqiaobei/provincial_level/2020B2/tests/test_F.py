import test as t
from random import randint
t.name = "F_result_statistics"

t1='''7
80
92
56
74
88
100
0'''

o1='''71%
43%'''

t.test(t1,o1)

for _ in range(10):
    big = "10000\n"
    l = [randint(0,100) for i in range(10000)]
    big += "\n".join(map(str,l))
    passed = sum(bool(i>=60) for i in l)
    excellent = sum(bool(i>= 85) for i in l)
    passed_rate = round(passed*100/len(l))
    excellent_rate = round(excellent*100/len(l))
    expect = f"{passed_rate}%\n{excellent_rate}%"
    # print(f"passed={passed}\texcellent={excellent}")
    t.test(big,expect,long_input=True)

