/*
ID:cqz15311
LANG:C++
PROG:bigbrn
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1002;
int n,T,a,b,Ans;
int f[maxn][maxn],g[maxn][maxn];
int main(){
	freopen("bigbrn.in","r",stdin);
	freopen("bigbrn.out","w",stdout);
	scanf("%d%d",&n,&T);
	memset(f,0,sizeof(f));
	while (T--){
		scanf("%d%d",&a,&b);
		f[a][b] = 1;
	}
	memset(g,0,sizeof(g));
	Ans = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (f[i][j]) continue;
			g[i][j] = min(min(g[i-1][j],g[i][j-1]),g[i-1][j-1])+1;
			Ans = max(Ans,g[i][j]);
		}
	}
	printf("%d\n",Ans);
}
