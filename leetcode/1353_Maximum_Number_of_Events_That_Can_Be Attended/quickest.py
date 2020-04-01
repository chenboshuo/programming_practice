class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        my_set = set()

        events.sort(key=lambda x: x[1])

        for a, b in events:
            i = a
            while i <= b:
                if i not in my_set:
                    my_set.add(i)
                    break
                i += 1

        return len(my_set)

# Runtime: 800 ms, faster than 95.31% of Python3 online submissions for Maximum Number of Events That Can Be Attended.
# Memory Usage: 51.3 MB, less than 100.00% of Python3 online submissions for Maximum Number of Events That Can Be Attended.
