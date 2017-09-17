#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
int dp[1005][3][1005];
int max(int x,int y){if (x<y) return y;else return x;}
int apple[1005];
int t,w,ans;
int main()
{
	scanf("%d%d",&t,&w);
	for (int i=1;i<=t;i++) scanf("%d",&apple[i]);
	//dp[i][j][k]表示第i分钟，表示在j树下，走了k步，接到的最大苹果数 
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=t;i++)
	{
		for (int j=1;j<=2;j++)
		{
			int temp;
			if (apple[i]==j) temp=1;else temp=0;
			dp[i][j][0]=dp[i-1][j][0]+temp;
			for (int k=1;k<=t;k++)
			{
				dp[i][j][k]=max(dp[i-1][j][k]+temp,dp[i-1][3-j][k-1]+(1-temp));
			} 
		}
	}
	ans=0;
	for (int i=0;i<=w;i++)
	{
		ans=max(ans,dp[t][1][i]);
		ans=max(ans,dp[t][2][i]);
	}
	printf("%d",ans);
	return 0;
}
