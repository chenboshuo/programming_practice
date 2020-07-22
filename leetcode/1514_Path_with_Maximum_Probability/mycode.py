from collections import defaultdict
from typing import *

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
      # record the edges' weights
      edges_weight = {i:defaultdict(int) for i in range(n)}
      for edge,p in zip(edges,succProb):
        edges_weight[edge[0]][edge[1]] = p
        edges_weight[edge[1]][edge[0]] = p

      # store the problability 
      nodes_access_problability = [0 for _ in range(n)]
      for i,p in edges_weight[start].items():
        nodes_access_problability[i] = p

      nodes_access_problability[start] = 1
      max_p = 1
      while start != end and max_p != 0:
        max_p = 0
        max_node = start
        for target in edges_weight[start].keys():
          edges_weight[target][start] = 0
          nodes_access_problability[target] *= nodes_access_problability[start]
          if edges_weight[start][target] > max_p:
            max_p = edges_weight[start][target]
            max_node = target
        start = max_node
      return nodes_access_problability[end]
        
