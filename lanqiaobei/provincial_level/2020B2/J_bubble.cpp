#include<cstdio>
#include<climits>
#include<cstdlib>

struct solution{
	int sum;
	int len;
	int num_of_letter[256];
};
struct solution *best, *cur;
int target;
int max_; // unknown
int len; // unknown

bool is_better(char j){
	char i = 'z';
	// pass invalid
	while(best->num_of_letter[i] == 0){
		--i;
	}
	if(i==j){
		while(i >= 'a' /* && j >= 'a' */){
			if(best->num_of_letter[i] > cur->num_of_letter[j]){
				return true;
			}
			--i;
			--j;
		}
	}
	return i > j;
}

void search(char letter, int right){
	if(cur->sum > target ||
		letter > max_ ||
		cur->len > best->len ||
		(cur->len == best->len && cur->sum != target)||
		(letter == max_ && cur->sum != target)){
			return;
		}

	if(cur->sum == target){
		if(cur->len < best->len || is_better(letter)){
			best->len = cur -> len;
			for(char i='a';i<='z';++i){
				best->num_of_letter[i] = cur->num_of_letter[i];
			}
		}
		return ;
	}
	for(char i=1; i <= right;++i){
		struct solution pre = *cur;
		cur->len += i;
		cur->sum +=(i*(cur->len));
		search(letter+i,i);
		*cur = pre;
	}
	cur->num_of_letter[letter+1] = 0;
}


int main() {
	scanf("%d",&target);
	cur = (struct solution*)calloc(1,sizeof(struct solution));
	best = (struct solution*)calloc(1,sizeof(struct solution));
	while(best->sum < target){
		char min_letter = 1;
		for(char c='b';c<='z';++c){
			if(best->num_of_letter[c] < best->num_of_letter[min_letter]){
				min_letter = c;
			}
		}
		best->sum += 
	}

}
