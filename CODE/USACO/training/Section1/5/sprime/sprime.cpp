/*
ID:cqz15311
PROG:sprime
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<cstring>
int n,ans;
/*void get_prime()
{
	memset(f,true,sizeof(f));
	change(1);
	for (int i=2;i<=99999999)
	{
		
	}
}*/
bool prime(int x)
{
	if (x==1) return false;
	int r=(int)sqrt(x);
	for (int i=2;i<=r;i++)
	{
		if (x % i==0) return false;
	}
	return true;
}
void dfs(int x)
{
	if (x==n+1)
	{
		printf("%d\n",ans);
		return ;
	}
	for (int i=1;i<=9;i++)
	{
		if (prime(ans*10+i))
		{
			ans=ans*10+i;
			dfs(x+1);
			ans=ans / 10;
		}
	}
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	scanf("%d",&n);
//	get_prime();
	ans=0;
	dfs(1);
}
