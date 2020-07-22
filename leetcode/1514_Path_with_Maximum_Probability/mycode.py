from collections import defaultdict
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
      nodes = {i:defaultdict(int) for i in range(n)}
      for edge,p in zip(edges,succProb):
        nodes[edge[0]][edge[1]] = p
        nodes[edge[1]][edge[0]] = p

      node_ps = [0 for _ in range(n)]
      for i,p in nodes[start].items():
        node_ps[i] = p

      while start != end:
        max_p = node_ps[start]
        max_node = start
        for target in nodes[start].keys():
          nodes[target][start] = 0
          if nodes[start][target] > max_p:
            max_p = nodes[start][target]
            max_node = target
        node_ps[target] = max_p* node_ps[start]
        start = max_node
      return node_ps[end]
        
