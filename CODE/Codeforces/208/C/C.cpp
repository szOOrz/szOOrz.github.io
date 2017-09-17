#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const LL maxn = 105;
const LL maxm = 105*105;
struct Edge{
	LL to,nxt;
}edge[maxm*2];
LL nume,first[maxn];
void add_edge(LL a,LL b){
	edge[nume] .to = b;
	edge[nume] .nxt = first[a];
	first[a] = nume++;
}
LL dist[maxn],q[maxn],dp[maxn],num[maxn],n,m;
LL front,rear;
LL All,t;
void bfs(){
	memset(dist,-1,sizeof(dist));
	dist[1] = 0;
	front = rear = 0;
	q[rear++] = 1;
	while (front < rear){
		LL u = q[front++];
		for (LL e=first[u];~e;e=edge[e].nxt){
			LL v = edge[e].to;
			if (dist[v]==-1){
				dist[v] = dist[u] + 1;
				q[rear++] = v;
			}
		}
	}
}
LL DP(){
	memset(dp,-1,sizeof(dp));
	dp[1] = 1;
	front = rear = 0;
	q[rear++] = 1;
	while (front < rear){
		LL u = q[front++];
		for (LL e=first[u];~e;e=edge[e].nxt){
			if (dist[u] == dist[edge[e].to]-1){
				if (dp[edge[e].to] == -1){
					q[rear++] = edge[e].to;
					dp[edge[e].to] = 0;
				}
				dp[edge[e].to] += dp[u];
			}
		}
	}
	return dp[n]==-1?0:dp[n];
}

LL get(LL x){
	memset(num,-1,sizeof(num));
	num[x] = dp[x];
	front = rear = 0;
	q[rear++] = x;
	while (front < rear){
		LL u = q[front++];
		for (LL e=first[u];~e;e=edge[e].nxt){
			if (dist[u] == dist[edge[e].to]-1){
				if (num[edge[e].to] == -1){
					q[rear++] = edge[e].to;
					num[edge[e].to] = 0;
				}
				num[edge[e].to] += num[u];
			}
		}
	}
	return num[n]==-1?0:num[n];
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	memset(first,-1,sizeof(first));
	nume = 0;
	for (LL i=1;i<=m;i++) {
		LL x,y;
		scanf("%I64d%I64d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	bfs();
	All = DP();
	double Ans = 1.0;
	for (LL i=2;i<=n-1;i++){
		t = get(i);
		Ans = max(Ans,t*2.0 / All);
	}
	printf("%.20lf\n",Ans);
}
