#include<cstring>
#include<cstdio>
#include<cmath>
int dp[200005];
int s[105],f[105],ans,n;
int MX,MN,IX;
int min(int x,int y){if (x<y) return x; else return y;}
int max(int x,int y){if (x>y) return x; else return y;}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&s[i],&f[i]);
	//用DP[i,j]来表示前i个，左边和为j时，右边最大的值，都大于等于0
	for (int i=0;i<=200000;i++)
	{
		dp[i]=-100000;
	}
	dp[100000]=0;
	MX=100000;
	MN=100000;
	IX=100000;
	for (int i=1;i<=n;i++) 
	{
		MX=max(MX,MX+s[i]);
		IX=min(IX,IX+s[i]);
		//printf("%d %d\n",IX,MX);
		if (s[i]>0)
		{
			for (int j=MX;j>=IX;j--)
			{
				if (dp[j-s[i]]>-100000) 
					dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
			}
		}
		else
		{
			for (int j=IX;j<=MX;j++)
			{
				if (dp[j-s[i]]>-100000) 
					dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
			}
		}
	//	for (int j=IX;j<=MX;j++)
	//	{ 
	//		dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i]]+f[i]);
	//		printf("[%d,%d]<---[%d,%d]::::%d\n",i,j,j-s[i],f[i],dp[j]);
	//	}
	}
	ans=0;
	for (int j=100000;j<=MX;j++) 
		if (dp[j]>=0) ans=max(ans,dp[j]+j-100000);
	printf("%d",ans);
	return 0;
}
