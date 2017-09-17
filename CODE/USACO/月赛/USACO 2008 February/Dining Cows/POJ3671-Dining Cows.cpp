#include <iostream> 
#include <cstring>
#include <cmath>
#include <cstdio>
int dp[3][30005];
int a[30005],n,ans;
int min(int x,int y){if (x<y) return x;else return y;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1)
		{
			dp[0][i]=dp[0][i-1];
		}
		else
		{
			dp[0][i]=dp[0][i-1]+1;
		}
	}
	dp[1][n+1]=0;
	for (int i=n;i>=1;i--)
	{
		if (a[i]==2)
		{
			dp[1][i]=dp[1][i+1];
		}
		else
		{
			dp[1][i]=dp[1][i+1]+1;
		}
	}
	ans=35555;
	for (int i=0;i<=n;i++)
	{
		//printf("%d %d\n",dp[0][i],dp[1][i+1]);
		ans=min(ans,dp[0][i]+dp[1][i+1]);
	}
	printf("%d",ans);
	return 0;
}
