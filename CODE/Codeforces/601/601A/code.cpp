#include<bits/stdc++.h>
const int maxn = 411;
using namespace std;
int a1[maxn][maxn],a2[maxn][maxn];
int n,m;
bool vis[maxn];
int dist[maxn];
int dij(int a[maxn][maxn]){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[1] = 0;
	for(int j=1;j<=n;j++){
		int k = -1,Min = 0x3fffffff;
		for (int i=1;i<=n;i++){
			if (!vis[i] && dist[i] < Min){
				Min = dist[i];
				k = i;
			}
		}
		if (k == -1) break;
		vis[k] = true;
		for (int i=1;i<=n;i++){
			if (!vis[i])
				dist[i] = min(dist[i],dist[k] + a[k][i]); 
		}
	}
	return dist[n];
}
int main(){
	scanf("%d%d",&n,&m);
	memset(a1,0x3f,sizeof(a1));
	memset(a2,0x3f,sizeof(a2));
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a1[a][b] = a1[b][a] = 1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i == j) continue;
			if (a1[i][j] != 1)
				a2[i][j] = 1;
		}
	}
	int ans1 = dij(a1);
	int ans2 = dij(a2);
	if ((ans1 > n) || (ans2 > n)) puts("-1"); else
	printf("%d\n",max(ans1,ans2));
}
