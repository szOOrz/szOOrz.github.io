#include<iostream>
#include<cstdio>
int n,t,r[5005],k,temp1,temp2;
int main()
{
//	freopen("icow.in","r",stdin);
//	freopen("icow.out","w",stdout);
	scanf("%d%d",&n,&t);
	if (n==1)
	{
		while (t--)
		{
			puts("1");
		}
		return 0; 
	}
	for (int i=1;i<=n;i++) scanf("%d",&r[i]);
	while (t--)
	{
		k=1;
		int max=-1;
		for (int i=1;i<=n;i++)
		{
			if (r[i]>max)
			{
				k=i;
				max=r[i];
			}
		}
	//	for (int i=1;i<=n;i++) printf("%d ",r[i]); printf("\n");
		printf("%d\n",k);
		temp1=r[k] / (n-1);
		temp2=r[k] % (n-1);
		int tt=0;
		r[k]=0;
		for (int i=1;i<=n;i++)
		{
			if (i==k) continue;
			r[i]+=temp1;
			if (tt!=temp2)
			{
				r[i]++;
				tt++;
			}
		}
	}
	return 0;
} 
