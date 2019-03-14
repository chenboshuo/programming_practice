int memo[256] = {0};

int climbStairs(int n) {
     if(memo[n]){
        return memo[n];
    }
    if(n == 0 || n == 1){
        memo[0] = 1;
        memo[1] = 1;
        return 1;
    }
    memo[n] = climbStairs(n - 1) +climbStairs(n - 2);
    return memo[n];
}

// Runtime: 4 ms, faster than 54.89% of C online submissions for Climbing Stairs.
// Memory Usage: 7 MB, less than 24.00% of C online submissions for Climbing Stairs.
