/*
ID:cqz15311
PROG:numtri
LANG:C++
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::max;
int n,f[1005][1005],dp[1005][1005];
int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++) scanf("%d",&f[i][j]);
	}
	for (int i=1;i<=n;i++)
	{
		dp[n][i]=f[n][i];
	}
	for (int i=n-1;i>=1;i--)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+f[i][j];
		//	printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[1][1]);
	return 0;
}
