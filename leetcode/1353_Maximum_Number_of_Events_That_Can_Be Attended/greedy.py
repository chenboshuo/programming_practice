# source https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510262/Detailed-analysisLet-me-lead-you-to-the-solution-step-by-step
import heapq


class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        day = 1
        count = 0
        event_id = 0
        min_heap = []  # store the end days
        max_day = max(event[1] for event in events)
        while day <= max_day:

            # if no event today, to the next avaiable event
            if event_id < len(events) and not min_heap:
                day = events[event_id][0]

            # all events starting from today are newly available.
            # add them to the heap.
            while event_id < len(events) and events[event_id][0] <= day:
                heapq.heappush(min_heap, events[event_id][1])
                event_id += 1

            # if the event at the top already ended, then discard it
            while min_heap and min_heap[0] < day:
                heapq.heappop(min_heap)

            if min_heap:
                heapq.heappop(min_heap)
                count += 1
            elif event_id > len(events):
                break

            day += 1

        return count


# Runtime: 996 ms, faster than 41.88 % of Python3 online submissions for Maximum Number of Events That Can Be Attended.
# Memory Usage: 51 MB, less than 100.00 % of Python3 online submissions for Maximum Number of Events That Can Be Attended.
