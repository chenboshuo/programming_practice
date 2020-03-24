# reference https://leetcode.com/problems/product-of-the-last-k-numbers/discuss/510260/JavaC%2B%2BPython-Prefix-Product
class ProductOfNumbers:

    def __init__(self):
        self.nums = [1]

    def add(self, num: int) -> None:
        if num != 0:
            self.nums.append(self.nums[-1]*num)
        else:
            self.nums = [1]

    def getProduct(self, k: int) -> int:
        if(k >= len(self.nums)):
            return 0
        else:
            return self.nums[-1] // self.nums[-k-1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)

# Runtime: 276 ms, faster than 96.18% of Python3 online submissions for Product of the Last K Numbers.
# Memory Usage: 28.1 MB, less than 100.00% of Python3 online submissions for Product of the Last K Numbers.
# https://leetcode.com/submissions/detail/315360973/
