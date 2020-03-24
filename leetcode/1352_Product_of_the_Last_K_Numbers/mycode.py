import numpy as np


class ProductOfNumbers:

    def __init__(self):
        self.nums = []
        self.product = 1

    def add(self, num: int) -> None:
        if num != 0:
            # for i in range(len(self.nums)):
            #   self.nums[i] *= num
            self.nums.append(self.product)
            self.product *= num
        else:
            self.nums = [0 for _ in self.nums]

    def getProduct(self, k: int) -> int:
        # return self.nums[-k]
        # ans = 1
        # for i in self.nums[-k:]:
        #   ans *= i
        # return ans
        # return np.product(self.nums[-k:])
        p = self.nums[-k]
        if p == 0:
            return 0
        else:
            return self.product//p


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)

# 2 / 33 test cases passed.
# Status: Runtime Error
# Submitted: 1 month ago
# Runtime Error Message:
# Line 24: IndexError: list index out of range
# Last executed input:
# ["ProductOfNumbers","add","add","add","add","add","getProduct","add","getProduct","add"]
# [[],[3],[0],[0],[8],[3],[1],[7],[5],[3]]
# https://leetcode.com/contest/weekly-contest-176/submissions/detail/303683901/
