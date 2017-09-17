/*
ID:cqz15311
PROG:frac1
LANG:C++
*/
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using std::sort;
struct fs
{
	int fz,fm;
}ans[165*165];
int n,num;
bool cmp(fs a,fs b)
{
	return ((double)a.fz / (double) a.fm)<((double)b.fz / (double) b.fm);
}
int gcd(int x,int y)
{
	if (!y) return x; else return gcd(y,x % y);
}
int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	num=0;
	for (int b=1;b<=n;b++)
	{
		for (int a=1;a<=b;a++)
		{
			if (gcd(a,b)==1) 
			{
				ans[++num].fz=a;
				ans[num].fm=b;
			}
		}
	}
	puts("0/1");
	//for (int i=1;i<=num;i++) printf("%d/%d\n",ans[i].fz,ans[i].fm);
	//puts("");
	sort(ans+1,ans+1+num,cmp);
	for (int i=1;i<=num;i++) printf("%d/%d\n",ans[i].fz,ans[i].fm);
	return 0;
}
