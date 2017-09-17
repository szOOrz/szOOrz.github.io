#include<bits/stdc++.h> 
using namespace std;
const int maxn = 305050;
const int maxm = 305050;
struct Edge{
	int from,to;
	char color;
}edge[maxm];
int father[maxn*3];
int n,m;
int getfather(int u){
	if (father[u] == u) return u;
	father[u] = getfather(father[u]);
	return father[u];
}
void Union(int a,int b){
	int u = getfather(a);
	int v = getfather(b);
	if (u <= n) father[v] = u; else
	if (v <= n) father[u] = v; else
				father[u] = v;
}
bool vis[maxn];
int Rec[maxn],cnt1[maxn],cnt2[maxn];
int ans[2][maxn];
void solve(int k){
	for (int i=1;i<=n;i++){
		father[i] = i;
		father[i+n] = i+n;
		father[i+2*n] = i+2*n;
	}
	//考虑全部变成蓝色 
	for (int i=1;i<=m;i++){
		int u,v;
		u = edge[i].from;
		v = edge[i].to;
		Union(u+2*n,v+2*n);
		if (edge[i].color == 'R'){
			if (getfather(u) == getfather(v)){ans[k][0] = 1e9;return ;}
			//两边只有一边选 
			Union(u,v+n);
			Union(u+n,v);
		} else{
			if (getfather(u) == getfather(v+n)) {ans[k][0] = 1e9;return ;}
			Union(u,v);
			Union(u+n,v+n);
		}
	}
	memset(vis,false,sizeof(vis));
	memset(cnt1,0,sizeof(cnt1));
	memset(cnt2,0,sizeof(cnt2));
	for (int i=1;i<=n;i++)
			 if (vis[getfather(i)])   cnt1[getfather(i)]++;
		else if (vis[getfather(n+i)]) cnt2[getfather(n+i)]++;
		else {
			vis[getfather(i)] = 1;
			cnt1[getfather(i)] = 1;
		}

	for (int i=1; i<=n; i++)
		if (vis[getfather(i)] && cnt1[getfather(i)] <= cnt2[getfather(i)]) ans[k][++ans[k][0]] = i; else
		if (vis[getfather(i+n)] && cnt1[getfather(i+n)] > cnt2[getfather(i+n)]) ans[k][++ans[k][0]] = i;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d %c",&edge[i].from,&edge[i].to,&edge[i].color);
	memset(ans,0,sizeof(ans));
	solve(0);
	for (int i=1;i<=m;i++)
		if (edge[i].color == 'R') edge[i].color = 'B'; else edge[i].color = 'R';
	solve(1);
	if (ans[0][0] > n && ans[1][0] > n){
		puts("-1");
	} else
	if ((ans[0][0] > ans[1][0])){
		printf("%d\n",ans[1][0]);
		for (int i=1;i<=ans[1][0];i++)
			printf("%d ",ans[1][i]);
	} else{
		printf("%d\n",ans[0][0]);
		for (int i=1;i<=ans[0][0];i++)
			printf("%d ",ans[0][i]);
	}
	return 0;
} 
