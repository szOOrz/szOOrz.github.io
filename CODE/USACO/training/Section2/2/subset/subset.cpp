/*
ID:cqz15311
PROG:subset
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
long long f[800],need,n,max;
int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%lld",&n);
	max=(n)*(n+1) / 2;
	if (max & 1==1){
		puts("0");
	}
	else
	{
		need=max / 2;
		f[0]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=400;j>=0;j--)
			{
				f[j+i]+=f[j];
			}
		}
//		for (int i=0;i<=30;i++) printf("%d ",f[i]);
//		puts("");

		printf("%lld\n",f[need]/2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
