int fib(int N) {
    if(N == 0) return 0;
    if(N == 1) return 1;
    return fib(N-1) + fib(N-2);
}
// Runtime: 12 ms
// Memory Usage: 6.6 MB
// Your runtime beats 40.45 % of c submissions.
// Your memory usage beats 93.67 % of c submissions.
