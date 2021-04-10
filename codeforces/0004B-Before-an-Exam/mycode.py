total_day, total_time = map(int,input().split())
min_hours = []
max_hours = []
for _ in range(total_day):
    min_hour, max_hour = map(int,input().split())
    min_hours.append(min_hour)
    max_hours.append(max_hour)

delta = total_time - sum(min_hours)
if sum(max_hours) < total_time or delta < 0:
    print('NO')
    exit(0)
for i in range(total_time):
    extra_time = min(max_hours[i] - min_hours[i],delta)
    min_hours[i] += extra_time
    delta -= extra_time
    if delta == 0 :
        print('YES')
        print(*min_hours)
        exit(0)

print('NO')
