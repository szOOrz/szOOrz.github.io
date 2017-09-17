#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
int main()
{
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	memset(dp,false,sizeof(dp));
	dp[0]=true;
	return 0;
}
