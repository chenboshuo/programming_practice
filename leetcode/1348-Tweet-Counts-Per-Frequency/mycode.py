from collections import defaultdict
class TweetCounts:

    def __init__(self):
        self.user_time = defaultdict(list)

    def recordTweet(self, tweetName: str, time: int) -> None:
      self.user_time[tweetName].append(time)

      self.user_time[tweetName].sort()


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


# Runtime: 444 ms, faster than 40.45% of Python3 online submissions for Tweet Counts Per Frequency.
# Memory Usage: 20.3 MB, less than 100.00% of Python3 online submissions for Tweet Counts Per Frequency.
