#include<bits/stdc++.h>
using namespace std;
const int maxn = 205050;
typedef long long LL;
LL n,k,a[maxn],b[maxn],c[maxn],sum,Ans;
int main(){
	scanf("%I64d%I64d",&n,&k);
	for (int i=0;i<=n;i++){
		scanf("%I64d",&a[i]);
		b[i] = c[i] = a[i];
	}
	for (int i=0;i<n;i++){
		b[i+1] += b[i] / 2LL;
		b[i] %= 2LL;
	}
	int flag = n+1;
	for (int i=0;i<=n;i++){
		if (b[i]){
			flag = i;
			break;
		}
	}
	Ans = 0;
	sum = 0;
	for (int i=n;i>=0;i--){
		sum = 2LL * sum + b[i];
		//整个式子的值是sum*2^i 
		if (abs(sum) > 2LL*k) break;
		if (i<=flag){
			LL p = c[i] - sum;
			//得到新的系数，满足Q(2) = 0 
			if (abs(p)> k || (i==n && p==0)) continue;
			Ans++;
		}
	}
	printf("%I64d\n",Ans);
}
