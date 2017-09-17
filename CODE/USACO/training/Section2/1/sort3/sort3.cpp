/*
ID:cqz15311
PROG:sort3
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
int f[4][4],n,h[1005],num[4],t,ans;
int min(int a,int b){if (a<b) return a; else return b;}
int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		num[h[i]]++;
	}
	for (int i=1;i<=num[1];i++)
	{
		f[1][h[i]]++;
	}
	for (int i=num[1]+1;i<=num[1]+num[2];i++)
	{
		f[2][h[i]]++;
	}
	for (int i=num[1]+num[2]+1;i<=num[1]+num[2]+num[3];i++)
	{
		f[3][h[i]]++;
	}
	t=min(f[1][2],f[2][1]);
	ans+=t;
	f[1][2]-=t;f[2][1]-=t;
	t=min(f[1][3],f[3][1]);
	ans+=t;
	f[1][3]-=t;f[3][1]-=t;
	t=min(f[2][3],f[3][2]);
	ans+=t;
	f[2][3]-=t;f[3][2]-=t;
//	printf("%d\n",ans);
	ans+=(f[1][2]+f[2][3]+f[3][1]+f[1][3]+f[3][2]+f[2][1])/3*2;
	printf("%d\n",ans);
}
