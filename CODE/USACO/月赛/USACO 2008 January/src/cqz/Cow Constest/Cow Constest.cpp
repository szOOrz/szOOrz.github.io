#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include <cstdlib>
bool f[102][102];
int n,m,sum,ans,x,y;
int main()
{
	scanf("%d%d",&n,&m);
	memset(f,false,sizeof(f));
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		f[x][y]=true;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (f[i][k] && f[k][j]) f[i][j]=true;
	for (int i=1;i<=n;i++)
	{
		sum=0;
		for (int j=1;j<=n;j++)
			if (i!=j)
			{
				if (f[i][j]) sum=sum+1;
				if (f[j][i]) sum=sum+1;
			}
		if (sum==n-1) ans++;
	}
	printf("%d",ans);
} 
