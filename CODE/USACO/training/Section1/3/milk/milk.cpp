/*
ID:15311
PROG:milk
LANG:C++ 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
struct M{
	int p,a;
}milk[5005];
int sum,cnt,n,m;
bool cmp(M a,M b)
{
	return a.p<b.p;
}
int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&milk[i].p,&milk[i].a);
	sort(milk+1,milk+1+m,cmp);
	sum=0;
	cnt=0;
	for (int i=1;i<=m;i++)
	{
//		printf("%d %d %d %d %d\n",i,cnt,sum,milk[i].p,milk[i].a);
		if (cnt+milk[i].a>=n)
		{
			sum+=(n-cnt)*milk[i].p;
//			printf("%d",sum+(n-cnt)*milk[i].p);
			break;
		}
		cnt+=milk[i].a;
		sum+=milk[i].a*milk[i].p; 
	}
	printf("%d\n",sum);
	return 0;
}
/*Ì°ĞÄ*/
