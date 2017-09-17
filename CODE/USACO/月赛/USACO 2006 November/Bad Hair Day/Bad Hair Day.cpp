#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
long long n;
long long ans=0;
long long h[80500],shed[80500];
long long top,temp;
int main()
{
	scanf("%lld",&n); 
	memset(shed,0,sizeof(shed));
	for (int i=0;i<n;i++)scanf("%lld",&h[i]);
	top=0;
	for (int i=0;i<n;i++)
	{
		temp=h[i];
		while ((top>0) and (shed[top]<=temp)) top--;
		ans+=top;
		shed[++top]=temp;
	}
	printf("%lld",ans);
	return 0;
}
