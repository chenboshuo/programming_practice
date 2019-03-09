bool isPalindrome(int x) {
    if(x < 0) return false;

    int i = 0;
    int s[20];

    do{
        s[i++] = x % 10;
        x /= 10;
    }while(x);
    for(int *p=s,*q=s+i-1; p<q; p++,q--){
        if (*p != *q) return false;
    }
    return true;
}
// Runtime: 112 ms, faster than 75.35% of C online submissions for Palindrome Number.
// Memory Usage: 72.2 MB, less than 6.38% of C online submissions for Palindrome Number.
