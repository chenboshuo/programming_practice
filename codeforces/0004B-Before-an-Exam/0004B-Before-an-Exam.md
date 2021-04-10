# 0004B-Before-an-Exam
[codeforces.com](https://codeforces.com/problemset/problem/4/B) B. Before an Examtime limit per test0.5 secondmemory limit per test64 megabytesinputstandard inputoutputstandard output

Tomorrow Peter has a Biology exam. He does not like this subject much, but _d_ days ago he learnt that he would have to take this exam. Peter's strict parents made him prepare for the exam immediately, for this purpose he has to study not less than _minTime__i_ and not more than _maxTime__i_ hours per each _i_-th day. Moreover, they warned Peter that a day before the exam they would check how he has followed their instructions.

So, today is the day when Peter's parents ask him to show the timetable of his preparatory studies. But the boy has counted only the sum of hours _sumTime_ spent him on preparation, and now he wants to know if he can show his parents a timetable _sсhedule_ with _d_ numbers, where each number _sсhedule__i_ stands for the time in hours spent by Peter each _i_-th day on biology studies, and satisfying the limitations imposed by his parents, and at the same time the sum total of all _schedule__i_ should equal to _sumTime_.

Input

The first input line contains two integer numbers _d_, _sumTime_ (1 ≤ _d_ ≤ 30, 0 ≤ _sumTime_ ≤ 240) — the amount of days, during which Peter studied, and the total amount of hours, spent on preparation. Each of the following _d_ lines contains two integer numbers _minTime__i_, _maxTime__i_ (0 ≤ _minTime__i_ ≤ _maxTime__i_ ≤ 8), separated by a space — minimum and maximum amount of hours that Peter could spent in the _i_-th day.

Output

In the first line print YES, and in the second line print _d_ numbers (separated by a space), each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, if he followed his parents' instructions; or print NO in the unique line. If there are many solutions, print any of them.

ExamplesInput

```plt
1 48
5 7
```

Output

```plt
NO
```

Input

```plt
2 5
0 1
3 5
```

Output

```plt
YES
1 4
```
