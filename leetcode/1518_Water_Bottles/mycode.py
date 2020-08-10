class Solution:
    def numWaterBottles(self, num_bottles: int, num_exchange: int) -> int:
        result = num_bottles
        while num_bottles >= num_exchange:
          exchange = num_bottles // num_exchange
          r = num_bottles % num_exchange
          result += exchange
          num_bottles = exchange + r
        # result += num_bottles
        return result
