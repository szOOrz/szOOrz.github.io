#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

int n,k,ans;
long a[1000000];

int main()
{
    //freopen("2338.in","r",stdin);
    //freopen("2338.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		a[k]++;
	};
	ans=0;
	for (int i=1;i<=1000000;i++)
	{
		ans=ans+a[i];
		if (ans> (n >> 1))
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}
