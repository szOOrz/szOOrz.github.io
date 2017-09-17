#include<iostream>
#include<cmath>
using namespace std;
int dp[30050][4];
int num[30500],n,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&num[i]);
	//µÝÔö 
	dp[0][1]=0;
	dp[0][2]=0;
	dp[0][3]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i][1]=dp[i-1][1];
		dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
		dp[i][3]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]));
		for (int k=1;k<=3;k++)
		if (k!=num[i]) dp[i][k]++;
	}
	ans=dp[n][3];
	ans=min(ans,dp[n][2]);
	ans=min(ans,dp[n][1]);
	//µÝ¼õ 
	dp[0][1]=0;
	dp[0][2]=0;
	dp[0][3]=0;
	for (int i=1;i<=n;i++)
	{
		dp[i][3]=dp[i-1][3];
		dp[i][2]=min(dp[i-1][3],dp[i-1][2]);
		dp[i][1]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]));
		for (int k=1;k<=3;k++)
		if (k!=num[i]) dp[i][k]++;
	}
	ans=min(ans,dp[n][3]);
	ans=min(ans,dp[n][2]);
	ans=min(ans,dp[n][1]);
	printf("%d",ans);
	return 0;
} 
