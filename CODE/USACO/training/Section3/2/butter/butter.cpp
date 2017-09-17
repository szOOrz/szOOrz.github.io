/*
ID:cqz15311
LANG:C++
PROG:butter
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
const int maxe = 1455*2;
const int maxv = 805;
const int oo = 1<<20;
struct Node{
	int id,val;
	bool operator < (const Node &x) const{
		return val > x.val; 
	}
};
struct E{
	int to,nxt,dist;
}edge[maxe];
int first[maxv],nume,Ans,cow[maxv];
int dist[maxv];
int n,p,c,x;
void add_edge(int a,int b,int c){
	edge[nume] . to = b;
	edge[nume] . dist = c;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
Node f(int x,int y){
	Node t;
	t.id = x;
	t.val = y;
	return t;
}
bool vis[maxv];
void dijkstra(int s){
	priority_queue<Node> Heap;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[s] = 0;
	Heap.push(f(s,0));
	int u,v;
	for (int i=1;i<=p-1;i++){
		Node tmp = Heap.top();
		Heap.pop();
		while (vis[tmp . id]){
			tmp = Heap.top();
			Heap.pop();
		}
		u = tmp . id;
		vis[u] = true;
		for (int e=first[u];e!=-1;e=edge[e].nxt){
			v = edge[e] . to;
			if (!vis[v]){
				if (dist[v] > dist[u] + edge[e].dist){
					dist[v] = dist[u] + edge[e].dist;
					Heap.push(f(v,dist[v]));
				}
			}
		}
	}
}
int main(){
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	scanf("%d%d%d",&n,&p,&c);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		cow[x]++;
	}
	memset(first,-1,sizeof(first));
	nume = 0;
	for (int i=1;i<=c;i++){
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		add_edge(a,b,d);
		add_edge(b,a,d);
	}
	Ans = oo;
	for (int i=1;i<=p;i++){
		dijkstra(i);
		int rec = 0;
		for (int j=1;j<=p;j++) rec+=dist[j] * cow[j];
		Ans = min(Ans,rec);
	}
	printf("%d\n",Ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
