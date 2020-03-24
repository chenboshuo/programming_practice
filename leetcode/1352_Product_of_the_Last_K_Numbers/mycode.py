import numpy as np


class ProductOfNumbers:

    def __init__(self):
        self.nums = []
        self.left_product = 1
        self.product = 1

    def add(self, num: int) -> None:
        if num != 0:
            # for i in range(len(self.nums)):
            #   self.nums[i] *= num
            self.product *= num
            num *= self.left_product
            self.nums.append(num)
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


# 1 / 33 test cases passed.
# Status: Wrong Answer
# Submitted: 1 month ago
# Input:
# ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
# [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
# Output:
# [null,null,null,null,null,null,24,60,0,null,240]
# Expected:
# [null,null,null,null,null,null,20,40,0,null,32]
# https://leetcode.com/contest/weekly-contest-176/submissions/detail/303678592/
