import subprocess
import sys

def test(file,inputs,expected):
    p = subprocess.Popen([file],stdin=subprocess.PIPE, 
        stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    outs,err = p.communicate(inputs.encode('utf-8'))
    outs = outs.decode("utf-8")
    print(f"output:\n{outs}")
    print(f"expected:\n{expected}")

t1 = """**********
o****o****"""
test('/tmp/prev-6_flip_coins.out',t1,"5")

t2="""*o**o***o***
*o***o**o***"""
test('/tmp/prev-6_flip_coins.out',t2,"1")