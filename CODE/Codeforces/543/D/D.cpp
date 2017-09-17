#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9+7;
const int maxn = 2e5+100;
struct Edge{
	int to,nxt;
}edge[maxn * 2];
int nume,first[maxn];
int vis[maxn],n,p;
int f[maxn],Ans[maxn],g[maxn];
void add_edge(int a,int b){
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
int get_dp(int u){
	vis[u] = true;
	f[u] = 1;
	for(int e=first[u];e!=-1;e=edge[e].nxt){
		int v = edge[e].to;
		if (vis[v]) continue;
		get_dp(v);
		f[u] = 1LL * f[u] * (f[v] + 1) % Mod;
	};
	g[u] = f[u];
}
int Pow(int a,int b){
	int Ans = 1;
	for (;b;b>>=1,a=1LL*a*a % Mod){
		if (b&1) Ans=1LL * Ans * a % Mod;
	}
	return Ans;
}
int inv(int x){
//	if (x == 0) return 1;
	return Pow(x,Mod-2);
}

void solve(int u, int g,int fa){
	Ans[u] = 1LL * f[u] * g % Mod;
	for (int e=first[u];~e;e=edge[e].nxt)
		if (edge[e].to != fa && f[edge[e].to] != Mod-1)
			solve(edge[e].to, (1LL * g * f[u] % Mod * inv(f[edge[e].to]+1) % Mod + 1) % Mod,u);
		else if (edge[e].to != fa){
			int res = 1;
			for (int j=first[u]; ~j; j=edge[j].nxt)
				if (edge[j].to != fa && edge[j].to!=edge[e].to)
					res = 1LL * res * (f[edge[j].to] + 1) % Mod;
			solve(edge[e].to, (1LL * g * res % Mod + 1) % Mod,u);
		}
}
int main(){
	scanf("%d",&n);
	nume = 0;
	memset(first,-1,sizeof(first));
	for (int i=2;i<=n;i++){
		scanf("%d",&p);
		add_edge(i,p);
		add_edge(p,i);
	}
	memset(f,0,sizeof(f));
	memset(vis,false,sizeof(vis));
	get_dp(1);
	memset(Ans,-1,sizeof(Ans));
	memset(vis,false,sizeof(vis));
	solve(1,1,-1);
	for (int i=1;i<=n;i++) printf("%d ",Ans[i]);
}
