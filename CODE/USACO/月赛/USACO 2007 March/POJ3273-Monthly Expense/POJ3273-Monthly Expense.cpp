#include<iostream> 
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
const int oo=1500000000;
int day[105000];
int n,m,left,right,ans;
bool check(int num)
{
	int sum=0;
	int f=0;
	for (int i=1;i<=n;i++)
	{
		if (sum+day[i]>num)
		{
			sum=0;
			f++;
		}
		sum+=day[i];
	}
	f++;
	if (f>m) return false;else return true;
}
int main()
{
//二分结果，最小是所有数的最大值，最大是所有数的总和，约等于1000000000。
//然后得到的值代进去验证，所以时间复杂度是log sum*n≈30*n,不会超
//如果可行，那么right改变（同时记录最小可能值），否则left改变 
	scanf("%d%d",&n,&m);
	left=-oo;
	right=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&day[i]);
		if (day[i]>left) left=day[i];
		right+=day[i];
	}
	ans=right;
	while (left<=right)
	{
		//printf("%d %d\n",left,right);
		int mid=(left+right) >> 1;
		if (check(mid))	//可行 
		{
			ans=mid;
			right=mid-1;
		}
		else
		{
			left=mid+1;
		}
	}
	printf("%d",ans);
	return 0;
}
