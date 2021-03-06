import subprocess
import timeit
import logging

FORMAT = "%(message)s"
logging.basicConfig(
    # level="NOTSET", format=FORMAT, datefmt="[%X]", handlers=[RichHandler()]
    level="INFO", format=FORMAT, datefmt="[%X]"
)

test_counter = 1
language='c'

def test(inputs, expect=None,long_input=False):
    global name
    global language
    if language == 'c':
        compile = subprocess.run(["gcc", f"../{name}.c",
                                "-o", f"./{name}.out", "-lm"])
    elif language == 'cpp':
        compile = subprocess.run(["g++", f"../{name}.cpp",
                                "-o", f"./{name}.out", ])
    # p = subprocess.run(['python','contest.py'],
    start = timeit.default_timer()
    p = subprocess.run([f'./{name}.out'],
                       # stdin=subprocess.PIPE,
                       input=inputs.encode('utf-8'),
                       stdout=subprocess.PIPE,
                       stderr=subprocess.PIPE)
    stop = timeit.default_timer()
    time_cost =  (stop - start)*1000
    global test_counter
    out = p.stdout.decode('utf-8').strip()
    expect = expect.strip() if expect else out
    if(expect != out or time_cost > 1000):
        if not long_input:
            print("input:")
            print(inputs)
        print(p.stderr.decode('utf-8'))
        print("output:")
        print(out)
        if expect:
            print("expect:")
            print(expect)
        logging.error(f"test error in test {test_counter} ({time_cost} ms)")
        exit(1)
    print(f"test{test_counter} passed({time_cost} ms)")
    test_counter += 1
