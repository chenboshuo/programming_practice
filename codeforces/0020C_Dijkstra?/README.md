

# C. Dijkstra?
```text
time limit per test 1 second
memory limit per test 64 megabytes
input standard input
output standard output
```

You are given a weighted undirected graph. The vertices are enumerated from 1 to _n_. Your task is to find the shortest path between the vertex 1 and the vertex _n_.

Input

The first line contains two integers _n_ and _m_ (2 ≤ _n_ ≤ 105, 0 ≤ _m_ ≤ 105), where _n_ is the number of vertices and _m_ is the number of edges. Following _m_ lines contain one edge each in form _a__i_, _b__i_ and _w__i_ (1 ≤ _a__i_, _b__i_ ≤ _n_, 1 ≤ _w__i_ ≤ 106), where _a__i_, _b__i_ are edge endpoints and _w__i_ is the length of the edge.

It is possible that the graph has loops and multiple edges between pair of vertices.

Output

Write the only integer -1 in case of no path. Write the shortest path in opposite case. If there are many solutions, print any of them.

ExamplesInputCopy

```text
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
```

Output

```text
1 4 3 5
```

Input

```text
5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1
```

Output

```text
1 4 3 5
```
