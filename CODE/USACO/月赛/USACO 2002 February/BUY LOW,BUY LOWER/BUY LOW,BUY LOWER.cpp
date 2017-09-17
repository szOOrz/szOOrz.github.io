//POJ1952 
#include <iostream> 
const int oo=2000000000;
int n,h[5050];
int dp[5050],num[5050];
int t,sum;
int main()
{
	scanf("%d",&n);
	h[0]=oo;
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	dp[1]=1;
	num[1]=1;
	for (int i=2;i<=n;i++)
	{
		num[i]=1;
		dp[i]=1;
		for (int j=i-1;j>=1;j--)
		{
			if (h[j]>h[i])
			{
				if (dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
					num[i]=num[j];	
				}
				else
				if (dp[i]==dp[j]+1)
				{
					num[i]+=num[j];
				}
			}
			else
			if (h[i]==h[j])
			{
				if (dp[i]==1)
				{
					num[i]=0;
				}
				break;
//dp数组保存到i位置的最长长度。 num[i]保存长度为dp[i]的子序列，到i为止，这种有多少个 为了防止重复，在程序中加一个特判，即dp的时候，倒着枚举（从i-1到1枚举），如果扫描到一个，h和i的h相等，并且我当前的这个和之前这一段还是1，也就是会和前面那个重复，这时候去掉后面那个，也就是让i的num数组赋值为0，并且不管当前是否只有1跳出循环。（如果不跳的话，哪怕前面有更优的，必然重复） 
			}
		}
	}
	t=0;
	for (int i=1;i<=n;i++)
		if (dp[i]>t) t=dp[i];
	printf("%d ",t);
	sum=0;
	for (int i=1;i<=n;i++)
		if (dp[i]==t) sum+=num[i];
	printf("%d\n",sum);
	//for (int i=0;i<=n;i++)
	//printf("%d  %d %d %d\n",h[i],i,dp[i],num[i]);
	return 0;
}
