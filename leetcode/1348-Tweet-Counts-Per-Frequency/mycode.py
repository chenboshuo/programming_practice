from collections import defaultdict
from bisect import insort
class TweetCounts:

    def __init__(self):
        self.user_time = defaultdict(list)

    def recordTweet(self, tweet_name: str, time: int) -> None:
      insort(self.user_time[tweet_name], time)


    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
      # 处理分钟情况
        time_during = {'minute': 60, 'hour':3600, 'day': 86400}
        delta = time_during[freq]
        n_duration = (endTime - startTime) // delta + 1
        ans = [0]* n_duration

        for time in self.user_time[tweetName]:
          if startTime<= time <= endTime:
            ans[(time-startTime) // delta]+=1

        return ans
        


# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)

# Runtime: 420 ms, faster than 51.70% of Python3 online submissions for Tweet Counts Per Frequency.
# Memory Usage: 20.4 MB, less than 100.00% of Python3 online submissions for Tweet Counts Per Frequency.
