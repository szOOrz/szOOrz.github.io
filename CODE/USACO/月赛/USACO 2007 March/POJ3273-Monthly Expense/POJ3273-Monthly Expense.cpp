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
//���ֽ������С�������������ֵ����������������ܺͣ�Լ����1000000000��
//Ȼ��õ���ֵ����ȥ��֤������ʱ�临�Ӷ���log sum*n��30*n,���ᳬ
//������У���ôright�ı䣨ͬʱ��¼��С����ֵ��������left�ı� 
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
		if (check(mid))	//���� 
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
