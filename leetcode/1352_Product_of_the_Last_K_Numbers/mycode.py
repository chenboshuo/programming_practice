class ProductOfNumbers:

    def __init__(self):
        self.nums = []

    def add(self, num: int) -> None:
        for i in range(len(self.nums)):
            self.nums[i] *= num
        self.nums.append(num)

    def getProduct(self, k: int) -> int:
        return self.nums[-k]
        # ans = 1
        # for i in self.nums[-k:]:
        #   ans *= i
        # return ans
# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)


# 30 / 33 test cases passed.
# Status: Time Limit Exceeded
# https://leetcode.com/contest/weekly-contest-176/submissions/detail/303662240/
