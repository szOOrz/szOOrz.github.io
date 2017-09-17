#include<bits/stdc++.h>
using namespace std;
const int maxn = 205000;
int father[maxn],color[maxn];
bool vis[maxn];
int cnt1,cnt2,ans1[maxn],ans2[maxn];
int n,m;
int getfather(int u){
	if (father[u] == u) return u ; else 
	return father[u] = getfather(father[u]);
}
void Union(int a,int b){
	int u = getfather(a);
	int v = getfather(b);
	if (u <= n) father[v] = u; else father[u] = v;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=2*n;i++) father[i] = i;
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		vis[a] = vis[b] = true;
		if (getfather(a) == getfather(b)){
			puts("-1");
			return 0;
		}
		Union(a+n,b);
		Union(a,b+n);
	}
	memset(color,0,sizeof(color));
	for (int i=1;i<=n;i++){
		if (!vis[i]) continue;
		color[i] = color[getfather(i)];
		if (color[i] == 0)
			color[i] = color[getfather(i)] = 3-color[getfather(i+n)];
		if (color[i] == 0){
			color[i] = color[getfather(i)] = 1;
			color[getfather(i+n)] = 2;
		}
		if (color[i] == 1){
			ans1[++cnt1] = i ;
		} else
			ans2[++cnt2] = i;
	} 
	printf("%d\n",cnt1);
	for (int i=1;i<=cnt1;i++) printf("%d ",ans1[i]);
	puts("");
	printf("%d\n",cnt2);
	for (int i=1;i<=cnt2;i++) printf("%d ",ans2[i]);
	puts("");
	return 0;
}
