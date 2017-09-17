/*
ID:cqz15311
PROG:money
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
long long v,n,dp[10005],x;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%lld%lld",&v,&n);
	dp[0]=1;
	for (long long i=1;i<=v;i++)
	{
		scanf("%lld",&x);
		for (long long j=1;j<=n;j++)
			if (j-x>=0)	dp[j]=dp[j]+dp[j-x];
	}
	printf("%lld\n",dp[n]);
	fclose(stdin);
	fclose(stdout);
}
