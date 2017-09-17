/*
ID:cqz15311
LANG:C++
PROG:snail
*/
#include<bits/stdc++.h>
const int maxn = 125;
using namespace std;
const int dx[4] = {-1, 0,0,1};
const int dy[4] = { 0,-1,1,0};
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
bool vis[maxn][maxn];
bool f[maxn][maxn];
char s[5];
int n,B,Ans;
int getnum(){
	int a = 0;
	for (int i=1;s[i];i++) a = a*10+s[i]-48;
	return a;
}
void PT(){
	for (int i=0;i<=n+1;i++){
		for (int j=0;j<=n+1;j++){
			if (vis[i][j]) putchar('V'); else
			if (f[i][j]) putchar('#'); else putchar('.');
		}
		puts("");
	}
	puts("");
}
void dfs(int x,int y,int fx,int cnt){
	int _x,_y;
//	printf("X = %d %d %d\n",x,y,fx);
	if (f[x][y] || vis[x][y]) return;
	if (cnt > Ans) Ans = cnt;
	vis[x][y] = true;
//	printf("%d %d\n",x,y);
//	PT();
	_x = x + dx[fx];
	_y = y + dy[fx];
	if (f[_x][_y]){
		for (int d=0;d<4;d++)
			dfs(x + dx[d ],y+dy[d ],d ,cnt+1);
	}//Ç°ÃæÊÇÕÏ°­ 
	else 
			dfs(x + dx[fx],y+dy[fx],fx,cnt+1);
	vis[x][y] = false;
}
int main(){
	freopen("snail.in","r",stdin);
	freopen("snail.out","w",stdout);
	scanf("%d%d",&n,&B);
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++) f[0][i] = f[n+1][i] = 1;
	for (int i=1;i<=n;i++) f[i][0] = f[i][n+1] = 1;
	for (int i=1;i<=B;i++){
		scanf("%s",&s);
		f[getnum()][s[0] - 'A' + 1] = 1;
	}
	Ans = 0;
	memset(vis,false,sizeof(vis));
	dfs(1,1,RIGHT,1);
	dfs(1,1,DOWN,1);
	printf("%d\n",Ans);
	fclose(stdin);
	fclose(stdout);
}
/*
Executing...
   Test 1: TEST OK [0.014 secs, 4208 KB]
   Test 2: TEST OK [0.014 secs, 4208 KB]
   Test 3: TEST OK [0.014 secs, 4208 KB]
   Test 4: TEST OK [0.014 secs, 4208 KB]
   Test 5: TEST OK [0.014 secs, 4208 KB]
   Test 6: TEST OK [0.014 secs, 4208 KB]
   Test 7: TEST OK [0.014 secs, 4208 KB]
   Test 8: TEST OK [0.014 secs, 4208 KB]
   Test 9: TEST OK [0.014 secs, 4208 KB]
   Test 10: TEST OK [0.014 secs, 4208 KB]
   Test 11: TEST OK [0.014 secs, 4208 KB]
   Test 12: TEST OK [0.112 secs, 4208 KB]

All tests OK.
YOUR PROGRAM ('snail') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
*/
