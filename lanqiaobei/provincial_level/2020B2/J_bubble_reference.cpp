#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e4+5;

int num[N], res[N];
int n, m, _max, len;

bool judge(int letter) {
	int i = 26, j = letter;
	while (!res[i]) i--;
	if (i == j) {
		while (i > 0 && j > 0) {
			if (res[i] != num[j]) {
				return res[i] > num[j];
			} else {
				i--; j--;
			}
		}
	}
	return i > j;
}

void dfs(int letter, int curlen, int cursum, int l) {
	if (cursum > n) return ;
	if (letter > _max) return ;
	if (curlen > len) return ;
	
	if (curlen == len && cursum != n) return ;
	if (letter == _max && cursum != n) return ;
	
	if (cursum == n) {
		if (curlen < len || judge(letter)) { //长度减小或字典序减小更新结果
			len = curlen;
			for (int i = 1; i <= 26; i++) {
				res[i] = num[i];
			}
		}
		return ;
	}

	for (int i = 1; i <= l; i++) {
		num[letter + 1] = i;
		dfs(letter + 1, curlen + i, cursum + i * curlen, i);
	}
	num[letter + 1] = 0;
}


int main() {
	// scanf("%d", &n);
	// n = 4;
	n = 10000;
	n = 1000;
	m = 0; len = 0;
	while (m < n) {
		int id = 1;
		printf("\nm=%d\n",m);
		for (int i = 2; i <= 26; i++) { //找到s最小的点, 如果存在多个取字典序更小的
      if (res[i] < res[id]) id = i;
		}
		
		m += len - res[id];
		_max = max(_max, id);
		len ++; res[id] ++;

		for (int i = _max; i >= 1; i--) {
			for (int j = res[i]; j > 0; j--) {
				printf("%c", i-1+'a');
			}
		}
	}
	printf("\n");
	printf("m=%d\n",m);
	dfs(0, 0, 0, 100);
	for (int i = _max; i >= 1; i--) {
		for (int j = res[i]; j > 0; j--) {
			printf("%c", i-1+'a');
		}
	}
	printf("\n");  
	return 0;
	}
