int climbStairs(int n) {
    if(n == 0 || n == 1){
        return 1;
    }
    int first = 1, second = 1;
    int third = 2;
    for(int i = 1; i<n; i++){
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

// Runtime: 4 ms, faster than 59.26% of C online submissions for Climbing Stairs.
// Memory Usage: 7.1 MB, less than 18.00% of C online submissions for Climbing Stairs.
