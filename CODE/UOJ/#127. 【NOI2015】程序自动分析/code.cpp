#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
const int maxn = 100005;
map<int,int> Map;
int n,father[maxn*2];
int getfather(int u){
	if (u == father[u]) return u;
	father[u] = getfather(father[u]);
	return father[u];
}
int a[maxn],b[maxn],e[maxn];
void solve(){
	Map.clear();
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++) father[i] = i;
	int m = 0,u,v;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&e[i]);
		if (e[i] == 1){
			u = Map[a[i]];
			if (u == 0) u = Map[a[i]] = ++m;
			v = Map[b[i]];
			if (v == 0) v = Map[b[i]] = ++m;
			if (getfather(u) != getfather(v)){
				father[getfather(u)] = getfather(v);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (e[i] == 0){
			u = Map[a[i]];
			v = Map[b[i]];
			if (a[i] == b[i]){
				puts("NO");
				return ;
			}
			if (u == 0 || v == 0) continue;
			if (getfather(u) == getfather(v)){
				puts("NO");
				 return ;
			}
		}
	} 
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		solve();
	}
}
