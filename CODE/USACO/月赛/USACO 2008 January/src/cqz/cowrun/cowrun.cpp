#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
int i,d[15005],f[15555][555],n,m;
int max(int x,int y){if (x<y) return y;else return x;};
int read()
{
	int a=0;
	char c=getchar();
	while (!((c>='0') && (c<='9'))) c=getchar();
	while ((c>='0') && (c<='9'))
	{
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int main()
{
//	freopen("cowrun.in","r",stdin);
//	freopen("cowrun.out","w",stdout);	 
	n=read();
	m=read();
	for (int i=1;i<=n;i++) d[i]=read();
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0];
		for (int j=1;j<=m;j++)
		{
			if (i-j>=0) f[i][0]=max(f[i][0],f[i-j][j]);
			f[i][j]=f[i-1][j-1]+d[i];
		}
	}
	printf("%d",f[n][0]);
}
 
