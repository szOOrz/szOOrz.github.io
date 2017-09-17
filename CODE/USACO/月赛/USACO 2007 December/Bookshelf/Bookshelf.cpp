#include <iostream> 
#include <cstdio>
#include <algorithm>
bool cmp(int x,int y){return x>y;};
int sum,h[20002],n,b;
int main()
{
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	std::sort(h+1,h+n+1,cmp);
	sum=0;
	for (int i=1;i<=n;i++)
	{
		sum+=h[i];
		if (sum>=b)
		{
			printf("%d",i);
			return 0;
		}
	}
}
