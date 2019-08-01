#define max(a, b) (a) > (b) ? (a) : (b)
int *ans;

char *addStrings(char *num1, char *num2) {
  int l1 = strlen(num1);
  int l2 = strlen(num2);
  int l = max(l1, l2) + 1;
  // ans = (char*)malloc(sizeof(char) * (l+1));
  int c = 0, s;
  for (l1 = l1 - 1, l2 = l2 - 1, l = l - 1; l1 >= 0 && l2 >= 0;
       --l1, --l2, --l) {
    s = num1[l1] + num2[l2] - 2 * '0';
    c = s / 10;
    ans[l] = s % 10 + '0';
  }
  return ans + c / 10;
}
//
// 手残,一不小心提交了
// https://leetcode.com/submissions/detail/243216166/
// AddressSanitizer: SEGV on unknown address 0x000000000004 (pc 0x000000401934
// bp 0x7ffd228bf020 sp 0x7ffd228bf000 T0) 因该因为内存溢出
