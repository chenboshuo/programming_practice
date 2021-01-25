import sys
import logging
from heapq import *
root = logging.getLogger()
# root.setLevel(logging.DEBUG)
root.setLevel(logging.WARNING)

info = sys.stdin.readline().split()
times = int(info[0])
size = int(info[1])
records = list(sys.stdin.read().split('\n'))

logging.info(f"times={times},size={size},records={records}")


class Memory():
    def __init__(self,size):
        self.spaces = [[0,size]]
        self.occupies = dict()
        self.pid = 1
        self.size = size

    def alloc(self,size,pid=None):
        # for i,space in enumerate(self.spaces):
        to_small = []
        while self.spaces:
            space = heappop(self.spaces)
            if space[1] - space[0] >= size:
                # print(self.pid)
                occupy_right = space[0]+size
                if not pid:
                    pid = self.pid
                    print(pid)
                self.occupies[pid] = (space[0],occupy_right)
                if pid == self.pid:
                    self.pid += 1
                if occupy_right < space[1]:
                    # self.spaces[i] = (occupy_right,space[1])
                    heappush(self.spaces,(occupy_right,space[1]))
                break
            else:
                to_small.append(space)
        else:
            print("NULL")

        # restore
        for i in to_small:
            heappush(self.spaces,i)
        logging.info(f"memory_space:{self.spaces}")
        logging.info(f"memory_occupied:{self.occupies}\n")

    def erase(self,pid,delete=True):
        heappush(self.spaces,self.occupies[pid])
        if delete:
            del self.occupies[pid]
        logging.info(f"erase {pid}")
        logging.info(f"memory_space:{self.spaces}")
        logging.info(f"memory_occupied:{self.occupies}\n")

    def defragment(self):
        todo = []
        for pid,loc in self.occupies.items():
            todo.append((pid,loc[1]-loc[0]))
            self.erase(pid,delete=False)

        self.spaces = [[0,size]]
        for pid,length in todo:
            self.alloc(length,pid=pid)
        logging.info(f"memory cleaned:")
        logging.info(f"memory_space:{self.spaces}")
        logging.info(f"memory_occupied:{self.occupies}\n")

# size = 10
# m = Memory(size)
# m.alloc(5)
# m.alloc(3)
# m.erase(1)
# m.alloc(6)
# m.defragment()
# m.alloc(6)

m = Memory(size)
for i in records:
    if i == 'defragment':
        m.defragment()
    else:
        op,num = i.split()
        num = int(num)
        if op == 'alloc':
            m.alloc(num)
        else:
            m.erase(num)


# Time: 278 ms, memory: 5764 KB
# Verdict: RUNTIME_ERROR
# Input
# 6 10
# alloc 5
# alloc 3
# erase 1
# alloc 6
# defragment
# alloc 6
# Participant's output
# 1
# 2
# NULL
# 3
# Jury's answer
# Checker comment
# Exit code is 1
