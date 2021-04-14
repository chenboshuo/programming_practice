# C. Alice, Bob and Chocolate

[codeforces.com](https://codeforces.com/problemset/problem/6/C)



Alice and Bob like games. And now they are ready to start a new game. They have placed _n_ chocolate bars in a line. Alice starts to eat chocolate bars one by one from left to right, and Bob — from right to left. For each chocololate bar the time, needed for the player to consume it, is known (Alice and Bob eat them with equal speed). When the player consumes a chocolate bar, he immediately starts with another. It is not allowed to eat two chocolate bars at the same time, to leave the bar unfinished and to make pauses. If both players start to eat the same bar simultaneously, Bob leaves it to Alice as a true gentleman.

How many bars each of the players will consume?

Input

The first line contains one integer _n_ (1 ≤ _n_ ≤ 105) — the amount of bars on the table. The second line contains a sequence _t_1, _t_2, ..., _t__n_ (1 ≤ _t__i_ ≤ 1000), where _t__i_ is the time (in seconds) needed to consume the _i_-th bar (in the order from left to right).

Output

Print two numbers _a_ and _b_, where _a_ is the amount of bars consumed by Alice, and _b_ is the amount of bars consumed by Bob.

ExamplesInput

```
2 9 8 2 7
```

Output

```
2 3
```
