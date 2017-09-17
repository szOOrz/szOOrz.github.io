#include<bits/stdc++.h>
const int maxn = 2e3+100;
typedef long double LD;
int n,m,R,C;
LD dp[maxn][maxn];
LD dfs(int i,int j){
	if (i < 0 || j < 0)   return 0;
	if (i == 0 && j == 0) return 0;
	if (dp[i][j] > 0) return dp[i][j];
	int No,Two,Row,Col,All;
	No = (n-i) * (n-j);
	Two = i*j;
	Row = i * (n-j);
	Col = j * (n-i);
	dp[i][j] = n * n;
	dp[i][j] += dfs(i-1,j) * 1.0 * Row;
	dp[i][j] += dfs(i,j-1) * 1.0 * Col;
	dp[i][j] += dfs(i-1,j-1) * 1.0 * Two;
	dp[i][j] = dp[i][j] / (1.0 * n*n - 1.0 * No);
	return dp[i][j];
}
int main(){
	scanf("%d%d",&n,&m);
	R = n;
	C = n;
	int row[maxn],col[maxn];
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	while (m--){
		int a,b;
		scanf("%d%d",&a,&b);
		if (!row[a]) R--;
		if (!col[b]) C--;
		row[a]++;col[b]++;
	}
	memset(dp,255,sizeof(dp));
	printf("%.20lf\n",(double)dfs(R,C));
}
