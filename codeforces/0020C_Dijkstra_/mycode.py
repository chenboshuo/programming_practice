import sys
from collections import defaultdict,deque

nodes_size, edges_size = map(int,sys.stdin.readline().split())

graph = defaultdict(lambda: defaultdict(lambda: float('inf')))
for _ in range(edges_size):
    e1,e2,w = map(int, sys.stdin.readline().split())
    if e1 != e2:
        graph[e1][e2] = min(graph[e1][e2],w)
        graph[e2][e1] = min(graph[e2][e1],w)

# Node_item = namedtuple("Node_tuple",['cost','pre'])
path_memo = defaultdict(lambda:{'cost':float('inf'), 'pre':None})
path_memo[1]['cost'] = 0
visiting_queue = deque()
visiting_queue.append(1)
while visiting_queue:
    cur_node = visiting_queue.popleft()
    for next_node,w in graph[cur_node].items():
        c = path_memo[cur_node]['cost'] + w
        if path_memo[next_node]['cost'] > c:
            path_memo[next_node]['cost'] = c
            path_memo[next_node]['pre'] = cur_node
            visiting_queue.append(next_node)

path = []
cur = nodes_size
while cur:
    path.append(str(cur))
    cur = path_memo[cur]['pre']
# path.reverse()
if path[-1] == str(nodes_size):
    print(-1)
else:
    print(' '.join(reversed(path)))

"""
Memory limit exceeded on test 28 
"""
