#A. Winner

[codeforces.ml](https://codeforces.ml/problemset/problem/2/A) A. Winnertime limit per test1 secondmemory limit per test64 megabytesinputstandard inputoutputstandard output

The winner of the card game popular in Berland "Berlogging" is determined according to the following rules. If at the end of the game there is only one player with the maximum number of points, he is the winner. The situation becomes more difficult if the number of such players is more than one. During each round a player gains or loses a particular number of points. In the course of the game the number of points is registered in the line "name score", where name is a player's name, and score is the number of points gained in this round, which is an integer number. If score is negative, this means that the player has lost in the round. So, if two or more players have the maximum number of points (say, it equals to _m_) at the end of the game, than wins the one of them who scored at least _m_ points first. Initially each player has 0 points. It's guaranteed that at the end of the game at least one player has a positive number of points.

Input

The first line contains an integer number _n_ (1  ≤  _n_  ≤  1000), _n_ is the number of rounds played. Then follow _n_ lines, containing the information about the rounds in "name score" format in chronological order, where name is a string of lower-case Latin letters with the length from 1 to 32, and score is an integer number between -1000 and 1000, inclusive.

Output

Print the name of the winner.

ExamplesInput

```
mike 3
andrew 5
mike 2
```

Output

```
andrew
```

Input

```
andrew 3
andrew 2
mike 5
```

Output

```
andrew
```
