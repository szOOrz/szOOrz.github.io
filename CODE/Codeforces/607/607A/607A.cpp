#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n,nmax,d[maxn],dp[maxn];
int main(){
	scanf("%d",&n);
	nmax = 0;
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		scanf("%d",&d[a]);
		nmax = max(a,nmax);
	}
	memset(dp,0,sizeof(dp));
	int i;
	if (d[0]) dp[0] = 1;
	int rec = n;
	rec = min(rec,n - dp[0]);
	for (int i=1;i<=nmax;i++){
		if (d[i] == 0)	dp[i] = dp[i-1];
		else{
			if (d[i] >= i)	dp[i] = 1; else
							 dp[i] = dp[i-d[i]-1]+1;
			}
		rec = min(rec,n-dp[i]);
	}
	printf("%d\n",rec);
	return 0 ; 
}
 
