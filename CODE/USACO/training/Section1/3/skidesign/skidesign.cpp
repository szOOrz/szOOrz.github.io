/*
ID:cqz15311
PROG:skidesign
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<cstring>
int h[1050];
int sum,ans,n;
int main()
{
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	ans=-1;
	for (int i=0;i<=100-17;i++)
	{
		sum=0;
		for (int j=1;j<=n;j++)
		{
			if (h[j]<i) sum+=(i-h[j]) * (i-h[j]);
			if (h[j]>i+17) sum+=(h[j]-i-17) *(h[j]-i-17);
		}
		if (ans==-1) ans=sum;
		if (sum<ans) ans=sum;
		//printf("%d %d\n",i,sum);
	}
	printf("%d\n",ans);
	return 0;
} 
