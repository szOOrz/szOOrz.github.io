#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

int n,ans;

int main()
{
    //freopen("2140.in","r",stdin);
    //freopen("2140.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a=n / i;
		if (i % 2 == 1)
		{
			if ((i*a==n) and ((a-(i-1)/2)>=1))
			{
				ans++;
			}
		}
		else
		{
			if (((i*(a+a+1)/2)==n) and ((a-(i-2)/2)>=1))
			{
				ans++;
			}
		}
	} 
	printf("%d",ans);
	return 0;
}
