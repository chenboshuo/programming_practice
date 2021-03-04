import test as t
t.name = "I_plane_cut"
t.language = 'cpp'

t0="""1
1 1
"""

t.test(t0,'2')

t1='''3
1 1
2 2
3 3'''

o1='''6'''

t.test(t1,o1)

parallel="""2
1 1
1 2
"""
t.test(parallel,'3')


p='1000\n'
for i in range(1000):
    p += f"1 {i}\n"
t.test(p,'1001')

coincide='''2
1 1
1 1'''

t.test(coincide,"2")