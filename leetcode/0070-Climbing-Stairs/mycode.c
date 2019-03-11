long long count = 0;
int climbStairs(int n) {
    if(n == 1){
        return ++count;
    }else if(n <= 0){
        return 0;
    }else if(n == 2){
        return count += 2;
    }
    if(n>1){
        climbStairs(n-1);
    }
    if(n>2){
        climbStairs(n-2);
    }

    return count;
}

// Time Limit Exceeded
