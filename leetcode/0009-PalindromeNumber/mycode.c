bool isPalindrome(int x) {
    if(x < 0) return false;

    int i = 0;
    int s[20];

    do{
        s[i++] = x % 10;
        x /= 10;
    }while(x);
    for(int *p=s,*q=s+i-1; p!=q; p++,q--){
        if (*p != *q) return false;
    }
    return true;
}
// 	Runtime Error
