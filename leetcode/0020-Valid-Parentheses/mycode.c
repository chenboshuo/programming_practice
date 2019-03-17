bool isValid(char* s) {
    int a = 0;//()
    int b = 0;//[]
    int c = 0;//{}
    for(int i=0; *(s+i); i++){
        switch(*(s+i)){
                case'(': a+=1; break;
                case')': a-=1; break;
                case'[': b+=1; break;
                case']': b-=1; break;
                case'{': c+=1; break;
                case'}': c-=1; break;
        }
    }
    if(a || b || c){
        return false;
    }
    return true;
}
// Input:
// "([)]"

// Output:
// true

// Expected:
// false
// 想法太天真
