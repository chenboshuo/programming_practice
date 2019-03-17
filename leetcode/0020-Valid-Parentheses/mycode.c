bool isValid(char* s) {
    int brackets[100];
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
// AddressSanitizer: stack-buffer-underflow on address 0x7ffc06f490ec at pc 0x000000401996 bp 0x7ffc06f490c0 sp 0x7ffc06f490b8
// Last executed input:
// "]"
