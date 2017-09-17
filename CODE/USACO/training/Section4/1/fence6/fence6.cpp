/*
ID:cqz15311
LANG:C++
PROG:fence6
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
int start,ans,n,c;
int f[305],num[305][2],map[305][2][305];
bool vis[305];
int find(int a,int b){
  for (int i=1;i<=num[b][0];i++)
    if (map[b][0][i]==a) return 0;
  return 1;
}

void dfs(int u,int d,int s){
	if (s > ans) return;
	if (u == start && s > 0){
		ans = s;
		return ;
	}
	vis[u] = true;
	for (int i=1;i<=num[u][d];i++){
		//之前从左边过来的，现在要往右边去
		//否则，从右边要到左边
		int v = map[u][d][i];
		if (!vis[v] || (v == start)) 
			dfs(v,find(u,v) ^ 1,s + f[u]); 
			//方向是不确定的…… 
	}
	vis[u] = false;
}
int main(){
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&c);
		scanf("%d%d%d",&f[c],&num[c][0],&num[c][1]);
		for (int j=1;j<=num[c][0];j++) scanf("%d",&map[c][0][j]);
		for (int j=1;j<=num[c][1];j++) scanf("%d",&map[c][1][j]);
		//读入边 
	}
	ans = 0x3fffffff;
	for (start = 1; start <= n;start ++){
		memset(vis,false,sizeof(vis));
		dfs(start,0,0);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 4908 KB]
   Test 2: TEST OK [0.000 secs, 4908 KB]
   Test 3: TEST OK [0.000 secs, 4908 KB]
   Test 4: TEST OK [0.000 secs, 4908 KB]
   Test 5: TEST OK [0.000 secs, 4908 KB]
   Test 6: TEST OK [0.000 secs, 4908 KB]
   Test 7: TEST OK [0.000 secs, 4908 KB]
   Test 8: TEST OK [0.000 secs, 4908 KB]
   Test 9: TEST OK [0.000 secs, 4908 KB]

All tests OK.
YOUR PROGRAM ('fence6') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
其它方法可参考
http://train.usaco.org/usacoanal2?a=i62AGyUxgsm&S=fence6 
*/ 
