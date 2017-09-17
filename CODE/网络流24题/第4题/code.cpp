#include<bits/stdc++.h>
const int maxAns = 5000;
const int maxv = maxAns*2+5;
const int maxe = 3200000;
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
//				printf("%d:%d --> %d:%d\n",nume,a,b,c);
//				printf("Add:Edge[0] . from = %d",edge[0].from);
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

			void init_sap(){
				Reset();
				Max_flow = 0;
				memset(num,0,sizeof(num));
				memset(path,0,sizeof(path));
				num[0] = n;
				memset(dist,0,sizeof(dist));
				for (int i=0;i<n;i++) cur[i] = first[i];
			}

			int sap(int s,int t){
				memset(dist,0,sizeof(dist));
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
							if (u != s) u = edge[path[u]] . from;
						}
					}
				}
				return Max_flow;
			}
		;
}G;

int n,m;
bool vis[maxv];
int main(){
	int s = 0,t = maxAns *2 + 1;
	G.init(maxAns*2+2);
	scanf("%d",&n);
	G.Reset(); 
	int i;
	for (i=1;i<=maxAns;i++){
		G.add_edge(s,i,1);
		G.add_edge(maxAns + i,t,1);
		for (int j=1;j<i;j++){
			int t = (int)sqrt(1.0*(i+j));
			if (t * t == (i+j)){
				G.add_edge(j,i + maxAns,1);
			}
		}
		int rec = i - G.sap(s,t);
		if (rec > n){
			break;
		}
	}
	//Ans = i 
	int Ans = i-1;

	for (int j=0;j<G.nume;j++){
		if ((G.edge[j].to == i) || (G.edge[j].to == i+maxAns) ||
		   (G.edge[j].from == i) || (G.edge[j].from == i+maxAns)){
		   		G.edge[j].cap  = 0;
		   		G.edge[j].flow = 0;
		   }
	}
	
	G.Reset(); 
	G.sap(s,t);
	/*
	for (int j=0;j<G.nume;j++){
		if ((G.edge[j].to == i) || (G.edge[j].to == i+maxAns) ||
		   (G.edge[j].from == i) || (G.edge[j].from == i+maxAns)){
		   		
		   		G.edge[j].cap  = -1;
				G.edge[j].flow = -1;
				printf("Delete%d-->%d\n",G.edge[j].from,G.edge[j].to);
		   }
	}*/
	memset(vis,false,sizeof(vis));
	vis[i] = true;
	printf("%d\n",Ans);
	for (int i=1;i<=Ans;i++){
		if (vis[i]) continue;
		int u = i; 
//		printf("find(%d) = %d\n",i,u);
		while (true){
//			printf("%d,%d \n",vis[u],u);
			printf("%d ",u);
			vis[u] = true;
			bool found = false;
			for (int e=G.first[u];e!=-1;e=G.edge[e].nxt){
//				printf("%d--(%d,%d)->%d\n",u,G.edge[e].cap,G.edge[e].flow,G.edge[e].to);
				if (((e & 1) == 0) && (G.edge[e].cap == G.edge[e].flow) && (!vis[G.edge[e].to - maxAns])){
					u = G.edge[e].to - maxAns;
					found = true;
					break;
				}
			}
			if (!found) break;
		}
//		printf("\n%d**",i);
		puts("");
	}
}

