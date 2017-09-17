/*
ID:cqz15311
PROG:crypt1
LANG:C++
*/ 
#include<cstdio>
#include<cstring>
bool f[10050];
int n,x,y,z,ans;
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	scanf("%d",&n);
	memset(f,false,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		f[x]=true;
	}
	for (int i=10;i<=9999;i++)
	{
		if ((f[i % 10]) && (f[i / 10])) f[i]=true; else f[i]=false;
	}
	ans=0;
	for (int i=100;i<=999;i++)
	{
		if (!f[i]) continue;
		for (int j=10;j<=99;j++)
		{
			if (i*j>=10000) break;
			if (!f[j]) continue;
			x=(j % 10) * i;
			if ((!f[x]) || (!((x>=100) && (x<=999)))) continue;
			y=(j / 10) * i;
			if ((!f[y]) || (!((y>=100) && (y<=999)))) continue;
			z=i*j;
			if (!f[z]) continue; 
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
