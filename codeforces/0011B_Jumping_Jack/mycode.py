
import sys
from collections import deque
import logging
logging.root.setLevel(level=logging.DEBUG)

target = int(sys.stdin.readline())
target = target if target >= 0 else -target

to_explore = deque()
to_explore.append(0)

# t = 1
reached = {0:0}
while target not in reached:
    point = to_explore.popleft()
    t = reached[point] + 1

    left = point-t
    left = left if left >=0 else -left
    # if left not in reached:
    reached[left] =  t
    to_explore.append(left)

    right = point+t
    # if right not in reached:
    reached[right] =  t
    to_explore.append(right)

    logging.debug(f"t={t},point={point}\nreached={reached},to_explore={to_explore}")
    # t =
print(reached[target])
