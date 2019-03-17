#include <string.h>
bool isValid(char* s) {
    int brackets[strlen(s)+2];
    int *p = brackets+1;
    for(int i=0; *(s+i); i++){
        switch(*(s+i)){
                case'(': *p=1; p++; break;
                case')': if(*(p-1) == 1) {p--;} else{return false;}break;
                case'[': *p=2; p++; break;
                case']': if(*(p-1) == 2) {p--;} else{return false;} break;
                case'{': *p = 3; p++; break;
                case'}': if(*(p-1) == 3) {p--;} else{return false;} break;
        }
    }
    return true;
}
// Input:
// "["
// Output:
// true
// Expected:
// false
