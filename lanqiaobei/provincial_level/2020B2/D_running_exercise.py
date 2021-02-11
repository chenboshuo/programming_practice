# ## D 跑步锻炼

# ### 问题描述
# 小蓝每天都锻炼身体。
# 正常情况下，小蓝每天跑 1 千米。
# 如果某天是周一或者月初（1 日），为了
# 激励自己，小蓝要跑 2 千米。
# 如果同时是周一或月初，小蓝也是跑 2 千米。
# 小蓝跑步已经坚持了很长时间，
# 从 2000 年 1 月 1 日周六（含）到 2020 年
# 10 月 1 日周四（含）。
# 请问这段时间小蓝总共跑步多少千米？

from datetime import *
MONDAY = 0
begin = date(2000,1,1)
end = date(2020,10,1)

day = begin
delta = timedelta(days=1)
count = 0
while day <= end:
    if day.weekday() == MONDAY or day.day == 1:
        count += 1
    count += 1
    day += delta

print(count)

"""
doc:https://docs.python.org/3/library/datetime.html#datetime.timedelta

date.weekday()
Return the day of the week as an integer, where Monday is 0 and Sunday is 6. For example, date(2002, 12, 4).weekday() == 2, a Wednesday. See also isoweekday().

date.isoweekday()
Return the day of the week as an integer, where Monday is 1 and Sunday is 7. For example, date(2002, 12, 4).isoweekday() == 3, a Wednesday. See also weekday(), isocalendar().

class datetime.date
An idealized naive date, assuming the current Gregorian calendar always was, and always will be, in effect. Attributes: year, month, and day.

A timedelta object represents a duration, the difference between two dates or times.

class datetime.timedelta(days=0, seconds=0, microseconds=0, milliseconds=0, minutes=0, hours=0, weeks=0)
All arguments are optional and default to 0. Arguments may be integers or floats, and may be positive or negative.
"""