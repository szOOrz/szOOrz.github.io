/*
ID:cqz15311
LANG:C++
PROG:milk6 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL oo = 1LL<<50;
const int maxv = 35;
const int maxe = 2005;
struct Edge{
	int from,to,nxt;
	LL cap,flow;
};
struct G{
	int nume;
	int first[maxv],cur[maxv],path[maxv],num[maxv+2],n;
	int dist[maxv];
	Edge edge[maxe * 2];
	LL Max_flow;
	
	void init(int n){
		this -> n = n;
		nume = 0;
		memset(first,-1,sizeof(first));
	}
	void add_edge(int a,int b,int c){
		edge[nume] . from = a;
		edge[nume] . to   = b;
		edge[nume] . cap  = c;
		edge[nume] . flow = 0;
		edge[nume] . nxt  = first[a];
		first[a] = nume++;
		edge[nume] . from = b;
		edge[nume] . to   = a;
		edge[nume] . cap  = 0;
		edge[nume] . flow = 0;
		edge[nume] . nxt  = first[b];
		first[b] = nume++;
	}
	void Reset(){
		for (int i=0;i<nume;i++) edge[i] . flow = 0;
	}
	LL sap(int s,int t){
		Reset();
		Max_flow = 0;
		memset(num,0,sizeof(num));
		num[0] = n;
		memset(dist,0,sizeof(dist));
		for (int i=1;i<=n;i++) cur[i] = first[i];
		int u = s;
		while (dist[s] < n){
//			printf("%d\n",u);
			if (u == t){
				LL Min_flow = oo,break_point;
				//Augment
				for (int v=t;v!=s;v=edge[path[v]].from){
					if (edge[path[v]] . cap - edge[path[v]] . flow < Min_flow){
						Min_flow = edge[path[v]] . cap - edge[path[v]] . flow;
						break_point = edge[path[v]] . from;
					}
				}
				Max_flow += Min_flow;
				for (int v=t;v!=s;v=edge[path[v]].from){
					edge[path[v]] . flow += Min_flow;
					edge[path[v]^1] .flow -= Min_flow;
				}
				u = break_point;
			} else{
				bool found = false;
				for (int &e = cur[u];e!=-1;e=edge[e].nxt){
					if ((edge[e].cap > edge[e].flow) && (dist[edge[e].to] + 1 == dist[u])){
						path[edge[e].to] = e;
						u = edge[e].to;
						found = true;
						break;
					}
				}
				if (!found){
					int tmp = n+1;
					for (int e=first[u];e!=-1;e=edge[e].nxt){
						if (edge[e].cap > edge[e].flow){
							tmp = min(tmp,dist[edge[e].to] + 1);
						}
					}
					if (--num[dist[u]] == 0) return Max_flow;
					dist[u] = tmp;
					num[tmp]++;
					cur[u] = first[u];
					if (u != s) u = edge[path[u]] . from;
				}
			}
		}
		return Max_flow;
	}
}G;
int ans[maxe+1];
int a[maxe],b[maxe];
LL c[maxe];
int main(){
	freopen("milk6.in","r",stdin);
	freopen("milk6.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	G.init(n);
	for (int i=0;i<m;i++){
		scanf("%d%d%lld",&a[i],&b[i],&c[i]);
		c[i] = c[i] * 1001 + 1;
		G.add_edge(a[i],b[i],c[i]);
	}
	LL Max_flow = G.sap(1,n);
	printf("%lld ",Max_flow / 1001);
	memset(ans,0,sizeof(ans));
	for (int i=0;i<m;i++){
		G.edge[i*2] . cap = 0;
		LL tmp = G.sap(1,n);
		if (Max_flow - tmp == c[i]){
			ans[++ans[0]] = i+1;
			Max_flow -= c[i];
		} else
			G.edge[i*2] . cap = c[i];
	}
	printf("%d\n",ans[0]);
	if (ans[0] != 0){
		printf("%d\n",ans[1]);
		for (int i=2;i<=ans[0];i++){
			printf("%d\n",ans[i]);
		}
	} 
	fclose(stdin);
	fclose(stdout);
}
/*

Executing...
   Test 1: TEST OK [0.000 secs, 4328 KB]
   Test 2: TEST OK [0.000 secs, 4328 KB]
   Test 3: TEST OK [0.000 secs, 4328 KB]
   Test 4: TEST OK [0.000 secs, 4328 KB]
   Test 5: TEST OK [0.056 secs, 4328 KB]
   Test 6: TEST OK [0.000 secs, 4328 KB]
   Test 7: TEST OK [0.000 secs, 4328 KB]
   Test 8: TEST OK [0.000 secs, 4328 KB]
   Test 9: TEST OK [0.014 secs, 4328 KB]
   Test 10: TEST OK [0.154 secs, 4328 KB]
   Test 11: TEST OK [0.000 secs, 4328 KB]
   Test 12: TEST OK [0.000 secs, 4328 KB]

All tests OK.

*/
