from datetime import date


class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        return (date.fromisoformat(date2) - date.fromisoformat(date1)).days


# 56 / 105 test cases passed.
# Status: Wrong Answer
# Submitted: 1 month, 1 week ago
# Input:
# "2020-01-15"
# "2019-12-31"
# Output:
# -15
# Expected:
# 15
