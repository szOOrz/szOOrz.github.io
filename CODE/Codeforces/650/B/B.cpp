#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
LL n,a,b,t;
char s[1000006];
int w[1000006];
LL ans,sum;
int main(){
	scanf("%I64d%I64d%I64d%I64d%s",&n,&a,&b,&t,s);
	for (int i=0;i<n;i++){
		if (s[i] == 'w') w[i] = w[i+n] = b+1; else
						 w[i] = w[i+n] = 1;
		sum+=w[i];
	}
	sum-=w[0];
	LL l=1,r=n;
	while (l<=n && r<=n+n){
		sum+=w[r++];
		while (r-l>n || sum+(r-l-1+min(r-n-1,n-l))*a > t){
			sum-= w[l++];
		}
		if (l > n) break;
 		ans = max(ans,r-l);
	}
	printf("%I64d\n",ans);
	return 0;
}
