# reference: https://codeforces.com/contest/20/submission/133185940
import sys
from collections import defaultdict,namedtuple
from heapq import heappush,heappop
from dataclasses import dataclass,field
from typing import Dict
inf = 10**9+7
# from copy import deepcopy

# import logging
# log = logging.getLogger()
# log.setLevel(logging.INFO)

@dataclass(eq=False)
class Node():
    access_cost = inf
    has_connected = False
    pre = None
    next_nodes:Dict[int,int] = field(default_factory=(lambda:defaultdict(lambda: inf)))


nodes_size, edges_size = map(int,sys.stdin.readline().split())

graph = defaultdict(lambda:Node())

for _ in range(edges_size):
    v1,v2,w = map(int, sys.stdin.readline().split())

    if v1 != v2:
        graph[v1].next_nodes[v2] = min(graph[v1].next_nodes[v2],w)
        graph[v2].next_nodes[v1] = min(graph[v2].next_nodes[v1],w)

VisitItem = namedtuple('VisitItem',['access_cost','begin_node','end_node'])
# visiting_queue = [VisitItem(access_cost=0,begin_node=None,end_node=1)]
visiting_queue = [ \
    VisitItem(access_cost=graph[1]next_nodes[neighbor_node],begin_node=1,end_node=neighbor_node) 
    for neighbor_node in graph[1]next_nodes.keys()
]
# for  in graph[1]:


while visiting_queue:
    cur_node_cost,begin_node_name,end_node_name = heappop(visiting_queue)
    end_node = graph[end_node_name]

    if end_node.has_connected:
        continue
    # log.error(f"{begin_node_name}-{end_node_name} (total_cost) = {cur_node_cost}")
    end_node.has_connected = True
    end_node.pre = begin_node_name
    end_node.access_cost = cur_node_cost

    if end_node_name == nodes_size:
        path = []
        cur_node_name = nodes_size
        while cur_node_name:
            cur_node = graph[cur_node_name]
            path.append(str(cur_node_name))
            # cur = path_memo[cur].pre
            # log.error(f"{cur_node.pre}->{cur_node_name}")
            cur_node_name = cur_node.pre
        print(' '.join(reversed(path)))
        exit(0)

    for next_node_name,access_cost in graph[end_node_name].next_nodes.items():
        next_node = graph[next_node_name]
        if not next_node.has_connected:
            newpath_cost = cur_node_cost + access_cost

        heappush(visiting_queue,
            VisitItem(access_cost=newpath_cost,begin_node=end_node_name,end_node=next_node_name)
        )

print(-1)


"""
https://codeforces.com/contest/20/submission/142764350
Memory limit exceeded on test 31

Test 30:
Time: 561 ms, memory: 26780 KB
"""
