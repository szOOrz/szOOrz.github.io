/*
ID:cqz15311
LANG:C++
PROG:stall4
*/
#include<bits/stdc++.h>
int n,m,ans;
int Map[205][205],link[205];
bool vis[205];
using namespace std;
bool Hungary(int u){
	for (int v=1;v<=m;v++){
		if (!vis[v] && Map[u][v]){
			vis[v] = true;
			if (link[v] == -1 || Hungary(link[v])){
				link[v] = u;
				return true;
			}
		}
	}
	return false;
}
int c,x;
int main(){
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	memset(Map,false,sizeof(Map));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&c);
		while (c--){
			scanf("%d",&x);
			Map[i][x] = true;
		}
	}
	ans = 0;
	memset(link,-1,sizeof(link));
	for (int k=1;k<=n;k++){
		memset(vis,false,sizeof(vis));
		if (Hungary(k)) ans++;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4344 KB]
   Test 2: TEST OK [0.000 secs, 4344 KB]
   Test 3: TEST OK [0.000 secs, 4344 KB]
   Test 4: TEST OK [0.000 secs, 4344 KB]
   Test 5: TEST OK [0.000 secs, 4344 KB]
   Test 6: TEST OK [0.000 secs, 4344 KB]
   Test 7: TEST OK [0.000 secs, 4344 KB]
   Test 8: TEST OK [0.000 secs, 4344 KB]
   Test 9: TEST OK [0.000 secs, 4344 KB]

All tests OK.
YOUR PROGRAM ('stall4') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
*/
