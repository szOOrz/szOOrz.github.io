#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn = 4e5+100;
struct Edge{
	int to,nxt;
}edge[maxn * 2];
int n;
int nume,first[maxn],vis[maxn],a[maxn],Ans[maxn];
void add_edge(int a,int b){
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
void dfs1(int u,int GCD){
	vis[u] = true;
	Ans[u] = GCD;
	for (int e=first[u];e!=-1;e=edge[e].nxt){
		int v = edge[e] . to ;
		if (!vis[v]) dfs1(v,__gcd(GCD,a[v]));
	}
}
void dfs2(int u,bool flag,int Pre){
//	printf("%d\n",Pre);
	vis[u] = true;
	bool _flag = flag;
	if (a[u] % Pre){
		if (flag) return;
		_flag = true;
	}
	Ans[u] = max(Ans[u],Pre);
	for (int e=first[u];~e;e=edge[e].nxt){
		int v = edge[e].to;
		if (!vis[v]) dfs2(v,_flag,Pre);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(first,-1,sizeof(first));
	nume = 0;
	for (int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	memset(Ans,-1,sizeof(Ans));
	Ans[1] = a[1];
	//考虑先得到排除root的GCD
	memset(vis,false,sizeof(vis));
	vis[1] = true;
	for (int i=first[1];~i;i=edge[i].nxt){
		dfs1(edge[i].to,a[edge[i].to]);
	}
	//考虑枚举因数 
	for (int i=1;i*i<=a[1];i++){
		if (a[1] % i == 0){
			//可以作为gcd
			memset(vis,false,sizeof(vis));
			dfs2(1,false,i);
			memset(vis,false,sizeof(vis));
			dfs2(1,false,a[1] / i);
		}
	}
	
	for (int i=1;i<=n;i++){
		printf("%d ",Ans[i]);
	}
	return 0;
}
