/*
ID:cqz15311
PROG:fence
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxe = 1050 * 2;
const int maxv = 505;
int Map[maxv][maxv];
int Path[maxe],cnt;
int num[maxv];
int Min,Max;
void Dfs(int u){
	if (num[u]){
		do{
			int v;
			for (v = Min;v<=Max;v++){
				if (Map[u][v]) break;
			}
			Map[u][v]--;
			Map[v][u]--;
			num[u]--;
			num[v]--;
			Dfs(v);
		} while (num[u]);
		Path[++cnt] = u;
	}
	 else{
		Path[++cnt] = u;
	}
	
	
}
void solve(){
	for (int i=Min;i<=Max;i++){
		if ((num[i] % 2 == 1) && (num[i] != 0)){
			Dfs(i);
			return ;
		}
	}
	Dfs(Min);
}

int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int F,a,b,In[maxv];
	scanf("%d",&F);
	Min = 500;Max = 1;
	while (F--){
		scanf("%d%d",&a,&b);
		Map[a][b]++;
		Map[b][a]++;
		num[a]++;
		num[b]++;
		Min = min(Min,min(a,b));
		Max = max(Max,max(a,b));
	}
	solve();	
	for (int i=cnt;i>=1;i--){
		printf("%d\n",Path[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
