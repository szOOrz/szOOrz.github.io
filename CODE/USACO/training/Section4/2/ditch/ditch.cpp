/*
ID:cqz15311
LANG:C++
PROG:ditch
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int oo = 1<<20;
const int maxv = 205;
const int maxe = 405;
struct Edge{
	int to,nxt,cap,flow;
}edge[maxe];
int first[maxv],work[maxv];
int dist[maxv];
int q[maxv];
int nume,n,m,s,t;
void add_edge(int a,int b,int c){
	edge[nume] . to = b;
	edge[nume] . cap = c;
	edge[nume] . flow = 0;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
	edge[nume] . to = a;
	edge[nume] . cap = 0;
	edge[nume] . flow = 0;
	edge[nume] . nxt = first[b];
	first[b] = nume++;
}
void init(){
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	s = 1;
	t = m;
	for (int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
	}
}
bool dinic_bfs(){
	int front = 0,rear = 0;
	memset(dist,-1,sizeof(dist));
	q[rear++] = s;dist[s] = 0;
	while (front < rear){
		int u = q[front++];
		for (int e=first[u];e!=-1;e=edge[e].nxt){
			if ((edge[e].cap > edge[e].flow) && (dist[edge[e].to] < 0)){
				dist[edge[e].to] = dist[u] + 1;
				q[rear++] = edge[e].to;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic_dfs(int u,int c){
	if (u == t) return c;
	for (int &e=work[u];e!=-1;e=edge[e].nxt)
	if ((edge[e].cap > edge[e].flow) && (dist[edge[e].to] == dist[u] + 1)){
		int tmp = dinic_dfs(edge[e].to,min(c,edge[e].cap-edge[e].flow));
		if (tmp > 0){
			edge[e] . flow += tmp;
			edge[e ^ 1].flow -= tmp;
			return tmp;
		}
	}
	return 0;
} 

int dinic_flow(){
	int rec = 0;
	while (dinic_bfs()){
		for (int i=1;i<=m;i++) work[i] = first[i];
		while (1){
			int d = dinic_dfs(s,oo);
			if (d == 0) break;
			rec += d;
		}
	}
	return rec;
}

int main(){
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	init();
	printf("%d\n",dinic_flow());
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*

Executing...
   Test 1: TEST OK [0.000 secs, 4188 KB]
   Test 2: TEST OK [0.000 secs, 4188 KB]
   Test 3: TEST OK [0.000 secs, 4188 KB]
   Test 4: TEST OK [0.000 secs, 4188 KB]
   Test 5: TEST OK [0.000 secs, 4188 KB]
   Test 6: TEST OK [0.000 secs, 4188 KB]
   Test 7: TEST OK [0.000 secs, 4188 KB]
   Test 8: TEST OK [0.000 secs, 4188 KB]
   Test 9: TEST OK [0.000 secs, 4188 KB]
   Test 10: TEST OK [0.000 secs, 4188 KB]
   Test 11: TEST OK [0.000 secs, 4188 KB]
   Test 12: TEST OK [0.000 secs, 4188 KB]

All tests OK.
YOUR PROGRAM ('ditch') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
*/
