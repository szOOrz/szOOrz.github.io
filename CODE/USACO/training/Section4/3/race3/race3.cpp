/*
ID:cqz15311
LANG:C++
PROG:race3
*/
#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 55;

int n;
int Ans[maxn],ans[maxn];
bool vis[maxn];
int Map[maxn][maxn],MM[maxn][maxn];

bool dfs(int u){
	if (u == (n-1)) return true;
	vis[u] = true;
	for (int v=0;v<n;v++){
		if (Map[u][v] && !vis[v]){
			if (dfs(v)) return true;
		}
	}
	return false;
}

int main(){
	freopen("race3.in","r",stdin);
	freopen("race3.out","w",stdout);
	n = 0;
	int c;
	scanf("%d",&c);
	memset(Map,false,sizeof(Map));
	while (c != -1){
		while (c != -2){
			Map[n][c] = true;
			scanf("%d",&c);
		}
		n++;
		scanf("%d",&c);
	}
	/*对于第一个询问，只需要暴力将某个点去掉，然后看
	能否从起点到终点(DFS一下即可)*/ 
	ans[0] = 0;
	for (int i=1;i<n-1;i++){
		memset(vis,false,sizeof(vis));
		vis[i] = true;
		if (!dfs(0)){
			ans[++ans[0]] = i;
		}
	}
	printf("%d",ans[0]);
	for (int i=1;i<=ans[0];i++){
		printf(" %d",ans[i]);
	}
	puts("");
	//第二个
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			MM[i][j] = Map[i][j]; 
		}
	}
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (MM[i][k] && MM[k][j]) MM[i][j] = true;
	
	
	for (int k=1;k<n-1;k++){
		memset(vis,false,sizeof(vis));
		vis[k] = true;
		if (!dfs(0)){
			bool flag = true;
			for (int i=0;i<n;i++){
//				printf("(%d,%d):%d\n",k,i,Map[k][i]);
				if ((k!=i) && (vis[i]) && (MM[k][i])){
					flag = false;
					break;
				}
			}
			if (flag) Ans[++Ans[0]] = k;
		}
	}
	printf("%d",Ans[0]);
	for (int i=1;i<=Ans[0];i++) printf(" %d",Ans[i]);
	puts("");//USACO特殊最后回车……
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4204 KB]
   Test 2: TEST OK [0.000 secs, 4204 KB]
   Test 3: TEST OK [0.000 secs, 4204 KB]
   Test 4: TEST OK [0.000 secs, 4204 KB]
   Test 5: TEST OK [0.000 secs, 4204 KB]
   Test 6: TEST OK [0.000 secs, 4204 KB]
   Test 7: TEST OK [0.000 secs, 4204 KB]
   Test 8: TEST OK [0.000 secs, 4204 KB]
   Test 9: TEST OK [0.000 secs, 4204 KB]
   Test 10: TEST OK [0.000 secs, 4204 KB]
   Test 11: TEST OK [0.000 secs, 4204 KB]

All tests OK.
Your program ('race3') produced all correct answers!  This is your
submission #3 for this problem.  Congratulations!
*/
