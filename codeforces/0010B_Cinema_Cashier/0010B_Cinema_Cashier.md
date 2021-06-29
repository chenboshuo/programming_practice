
# B. Cinema Cashiertime
-   limit per test 1 second
-   memory limit per test256 megabytes
-   input standard input
-   output standard output

All cinema halls in Berland are rectangles with _K_ rows of _K_ seats each, and _K_ is an odd number. Rows and seats are numbered from 1 to _K_. For safety reasons people, who come to the box office to buy tickets, are not allowed to choose seats themselves. Formerly the choice was made by a cashier, but now this is the responsibility of a special seating program. It was found out that the large majority of Berland's inhabitants go to the cinema in order to watch a movie, that's why they want to sit as close to the hall center as possible. Moreover, a company of _M_ people, who come to watch a movie, want necessarily to occupy _M_ successive seats in one row. Let's formulate the algorithm, according to which the program chooses seats and sells tickets. As the request for _M_ seats comes, the program should determine the row number _x_ and the segment [_y__l_, _y__r_] of the seats numbers in this row, where _y__r_ - _y__l_ + 1 = _M_. From all such possible variants as a final result the program should choose the one with the minimum function value of total seats remoteness from the center. Say, ![](https://espresso.codeforces.com/de21a9bdfc2f66814cc5291ec42a9813f7f3b391.png) — the row and the seat numbers of the most "central" seat. Then the function value of seats remoteness from the hall center is ![](https://espresso.codeforces.com/a6ae5b08ea1c4d15f150b1a9df3c925c2b9cdd51.png). If the amount of minimum function values is more than one, the program should choose the one that is closer to the screen (i.e. the row number _x_ is lower). If the variants are still multiple, it should choose the one with the minimum _y__l_. If you did not get yet, your task is to simulate the work of this program.

Input

The first line contains two integers _N_ and _K_ (1 ≤ _N_ ≤ 1000, 1 ≤ _K_ ≤ 99) — the amount of requests and the hall size respectively. The second line contains _N_ space-separated integers _M__i_ from the range [1, _K_] — requests to the program.

Output

Output _N_ lines. In the _i_-th line output «-1» (without quotes), if it is impossible to find _M__i_ successive seats in one row, otherwise output three numbers _x_, _y__l_, _y__r_. Separate the numbers with a space.

ExamplesInput

```text
2 1
1 1
```

Output

```text
1 1 1
-1
```

Input

```text
4 3
1 2 3 1
```

Output

```text
2 2 2
1 1 2
3 1 3
2 1 1
```
