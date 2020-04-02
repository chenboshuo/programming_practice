from datetime import date


class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        return abs((date.fromisoformat(date2) - date.fromisoformat(date1)).days)


# 105 / 105 test cases passed.
# Status: Accepted
# Runtime: 24 ms
# Memory Usage: 12.7 MB
# Submitted: 1 month, 1 week ago
