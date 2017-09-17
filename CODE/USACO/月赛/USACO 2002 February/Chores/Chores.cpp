#include <iostream> 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
int t[10500],need[10500][105],p[10500],dp[10500],n,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		scanf("%d",&p[i]);
		for (int j=1;j<=p[i];j++) scanf("%d",&need[i][j]);
	}
	ans=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=0;
		for (int j=1;j<=p[i];j++) if (dp[need[i][j]]>dp[i]) dp[i]=dp[need[i][j]];
		dp[i]+=t[i];
		if (dp[i]>ans) ans=dp[i];
	}
	printf("%d",ans);
	return 0;
}
