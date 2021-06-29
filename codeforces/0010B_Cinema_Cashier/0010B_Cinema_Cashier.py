import sys
# import logging
# logging.root.setLevel(level=logging.DEBUG)
# logging.root.setLevel(level=logging.INFO)
import re
from math import ceil

length,size = map(int,sys.stdin.readline().split())
peoples = map(int,sys.stdin.readline().split())
has_occupied = [[True]+[False]*size for _ in range(size+1)]
has_occupied[0] = [True]*(size+1)

center_x = ceil(size/2)
center_y = ceil(size/2)
# logging.debug(f"center_x={center_x},center_y={center_y}")
distance = [[abs(x-center_x)+ abs(y-center_y) for y in range(size+1)]
                for x in range(size+1)]
row_empty = [size]*(size+1)
total_empty = size**2
# logging.debug(f"distance ={distance}")

for people in peoples:
    if people > size or people > total_empty:
        print(-1)
        continue
    d = float('inf')
    ans = None
    for x in range(1,size+1):
        if row_empty[x] < people:
            continue
        for left in range(1,size+2-people):
            total = sum(distance[x][left:left+people])
            if any(has_occupied[x][left:left+people]) == False and \
                total < d:
                    # logging.debug(f"({x},{left}):{total} < {d},{ans} changed")
                    ans = (x,left,left+people-1)
                    d = total

    if ans:
        print(*ans)
        has_occupied[ans[0]][ans[1]:ans[2]+1] = [True]*people
        total_empty -= people
        row_empty[ans[0]] -= people
    else:
        print(-1)
