import sys
import logging
from heapq import *
root = logging.getLogger()
# root.setLevel(logging.DEBUG)
root.setLevel(logging.WARNING)

info = sys.stdin.readline().split()
times = int(info[0])
size = int(info[1])
# records = list(sys.stdin.readline().split('\n'))
records = [sys.stdin.readline().strip() for _ in range(times)]

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
        if pid not in self.occupies:
            print("ILLEGAL_ERASE_ARGUMENT")
            return None
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

# Test: #6, time: 186 ms., memory: 1280 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
# Input
# 85 78
# defragment
# erase 1
# erase 1
# defragment
# defragment
# alloc 63
# erase -1534929890
# erase 1
# alloc 69
# erase 2
# defragment
# defragment
# erase 2
# erase 2
# defragment
# alloc 8
# alloc 44
# erase -1501290085
# defragment
# alloc 40
# alloc 85
# defragment
# defragment
# erase 7
# defragment
# erase 1
# alloc 44
# alloc 77
# defragment
# defragment
# erase 8
# erase 2
# defragment
# alloc 86
# alloc 31
# defragment
# erase 4
# erase 10
# alloc 30
# alloc 66
# defragment
# defragment
# defragment
# erase 3
# defragment
# alloc 79
# all...
# Output
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# 1
# ILLEGAL_ERASE_ARGUMENT
# NULL
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# 2
# 3
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# 4
# ILLEGAL_ERASE_ARGUMENT
# 5
# NULL
# NULL
# 6
# ILLEGAL_ERASE_ARGUMENT
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# 7
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_AR...
# Answer
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# 1
# ILLEGAL_ERASE_ARGUMENT
# 2
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# 3
# 4
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# 5
# NULL
# NULL
# 6
# ILLEGAL_ERASE_ARGUMENT
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# 7
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# NULL
# NULL
# ILLEGAL_ERASE_ARGUMENT
# NULL
# NULL
# ILLEGAL_ERASE_AR...
# Checker Log
# wrong answer 5th lines differ - expected: '2', found: 'NULL'
