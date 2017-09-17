
/*
ID:cqz15311
PROG:ariprog
LANG:C++ 
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
int n,m,ma,mb;
bool find;
bool flag[125500];
bool check(int a,int b)
{
	int k=a;
	for (int i=1;i<=n;i++)
	{
		if (!flag[k]) return false;
		k=k+b;
	}
	return true;
}
int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(flag,0,sizeof(flag));
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=m;j++)
		{
			flag[i*i+j*j]=true;
		}
	}
	find=false;
	mb=(2*m*m) / (n-1);
	for (int b=1;b<=mb;b++)
	{
//		if (((b-1)*n+0)> 125000) break;
		ma=m*m*2-b*(n-1);
		for (int a=0;a<=ma;a++)
		{
//			if ((a+(b-1)*n) > 125000) break;
			if (check(a,b))
			{
				find=true;
				printf("%d %d\n",a,b);
			}
		}
	}
	if (!find) puts("NONE");
	return 0;
}
