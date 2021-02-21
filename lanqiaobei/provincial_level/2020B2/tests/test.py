import subprocess
import timeit

test_counter = 1


def test(inputs, output,long_input=False):
    global name
    compile = subprocess.run(["gcc", f"../{name}.c",
                              "-o", f"./{name}.out", "-lm"])
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
    if(p.stdout.decode('utf-8').strip() != output.strip() or time_cost > 1000):
        if not long_input:
            print("input:")
            print(inputs)
        print(p.stderr.decode('utf-8'))
        print("output:")
        print(p.stdout.decode('utf-8').strip())
        print("expect:")
        print(output.strip())
        raise RuntimeError(f"test error in test {test_counter} ({time_cost} ms)")
    print(f"test{test_counter} passed({time_cost} ms)")
    test_counter += 1
