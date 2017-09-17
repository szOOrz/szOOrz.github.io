#include <iostream>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const ll oo=20000000000000; 
ll x[10],a[505000],b[505000];
ll n,i1,i2,j2,ans;
bool cmp(ll x,ll y){return x<y;}
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+1+n,cmp);
	for (int i=n+1;i<=500000;i++) a[i]=oo;
	for (int i=1;i<=500000;i++) b[i]=oo;
	i1=1;i2=1;
	j2=0;
	ans=0;
	for (int i=1;i<n;i++)
	{
		x[1]=a[i1];
		x[2]=a[i1+1];
		x[3]=b[i2];
		x[4]=b[i2+1];
		std::sort(x+1,x+5,cmp);
	//	for (int t=1;t<=4;t++) printf(" %lld ",x[t]);
		
		if ((x[1]==a[i1]) && (x[2]==a[i1+1]))
		{
			//printf("!!");
			j2++;
			b[j2]=a[i1]+a[i1+1];
			ans+=a[i1]+a[i1+1];
			i1+=2;
		}
		else
		if (((x[1]==a[i1]) && x[2]==b[i2]) || ((x[1]==b[i2]) && (x[2]==a[i1])))
		{
			//printf("%%");
			j2+=1;
			b[j2]=a[i1]+b[i2];
			ans+=a[i1]+b[i2];
			i1+=1;
			i2+=1;
		}
		else
		if ((x[1]==b[i2]) && (x[2]==b[i2+1]))
		{
			//printf("^^");
			j2++;
			b[j2]=b[i2]+b[i2+1];
			ans+=b[i2]+b[i2+1];
			i2+=2;
		}
	//	printf("%lld\n",ans);
	}
	printf("%lld",ans);
	return 0;
}
