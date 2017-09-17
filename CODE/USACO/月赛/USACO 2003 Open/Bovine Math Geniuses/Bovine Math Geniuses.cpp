#include<iostream>
#include<cstdio>
long long n,p,f[1000000];
int main()
{
	scanf("%lld",&n);
	int i=0;
	for (;i<1000000;i++) f[i]=-1;
	i=0;
	for (;;i++)
	{
		if (f[n]!=-1) break;
		f[n]=i;
		n=n / 10 % 10000;
		n=(n*n) % 1000000;
	//	printf("%lld\n",n);
	}
	printf("%lld %lld %lld",n,i-f[n],i);
	return 0;
} 
