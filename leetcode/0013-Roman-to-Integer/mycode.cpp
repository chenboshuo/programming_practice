int romanToInt(char* s) {
    int ans=0;
    int a=0;
    int num;
    for(int i=0;s[i];i++){
        a = num;
        switch(s[i]){
            case 'I': num = 1; break;
            case 'V': num = 5; break;
            case 'X': num = 10; break;
            case 'L': num = 50; break;
            case 'C': num = 100; break;
            case 'D': num = 500; break;
            case 'M': num = 1000; break;
        }
        if(a<num){
            num -= 2*a;
        }
        ans += num ;
    }
    return ans;
}
/**
 * Runtime: 44 ms,
 * faster than 64.63% of C online submissions for Roman to Integer.
 * Memory Usage: 29.5 MB,
 * less than 86.96% of C online submissions for Roman to Integer.
 */
