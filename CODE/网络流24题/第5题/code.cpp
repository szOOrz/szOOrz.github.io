#include<bits/stdc++.h>
const int maxv = 505;
const int maxe = maxv*maxv;
const int oo = 1<<30;
using namespace std;
struct Edge{
	int from,to,nxt,flow,cap;
};
class Graph{
	public:
			int first[maxv],n,Max_flow,nume;
			int num[maxv],dist[maxv],cur[maxv];
			int path[maxv];
			Edge edge[maxe * 2];
			
			void init(int n){
				this -> n = n;
				nume = 0;
				memset(first,-1,sizeof(first));
			}
			
			void add_edge(int a,int b,int c){
//				printf("%d --> %d:%d\n",a,b,c);
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
				num[0] = n;
				memset(dist,0,sizeof(dist));
				for (int i=0;i<n;i++) cur[i] = first[i];
				int u = s;
				while (dist[s] != n+1){
//					printf("U = %d -->",u);
					if (u == t){
//						puts("Add");
						int Min_flow = oo;
						int break_point = -1;
						for (int v = u;v!=s;v=edge[path[v]].from){
//							printf("%d %d %d\n",v,path[v],edge[path[v]].from);
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
							if (u != s) u = edge[path[u]] . from;
						}
					}
				}
				return Max_flow;
			}
		;
}G;
int m,n,sum; 
int main(){
	scanf("%d%d",&m,&n);
	G.init(m+n+2);
	int s = 0,t = n+m+1;
	for (int i=1;i<=m;i++){
		int W;
		scanf("%d",&W);
		sum = sum + W;
		G.add_edge(s,i,W);
	}
	
	for (int i=1;i<=n;i++){
		int W;
		scanf("%d",&W);
		G.add_edge(m+i,t,W);
	}
	
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			G.add_edge(i,m+j,1);
		}
	}
	int Ans = G.sap(s,t);
	if (Ans == sum){
		puts("1");
		for (int i =1;i<=m;i++){
			for (int e=G.first[i];e!=-1;e=G.edge[e].nxt){
				if (((e & 1) == 0) && (G.edge[e].cap == G.edge[e].flow)){
					printf("%d ",G.edge[e].to - m);
				}
			}
			puts("");
		}
	} else
		puts("0");
	
}
