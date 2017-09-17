//设dp[j][k]表示长度为j和k能组成
//那么对于第i条线，要么
//dp[j+a[k]][k]=true;dp[j][k+a[i]]=true;
//所有小棒一定要用上，所以可以求得第三条
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
bool dp[4005][4005];
int n,sum,l[4005],ans;
bool check(int a,int b,int c)
{
	if ((a==0) || (b==0) || (c==0)) return false;
	if (a+b<=c) return false;
	if (a+c<=b) return false;
	if (c+b<=a) return false;
	return true;
}
double geta(int a,int b,int c)
{
	double p=(double)a+b+c;
	p=p/2;
	return floor(sqrt((p-a)*(p-b)*(p-c)*p)*100);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	sum=0;
	for (int i=1;i<=n;i++) sum+=l[i];
	memset(dp,false,sizeof(dp));
	dp[0][0]=true;
	for (int i=1;i<=n;i++)
	{
		for (int j=sum;j>=0;j--)
			for (int k=sum;k>=0;k--)
			if (dp[j][k]) 
			{
				dp[j+l[i]][k]=true;
				dp[j][k+l[i]]=true;
			}
	}
	ans=-1;
	for (int i=1;i<=sum;i++) 
		for (int j=1;j<=sum;j++)
		if (dp[i][j])
		{
			int a=i;
			int b=j;
			int c=sum-i-j;
			if (check(a,b,c))
			{
			//	printf("%d %d %d\n",a,b,c);
				
				double k=geta(a,b,c);
				int temp=(int)k;
				if (temp>ans) ans=temp;
			}
		}
	printf("%d",ans);
	return 0;
}
