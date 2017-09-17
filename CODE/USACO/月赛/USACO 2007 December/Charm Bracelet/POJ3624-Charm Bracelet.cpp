#include<iostream> 
#include <cstring>
#include <cstdio>
int dp[14050];
int w[4005],d[4005];
int n,m;
int max(int x,int y){if (x<y) return y;else return x;}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&d[i]);
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
	{
		for (int j=m;j>=0;j--)
		{
			if (j>=w[i]) dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
		}
	} 
	printf("%d",dp[m]);
	return 0;
}
