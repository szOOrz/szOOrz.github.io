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
//dp���鱣�浽iλ�õ�����ȡ� num[i]���泤��Ϊdp[i]�������У���iΪֹ�������ж��ٸ� Ϊ�˷�ֹ�ظ����ڳ����м�һ�����У���dp��ʱ�򣬵���ö�٣���i-1��1ö�٣������ɨ�赽һ����h��i��h��ȣ������ҵ�ǰ�������֮ǰ��һ�λ���1��Ҳ���ǻ��ǰ���Ǹ��ظ�����ʱ��ȥ�������Ǹ���Ҳ������i��num���鸳ֵΪ0�����Ҳ��ܵ�ǰ�Ƿ�ֻ��1����ѭ��������������Ļ�������ǰ���и��ŵģ���Ȼ�ظ��� 
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
