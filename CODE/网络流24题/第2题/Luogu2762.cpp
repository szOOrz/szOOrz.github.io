#include<bits/stdc++.h> 
using namespace std;
const int maxv = 150;
const int maxe = 30000;
struct Edge{
	int from,to,nxt,cap,flow;
}; 

int Mark[maxv],Sum;
bool choice[maxv],C[maxv];
const int oo = 1<<25;
class Graph{
	public:
			int first[maxv],n,Max_flow,nume;
			int num[maxv],dist[maxv],cur[maxv];
			int path[maxv];
			Edge edge[maxe];
			
			void init(int n){
				this -> n = n;
				nume = 0;
				memset(first,-1,sizeof(first));
			}
			
			void add_edge(int a,int b,int c){
				edge[nume] . from  = a;
				edge[nume] .   to  = b;
				edge[nume] .  nxt  = first[a];
				edge[nume] .  cap  = c;
				edge[nume] . flow  = 0;
				first[a] = nume++;
				edge[nume] . from  = b;
				edge[nume] .   to  = a;
				edge[nume] .  nxt  = first[b];
				edge[nume] .  cap  = 0;
				edge[nume] . flow  = 0;
				first[b] = nume++;
			}
			
			void Reset(){
				for (int i=0;i<nume;i++){
					edge[i].flow = 0;
				}
			}
			
			int sap(int s,int t){
				Reset();
				Max_flow = 0;
				memset(num,0,sizeof(num));
				memset(dist,0,sizeof(dist));
				for (int i=1;i<=n;i++) cur[i] = first[i];
				int u = s;
				while (dist[s] != n+1){
					if (u == t){
						int Min_flow = oo;
						int break_point = -1;
						for (int v = u;v!=s;v=edge[path[v]].from){
							if (Min_flow >= edge[path[v]].cap - edge[path[v]].flow){
								Min_flow = edge[path[v]].cap - edge[path[v]].flow;
								break_point = edge[path[v]].from;
							}
						}
						Max_flow += Min_flow;
						for (int v = u;v!=s;v=edge[path[v]].from){
							edge[path[v]] . flow += Min_flow;
							edge[path[v] ^ 1] . flow -= Min_flow;
						}
						
												
						u = break_point;
					} else{
						bool found = false;
						for (int e = cur[u];e!=-1;e=edge[e].nxt){
							if ((dist[u] == dist[edge[e].to] + 1) && (edge[e].cap > edge[e].flow)){
								cur[u] = e;
								path[edge[e].to] = e;
								u = edge[e].to;
								found = true;
								break;
							}
						}
						if (!found){
							int tmp = n + 1;
							for (int e=first[u];e!=-1;e=edge[e].nxt)
								if (edge[e].cap > edge[e].flow){
									tmp = min(tmp,dist[edge[e].to]+1);
								}
							if (--num[dist[u]] == 0) return Max_flow;
							dist[u] = tmp;
							num[tmp]++;
							cur[u] = first[u];
							u = edge[path[u]] . from;
						}
					}
				}
				return Max_flow;
			}
		;
}G;
char c = '.';
int read(int x){
	while ((!((c>='0') && (c<='9'))) && ((c!='\n') || (x == 1))) c=getchar();
	if (c == '\n') return -1;
	int a = 0;
	while ((c>='0') && (c<='9')){
		a = a * 10 + c - 48;
		c=getchar();
	}
	return a;
}
int m,n;
int Son[maxv][maxv];
int main(){
	m = read(1);n = read(1);
	Sum = 0;
	G.init(1+m+n+1);
	for (int u=1;u<=m;u++){
		Son[u][0] = 0;
		int value = read(1);
		Sum = Sum + value;
		G.add_edge(1,1+u,value);
		for (Son[u][++Son[u][0]] = read(0);Son[u][Son[u][0]]!=-1;Son[u][++Son[u][0]]=read(0)){
			G.add_edge(1+u,1+m+Son[u][Son[u][0]],oo);
		}
	}
	for (int i=1;i<=n;i++){
		int dis = read(1);
		G.add_edge(1+m+i,1+n+m+1,dis);
	}
	int Max_flow = G.sap(1,1+n+m+1);
	for (int e=G.first[1];e!=-1;e=G.edge[e].nxt)
		if ((e & 1) == 0){//如果是正向边 
		//尝试去掉这条边
		int tmp1 = G.edge[e].cap;
		G.edge[e].cap = 0;
		int tmp2 =  G.sap(1,1+n+m+1);
		G.edge[e].cap = tmp1;
		if (G.edge[e].cap - G.edge[e].flow != tmp2) choice[G.edge[e].to-1] = true;
	}
	memset(C,0,sizeof(C));
	for (int i=1;i<=m;i++){
		if (choice[i]){
			printf("%d ",i);
			for (int j=1;j<=Son[i][0];j++){
				C[Son[i][j]] = true;
			}
		}
	}
	puts("");
	for (int i=1;i<=n;i++){
		if (C[i]) printf("%d ",i);
	}
	puts("");
	printf("%d\n",Sum-Max_flow);
}

/*
2 3
10 1 2
25 2 3
5 6 7
*/
