/*
ID:cqz15311
PROG:barn1
LANG:C++ 
*/ 
#include<cstdio>
#include<algorithm>
using std::sort;
int m,s,c,n[205],l[205],ans;
bool cmp_big(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);
	scanf("%d%d%d",&m,&s,&c);
	for (int i=1;i<=c;i++)
	{
		scanf("%d",&n[i]);
	}
	sort(n+1,n+1+c);
	for (int i=1;i<c;i++)
	{
		l[i]=n[i+1]-n[i]-1;
	}
	sort(l+1,l+c,cmp_big);
	ans=(n[c]-n[1]+1);
//	printf("%d\n",ans);
	for (int i=1;i<m;i++)
	{
		ans-=l[i];
//		printf("%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}
