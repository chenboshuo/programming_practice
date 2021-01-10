# B. President's Office

[codeforces.ml](https://codeforces.ml/problemset/problem/6/B) B. President's Officetime limit per test2 secondsmemory limit per test64 megabytesinputstandard inputoutputstandard output

President of Berland has a very vast office-room, where, apart from him, work his subordinates. Each subordinate, as well as President himself, has his own desk of a unique colour. Each desk is rectangular, and its sides are parallel to the office walls. One day President decided to establish an assembly, of which all his deputies will be members. Unfortunately, he does not remember the exact amount of his deputies, but he remembers that the desk of each his deputy is adjacent to his own desk, that is to say, the two desks (President's and each deputy's) have a common side of a positive length.

The office-room plan can be viewed as a matrix with _n_ rows and _m_ columns. Each cell of this matrix is either empty, or contains a part of a desk. An uppercase Latin letter stands for each desk colour. The «period» character («.») stands for an empty cell.

Input

The first line contains two separated by a space integer numbers _n_, _m_ (1 ≤ _n_, _m_ ≤ 100) — the length and the width of the office-room, and _c_ character — the President's desk colour. The following _n_ lines contain _m_ characters each — the office-room description. It is guaranteed that the colour of each desk is unique, and each desk represents a continuous subrectangle of the given matrix. All colours are marked by uppercase Latin letters.

Output

Print the only number — the amount of President's deputies.


```
3 4 R
G.B.
.RR.
TTT.
```


```
3 3 Z
...
.H.
..Z
```
