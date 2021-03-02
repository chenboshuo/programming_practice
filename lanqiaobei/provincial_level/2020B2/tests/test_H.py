import test as t
t.name = "H_sum_of_substring_scores"
# t.language = 'cpp'

t1='''ababc'''

o1='''28'''

t.test(t1,o1)

t2 = 'a' * 100
o2 = str(101*100//2)
t.test(t2,o2,long_input=True)

t3 = 'a' * 100000
o3 = str(100001*100000//2)
t.test(t3,o3,long_input=True)