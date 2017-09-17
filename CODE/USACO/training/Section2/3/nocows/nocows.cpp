/*
ID:cqz15311
PROG:nocows
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define Mod 9901
int dp[202][101];
int n,k;
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout); 
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=100;i++) dp[1][i]=1;
	for (int i=1;i<=200;i++)
	{
		for (int j=1;j<=100;j++)
		{
			for (int k=1;k<=i-2;k++)
			{
				dp[i][j]=(dp[i][j]+dp[k][j-1]*dp[i-1-k][j-1]) % Mod;
			}
		}
	}
	scanf("%d%d",&n,&k);
	printf("%d\n",(dp[n][k]+Mod-dp[n][k-1]) % Mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
