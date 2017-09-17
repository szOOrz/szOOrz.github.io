/*
ID:cqz15311
PROG:pprime
LANG:C++
*/
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
int prime[50005];
bool flag;
int ans[50000];
int a,b,k;
void get_prime()
{
	bool flag[50005];
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	prime[0]=0;
	for (int i=2;i<=50000;i++)
	{
		if (flag[i])
		{
			prime[++prime[0]] = i;
			for (int j=i+i;j<=50000;j+=i)
			{
				flag[j]=false;
			}
		}
	}
}
bool check(int x)
{
	bool flag=true;
	for (int i=1;i<=prime[0];i++)
	{
		if (x == prime[i]) return true;
		if (x % prime[i] == 0) {flag=false;break;}
	}
	return flag;
}
int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	get_prime();
	ans[0]=0;
	scanf("%d%d",&a,&b);
	for (int i=1;i<=9999;i++)
	{
		if (i<  10) k= i * 10 + i;else
		if (i< 100) k= i * 100 + (i % 10) * 10 + (i / 10 % 10); else
		if (i<1000) k= i * 1000 + (i % 10) * 100 + (i / 10 % 10) * 10 + (i / 100 % 10);else
		k=i * 10000 + (i % 10) * 1000 + (i / 10 % 10) * 100 +(i / 100 % 10) * 10 + (i / 1000 % 10);
//		printf("%d\n",k);
		if ((k>=a) && (k<=b) && (check(k))) ans[++ans[0]]=k;
		if (i<10) k=i; else 
		if (i<100) k=i * 10 + i / 10; else 
		if (i<1000) k=i * 100 + i / 10 % 10 * 10 + i / 100 % 10 * 1; else 
		k= i * 1000+i / 10 % 10 * 100 + i / 100 % 10 * 10 + i /1000 % 10 * 1;
		if ((k>=a) && (k<=b) && (check(k))) ans[++ans[0]]=k;
//		printf("%d\n",k);
	}
	std::sort(ans+1,ans+1+ans[0]);
	for (int i=1;i<=ans[0];i++) printf("%d\n",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
