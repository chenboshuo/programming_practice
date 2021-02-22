import test as t
t.name = "G_palindrome_date"

t1='''20200202'''

o1='''20211202
21211212'''

t.test(t1,o1)

t2="""21200212"""
o2="""21211212
21211212"""
t.test(t2,o2)