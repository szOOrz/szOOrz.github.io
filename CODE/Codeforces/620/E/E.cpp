#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
typedef unsigned long long ULL;
const int maxn = 4e5+100;
ULL tree[maxn*4],lazy[maxn*4];
#define lc (nod << 1)
#define rc ((nod << 1) + 1)
#define mid ((l+r) >> 1)
int C[maxn],n,Q;
int In[maxn],Out[maxn];
void build(int nod,int l,int r){
	if (l == r){
		tree[nod] = 1ULL << C[l];
		lazy[nod] = 0;
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	tree[nod] = tree[lc] | tree[rc];
	lazy[nod] = 0;
}
void push_down(int nod){
	if (lazy[nod]!=0){
		tree[lc] = lazy[lc] = lazy[nod];
		tree[rc] = lazy[rc] = lazy[nod];
		lazy[nod] = 0;
	}
}
void update(int nod,int l,int r,int x,int y,ULL val){
	if (l == x && r == y){
		tree[nod] = val;
		lazy[nod] = val;
		return ;
	}
	push_down(nod);
	if (y <= mid) update(lc,l,mid,x,y,val); else
	if (x >= mid+1) update(rc,mid+1,r,x,y,val); else{
		update(lc,l,mid,x,mid,val);
		update(rc,mid+1,r,mid+1,y,val);
	}
	tree[nod] = tree[lc] | tree[rc];
}
ULL query(int nod,int l,int r,int x,int y){
	if (l == x && r == y) return tree[nod];
	push_down(nod);
	if (y <= mid) return query(lc,l,mid,x,y); else
	if (x >= mid+1) return query(rc,mid+1,r,x,y); else
	return query(lc,l,mid,x,mid) | query(rc,mid+1,r,mid+1,y);
} 
int count(ULL x){
	int Ans = 0;
	while (x){
		Ans++;
		x &= x-1;
	}
	return Ans;
}
void solve(){
	build(1,1,n);
	while (Q--){
		int type;
		scanf("%d",&type);
		if (type==1){
			int v,color;
			scanf("%d%d",&v,&color);
			update(1,1,n,In[v],Out[v],1ULL<<(color-1));
		} else{
			int v;
			scanf("%d",&v);
			printf("%d\n",count(query(1,1,n,In[v],Out[v])));
		}
	}
}
//----------------EDGE ---------------------EDGE
struct Edge{
	int to,nxt;
}edge[maxn*2];
int first[maxn],tmp[maxn],nume;
void add_edge(int a,int b){
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
int vis[maxn];
int Time;
void dfs(int u){
	In[u] = ++Time;
	vis[u] = true;
	for (int e=first[u];e!=-1;e=edge[e].nxt){
		int v = edge[e].to;
		if (!vis[v]) dfs(v);
	}
	Out[u] = Time;
}
//---------------------EDGE---------------------EDGE 
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++){
		scanf("%d",&tmp[i]);
	}
	nume = 0;
	memset(first,-1,sizeof(first));
	for (int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
		add_edge(b,a);
	}
	memset(vis,false,sizeof(vis));
	Time = 0;
	dfs(1);
	for (int i=1;i<=n;i++){
		C[In[i]] = tmp[i] - 1;
	}
	solve();
}
