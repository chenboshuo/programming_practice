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
            self.nums.append(0)

    def getProduct(self, k: int) -> int:
        # return self.nums[-k]
        # ans = 1
        # for i in self.nums[-k:]:
        #   ans *= i
        # return ans
        # return np.product(self.nums[-k:])
        if k == len(self.nums):
            return self.product
        p = self.nums[-k]
        if p == 0:
            return 0
        else:
            return self.product//p


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)

# 25 / 33 test cases passed.
# Status: Wrong Answer
# Submitted: 1 month ago
# Input:
# ["ProductOfNumbers","add","add","add","getProduct","add","add","add","getProduct","getProduct","getProduct","add","add"]
# [[],[0],[0],[9],[3],[8],[3],[8],[5],[4],[6],[8],[8]]
# Output:
# [null,null,null,null,9,null,null,null,0,1728,1728,null,null]
# Expected:
# [null,null,null,null,0,null,null,null,0,1728,0,null,null]
# https://leetcode.com/contest/weekly-contest-176/submissions/detail/303687207/
