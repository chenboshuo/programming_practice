from collections import defaultdict
from bisect import insort, bisect_left
class TweetCounts:

    def __init__(self):
        self.user_time = defaultdict(list)

    def recordTweet(self, tweet_name: str, time: int) -> None:
      insort(self.user_time[tweet_name], time)


    def getTweetCountsPerFrequency(self, freq: str, tweet_name: str, start_time: int, end_time: int) -> List[int]:
        delta = 60 if freq == 'minute' else 3600 if freq == 'hour' else 86400
        i = start_time
        res = []
        while i <= end_time:
            j = min(i + delta, end_time+1)
            res.append(bisect_left(self.user_time[tweet_name], j) - bisect_left(self.user_time[tweet_name], i))
            i += delta
        return res



# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
