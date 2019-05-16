#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)

char * addStrings(char * num1, char * num2){
    char *p1 = num1 + strlen(num1) - 1;
    char *p2 = num2 + strlen(num2) - 1;
    char *ans =( char *)malloc(max(strlen(num1), strlen(num2))*sizeof(char) + 1);
    char *p3 = ans + strlen(ans) - 1;
    int n = min(strlen(num1), strlen(num2)) - 1;
    *p3 = *p1 + *p2;
    while(n--){
        *p3 += *p1 + *p2 - '0';
        if(*p3 > '9'){
            --*p3;
            p3--;
            *p3 = 1;
        }else{
            *(--p3) = 0;
        }
    }
    return ans;
}


