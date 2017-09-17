#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 4*1e5+100;
vector<LL> son[maxn];
struct E{
	LL from,to,dist,id,nxt;
	bool choose;
	bool operator < (const E &x) const{
		return dist < x.dist;
	}
}a[maxn];
LL dis[maxn],father[maxn];

LL root,spanning;
bool cmp_id(E &a,E &b){
	return a.id < b.id;
}
LL pa[maxn],n,m,deep[maxn],Rank[maxn];
LL getfather(LL u){
	if (father[u] == u) return father[u]; else return getfather(father[u]);
}

void Union(LL a,LL b,LL c){
	if (Rank[a] > Rank[b]){
		father[b] = a;
		dis[b] = c;
		son[a].push_back(b);
	} else
	if (Rank[a] < Rank[b]){
		father[a] = b;
		dis[a] = c;
		son[b].push_back(a);
	} else{
		father[b] = a;
		dis[b] = c;
		son[a].push_back(b);
		Rank[a] = Rank[a] + 1;
	}
}

void get_deep(LL u){
	for (int i=0;i<son[u].size();i++){
		LL v = son[u][i];
		deep[v] = deep[u] + 1;
		get_deep(v); 
	}
}

LL solve(LL u,LL v){
	LL Max = -1;
	while (u!=v){
//		printf("%d %d\n",u,v);
 		if (deep[u] > deep[v]){
			Max = max(Max,dis[u]);
			u = father[u];
		} else
		if (deep[u] < deep[v]){
			Max = max(Max,dis[v]);
			v = father[v];
		} else{
			Max = max(Max,dis[v]);
			Max = max(Max,dis[u]);
			u = father[u];
			v = father[v];
		}
	}
	return Max;
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	for (LL i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&a[i].from,&a[i].to,&a[i].dist);
		a[i] . id = i;
		a[i] . choose = false;
	}
	sort(a+1,a+1+m);
	for (LL i=1;i<=n;i++) father[i] = i,Rank[i] = 0,dis[i] = 0,son[i].clear();
	LL num = 0;
	for (LL i=1;i<=m && num!=n-1;i++){
		int u = getfather(a[i].from);
		int v = getfather(a[i].to);
		if (u!=v) {
			Union(u,v,a[i].dist);
			a[i].choose = true;
			spanning += a[i].dist;
		}
	}
//	printf("*%d\n",spanning);
	sort(a+1,a+1+m,cmp_id);
	int root = -1;
	for (int i=1;i<=n;i++) if (father[i] == i) root = i;
	deep[root] = 0;
	get_deep(root);
	for (LL i=1;i<=m;i++){
		if (a[i].choose) printf("%I64d\n",spanning); else{
//		printf("%I64d,%I64d:%I64d\n",a[i].from,a[i].to,solve(a[i].from,a[i].to));
			printf("%I64d\n",spanning - solve(a[i].from,a[i].to) + a[i].dist);
		}
	}
	return 0;
}
