#include<bits/stdc++.h> 
typedef long long LL;
const int maxn = 205000;
using namespace std;
int num[maxn];
struct E{
	int from,to,nxt;
}edge[maxn*2];
LL Ans,x,y;
int first[maxn],nume,n,a,b;
void add_edge(int a,int b){
	edge[nume] . from = a;
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
}
void dfs(int u){
	int v;
	num[u] = 0;
	for (int e=first[u];e!=-1;e=edge[e].nxt){
		v = edge[e].to;
		if (num[v] == 0){
			num[u]++;
			dfs(v);
		}
	}
}
int main(){
	scanf("%d%I64d%I64d",&n,&x,&y);
	memset(first,-1,sizeof(first));
	nume = 0;
	for (int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add_edge(a,b);
		add_edge(b,a);
	}
	if (x > y){
		Ans = (n-1) * y;
	}  else{
		memset(num,0,sizeof(num));
		dfs(1); 
		Ans = 0;
		for (int i=1;i<=n;i++)
			if (num[i] == 0) Ans++;
		if (num[1] == 1) Ans++;
		Ans--;
		Ans = (Ans-1) * y + x * (n - Ans);
	}
	printf("%I64d\n",Ans);
}
