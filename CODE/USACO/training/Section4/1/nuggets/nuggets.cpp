/*
ID:cqz15311
LANG:C++
PROG:nuggets
*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,dist[505],f,m;
int a[15];
int q[5505];
int front,rear;
int main(){
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	scanf("%d",&n);
	m = 0x3fffff;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m = min(m,a[i]);
	}
	f = a[1];
	for (int i=2;i<=n;i++) f = __gcd(f,a[i]);
	if ((f != 1) || (m == 1)){
		printf("%d\n",0);
	} else{
		front = rear = 0;
		memset(dist,-1,sizeof(dist));
		for (int i=1;i<=n;i++){
			if ((dist[a[i] % m] == -1) || (dist[a[i] % m] != -1) && (a[i] < dist[a[i] % m])){
				dist[a[i] % m] = a[i];
				q[rear++] = a[i] % m;
			}
		}
		while (front < rear){
			int u = q[front++];
			for (int i=1;i<=n;i++){
				int v = (u + a[i]) % m;
				if ((dist[v] == -1) || (dist[v] != -1) && (dist[v] > dist[u] + a[i])){
					dist[v] = dist[u] + a[i];
					q[rear++] = v;
				}
			}
		}
		int ans = 0;
		for (int i=0;i<m;i++){
			ans = max(ans,dist[i] - m);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
