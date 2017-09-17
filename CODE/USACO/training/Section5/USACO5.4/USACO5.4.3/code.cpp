/*
ID:cqz15311
LANG:C++
PROG:telecow
*/
#include<bits/stdc++.h> 
const int maxn = 105;
const int maxm = 606;
const int oo = 10000000;
const int maxv = maxn * 2;
const int maxe = maxn * 2 + maxm * 2;
using namespace std;
struct Edge{
	int from,to,nxt,cap,flow;
};
struct Graph{
	Edge edge[maxe * 2];
	int first[maxv],nume,n;
	int num[maxv],cur[maxv],path[maxv],dist[maxv];
	int Max_flow;
	void init(int n){
		this -> n = n;
		memset(first,-1,sizeof(first));
		nume = 0;
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
		for (int i=0;i<nume;i++) edge[i].flow = 0;
	} 
	
	int SAP(int s,int t){
		Reset();
//		printf("%d-->%d\n",s,t);
		memset(num,0,sizeof(num));
		memset(dist,0,sizeof(dist));
		for (int i=0;i<n;i++) cur[i] = first[i];
		num[0] = n;
		int u = s;
		Max_flow = 0;
		while (dist[s] != n+1){
//			printf("U = %d\n",u);
			if (u == t){
				int Min_flow = oo;
				int break_point = 0;
				for (int v=t;v!=s;v=edge[path[v]].from)
					if (edge[path[v]].cap - edge[path[v]].flow <= Min_flow){
						Min_flow = edge[path[v]].cap - edge[path[v]].flow;
						break_point = edge[path[v]].from;
					}
				Max_flow += Min_flow;
//				printf("Add = %d\n",Min_flow);
				for (int v=t;v!=s;v=edge[path[v]].from){
					edge[path[v]].flow += Min_flow;
					edge[path[v]^1].flow -= Min_flow;
				}
//				printf("%d-->%d\n",u,break_point);
				u = break_point;
			} else{
				bool found = false;
				for (int &e=cur[u];~e;e=edge[e].nxt)
					if ((edge[e].cap > edge[e].flow) && (dist[edge[e].to] +1 == dist[u])){
						path[edge[e].to] = e;
						u = edge[e].to;
						found = true;
						break;
					}
				if (!found){
					int tmp = n + 1;
					for (int e=first[u];~e;e=edge[e].nxt)
						if (edge[e].cap > edge[e].flow)
							tmp = min(tmp,dist[edge[e].to]+1);
					if (--num[dist[u]] == 0) return Max_flow;
					dist[u] = tmp;
					num[tmp]++;
					cur[u] = first[u];
					if (u!=s) u = edge[path[u]].from;
				}
			}
		}
		return Max_flow;
	}
}G;
int n,m,c1,c2;
int main(){
	freopen("telecow.in","r",stdin);
	freopen("telecow.out","w",stdout); 
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	G.init(2*n);
	for (int i=1;i<=n;i++){
		G.add_edge(i*2-2,2*i-1,1),
		G.add_edge(i*2-1,i*2-2,1);
	}
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G.add_edge(a*2-1,b*2-2,oo);
		G.add_edge(b*2-1,a*2-2,oo);
	}
	int Max_flow = G.SAP(c1*2-1,2*c2-2);
	printf("%d\n",Max_flow);
	vector<int> Ans;
	Ans . clear();
	for (int i=1;i<=n;i++){
//		if (i == c1 || i == c2) continue;
		G.edge[i*4-4].cap = 0;
		G.edge[i*4-2].cap = 0;
//		printf("Delete(%d) = %d \n",i,G.SAP(c1*2-1,2*c2-2));
		if (Max_flow - G.SAP(c1*2-1,2*c2-2) == 1){
			Max_flow --;
			Ans.push_back(i);
		} else{
//			printf("Restore\n"); 
			G.edge[i*4-4].cap = 1;
			G.edge[i*4-2].cap = 1;
		}
	}
	if (Ans.size() != 0){
		printf("%d",Ans[0]);
		for (int i=1;i<Ans.size();i++){
			printf(" %d",Ans[i]);
		}
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4236 KB]
   Test 2: TEST OK [0.000 secs, 4236 KB]
   Test 3: TEST OK [0.000 secs, 4236 KB]
   Test 4: TEST OK [0.000 secs, 4236 KB]
   Test 5: TEST OK [0.000 secs, 4236 KB]
   Test 6: TEST OK [0.000 secs, 4236 KB]
   Test 7: TEST OK [0.000 secs, 4236 KB]
   Test 8: TEST OK [0.000 secs, 4236 KB]
   Test 9: TEST OK [0.000 secs, 4236 KB]
   Test 10: TEST OK [0.014 secs, 4236 KB]
   Test 11: TEST OK [0.014 secs, 4236 KB]

All tests OK.
YOUR PROGRAM ('telecow') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
*/
