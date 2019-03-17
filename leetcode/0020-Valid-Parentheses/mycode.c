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
    if(p != brackets+1){
        return false;
    }
    return true;
}
// Runtime: 4 ms, faster than 69.72% of C online submissions for Valid Parentheses.
// Memory Usage: 7.3 MB, less than 64.10% of C online submissions for Valid Parentheses.
