#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cmath>
const int oo=2000000;
int dp[30][105][105];
int n,E,D,ans; 
int min(int x,int y){if(x<y)return x;else return y;}
int main()
{
	scanf("%d%d%d",&n,&E,&D);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=E;j++)
			for (int k=0;k<=D;k++)
				dp[i][j][k]=oo;
	dp[1][E][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=E;j++)
			for (int k=0;k<=D;k++)
				dp[i][E-k][k]=min(dp[i][E-k][k],dp[i-1][j][k]);
		//领导人更换的话 
		for (int j=E;j>=0;j--)
			for (int k=0;k<=D;k++)
				for (int t=1;t<=D;t++)
				{
					int temp=j-t*t;
					if (temp<0) break;
					if ((k+t)>D) break;
					dp[i][temp][k+t]=min(dp[i][temp][k+t],dp[i][j][k]+1);
				}
		//跑步的话 
	}
	ans=oo;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=E;j++)
			if (ans>dp[i][j][D]) ans=dp[i][j][D];
	if (ans==oo) printf("0\n");else printf("%d\n",ans);
	return 0;
}
