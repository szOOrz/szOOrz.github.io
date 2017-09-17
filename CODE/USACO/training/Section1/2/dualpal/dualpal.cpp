/*
ID:cqz15311
PROG:dualpal
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
int b[100],n,s;
bool could(int x,int B)
{
	memset(b,0,sizeof(b));
	int n=0;
	while (x)
	{
		n++;
		b[n]=x % B;
		x=x/B;
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]!=b[n-i+1]) return false;
	}
	return true;
}
bool check(int x)
{
	int val=0;
	for (int B=2;B<=10;B++)
	{
		if (could(x,B))
		{
			val++;
			if (val>=2) return true;
		}
	}
	return false;
}
int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	scanf("%d%d",&n,&s);
	bool find=false;
	while (!find)
	{
		s++;
		if (check(s))
		{
			printf("%d\n",s);
			n--;
			if (n==0) find=true;
		}
	}
	return 0;
}
