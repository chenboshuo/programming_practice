#include <string.h>
bool isValid(char* s) {
    int brackets[strlen(s)];
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
// Runtime Error Message:
// Line 2: Char 9: runtime error: variable length array bound evaluates to non-positive value 0 (solution.c)
// Last executed input:
// ""
