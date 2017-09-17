#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
typedef long long ll; 
const ll oo=9999999999;
ll now,minval,time,n,w[100005],h[100005],l[100005],r[100005],ans[100005];
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld %lld",&w[i],&h[i]); 
	for (int i=1;i<=n;i++) l[i]=i-1;
	for (int i=n;i>=1;i--) r[i]=i+1;
	minval=1;
	for (int i=2;i<=n;i++) if (h[i]<h[minval]) minval=i;
	now=minval;
	time=0;
	h[0]=oo;
	h[n+1]=oo;
	for (int i=1;i<n;i++)
	{
		ans[now]=time+w[now];
		if (h[r[now]]<h[l[now]])
		{
			time+=w[now]*(h[r[now]]-h[now]);
			w[r[now]]+=w[now];
			l[r[now]]=l[now];
			r[l[now]]=r[now];
			now=r[now];
		}
		else
		{
			time+=w[now]*(h[l[now]]-h[now]);
			w[l[now]]+=w[now];
			r[l[now]]=r[now];
			l[r[now]]=l[now];
			now=l[now];
		}
		while (h[l[now]]<h[now]) now=l[now];
		while (h[r[now]]<h[now]) now=r[now]; 
	}
	ans[now]=time+w[now];
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
}  
