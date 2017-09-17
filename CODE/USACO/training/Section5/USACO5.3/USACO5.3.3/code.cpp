/*
ID:cqz15311
LANG:C++
PROG:schlnet
*/
#include<bits/stdc++.h> 
using namespace std;
const int maxn = 105;
struct Edge{
	int from,to,nxt;
}edge[maxn*maxn]; 
int nume;
int first[maxn],Time,DFN[maxn],low[maxn],Stack[maxn],top;
bool Instack[maxn];
int cnt,n,Belong[maxn];
int Outedge[maxn],Inedge[maxn],Out0,In0;
void add_edge(int a,int b){
	edge[nume] . from = a;
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
void Tarjan(int u){
	DFN[u] = ++Time;
	low[u] = Time;
	Stack[++top] = u;
	Instack[u] = true;
	for (int e=first[u];e!=-1;e=edge[e].nxt){
		int v = edge[e].to;
		if (DFN[v] == -1){
			Tarjan(v);
			low[u] = min(low[u],low[v]);
		} else if (Instack[v])
			low[u] = min(low[u],low[v]);
	}
	if(DFN[u] == low[u]){
		cnt++;
		while (Stack[top]!=u){
			Belong[Stack[top]] = cnt;
			Instack[Stack[top]] = false;
			top--;
		}
		Belong[u] = cnt;
		Instack[u] = false;
		top--;
	}
}
int main(){
	freopen("schlnet.in","r",stdin);
	freopen("schlnet.out","w",stdout);
	scanf("%d",&n);
	memset(first,-1,sizeof(first));
	nume = 0;
	for (int i=1;i<=n;i++){
		int j;
		scanf("%d",&j);
		while (j!=0){
			add_edge(i,j);
			scanf("%d",&j);
		}
	}
	Time = 0;
	memset(Instack,false,sizeof(Instack));
	memset(DFN,-1,sizeof(DFN));
	cnt = 0;
	for (int i=1;i<=n;i++){
		top = 0;
		if (DFN[i] == -1) Tarjan(i);
	}
	memset(Inedge,0,sizeof(Inedge));
	memset(Outedge,0,sizeof(Outedge));
	for (int i=0;i<nume;i++){
		int u,v;
		u = Belong[edge[i].from];
		v = Belong[edge[i].to];
		if (u!=v){
			Inedge[v]++;
			Outedge[u]++;
		}
	}
	Out0 = 0;
	for (int i=1;i<=cnt;i++){
		if (Outedge[i] == 0) Out0++; 
		if (Inedge[i] == 0) In0++; 
	}
	if (cnt == 1){
		puts("1");
		puts("0");
	} else
		printf("%d\n%d\n",In0,max(Out0,In0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
