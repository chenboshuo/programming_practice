from typing import *
import heapq

class Solution:
    def maxProbability(self,
                    n: int,
                    edges: List[List[int]],
                    successor_prob: List[float],
                    start: int,
                    end: int) -> float:
        access_prob = [0] * n
        edges_weight = {i:{} for i in range(n)}
        for (begin_point,end_point),p in zip(edges,successor_prob):
            edges_weight[begin_point][end_point] = p
            edges_weight[end_point][begin_point] = p

        access_prob[start] = 1
        heap = [(-1,start)]
        # heap = []
        cur = start
        # prob = -1

        while heap and cur != end:
            prob ,cur = heapq.heappop(heap)
            for neighbor,next_p in edges_weight.get(cur,{}).items():
                new_p = -prob * next_p
                if new_p > access_prob[neighbor]:
                    access_prob[neighbor] = new_p
                    heapq.heappush(heap,(-access_prob[neighbor],neighbor))

        return access_prob[end]

# Runtime: 692 ms, faster than 99.80% of Python3 online submissions for Path with Maximum Probability.
# Memory Usage: 25 MB, less than 67.86% of Python3 online submissions for Path with Maximum Probability.
