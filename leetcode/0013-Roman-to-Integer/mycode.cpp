/**
 * reference:
 * https://leetcode.com/problems/roman-to-integer/discuss/6857/Simple-c-code-in-18ms
 *
 */
int romanToInt(char* s) {
    int ans=0;
    int a=0;
    int num=0;
    int n[256]={0};

    n['I'] = 1;
    n['V'] = 5;
    n['X'] = 10;
    n['L'] = 50;
    n['C'] = 100;
    n['D'] = 500;
    n['M'] = 1000;
    for(;*s;s++){
        a = num;
        num = n[*s];
        if(a<num){
            ans -= 2*a;
        }
        ans += num ;
    }
    return ans;
}
/**
 * Runtime: 40 ms,
 * faster than 87.77% of C online submissions for Roman to Integer.
 * Memory Usage: 29.6 MB,
 * less than 80.43% of C online submissions for Roman to Integer.
 */
