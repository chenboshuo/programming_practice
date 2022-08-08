#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAX 0x3f3f3f3f
using namespace std;

int mp[15][15];
int vis[15][15];
int dir[4][2] = {0,1, 1,0, 0,-1, -1,0};
int n, m;
int ans, tot;
bool check(int x, int y){
    if(x<1 || x>n || y<1 || y>m || vis[x][y]) return false;
    return true;
}
//（x,y）当前格子， cnt 表示连续格子的个数， sum为cnt个格子内的数字之和 
void dfs(int x, int y, int cnt, int sum){ 
    if(sum*2 == tot)
        if(ans > cnt) ans = cnt;
    if(ans <= cnt) return;
    for(int i=0; i<4; ++i){
        int xx = x+dir[i][1];
        int yy = y+dir[i][0];
        if(check(xx, yy)){
            vis[xx][yy] = 1;
            dfs(xx, yy, cnt+1, sum+mp[xx][yy]);
            vis[xx][yy] = 0;
        }
    }
}

int main(){
    while(scanf("%d%d", &m, &n) != EOF){
        tot = 0;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                scanf("%d", &mp[i][j]), tot+=mp[i][j];
        ans = MAX;
        vis[1][1] = 1;
        dfs(1, 1, 1, mp[1][1]);
        if(ans == MAX) ans=0;
        printf("%d\n", ans);
    }
    return 0;
}