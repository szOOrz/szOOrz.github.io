#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn = 5*1e5+100;
struct Edge{
	int to,nxt;
}edge[maxn*2];
int first[maxn],nume;
int n,Ans;
void add_edge(int a,int b){
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
vector<int> f;
bool vis[maxn];
void dfs(int u,int deep){
	vis[u] = true;
	bool left = true;
	for (int e=first[u];~e;e=edge[e].nxt){
		int v = edge[e].to;
		if (!vis[v]){
			left = false;
			dfs(v,deep+1);
		}
	} 
	if (left){
		f.push_back(deep);
	}
}
int main(){
	scanf("%d",&n);
	memset(first,-1,sizeof(first));
	nume = 0;
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	memset(vis,false,sizeof(vis));
	vis[1] = true;
	Ans = 0;
	for (int e=first[1];~e;e=edge[e].nxt){
		f.clear();
		dfs(edge[e].to,1);
		sort(f.begin(),f.end());
		for (int i=1;i<(int)f.size();i++){
			f[i] = max(f[i-1]+1,f[i]);
		}
		Ans = max(Ans,f[(int)f.size()-1]);
	}
	printf("%d\n",Ans);
	return 0;
}
