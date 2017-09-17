#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005000;
vector<LL> gcd;
LL n;
LL a,b,val[maxn],Ans;
LL dp[maxn][3],cost[maxn];
LL calc(LL x){
	for (int i=1;i<=n;i++){
		cost[i] = 1e10;
		if (val[i] % x == 0){
			cost[i] = 0;
		} else
		if (((val[i] + 1) % x== 0)|| ((val[i]-1) % x == 0)){
			cost[i] = b;
		}
	}
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++){
		dp[i][0] = dp[i-1][0] + cost[i];
		dp[i][1] = min(dp[i-1][0] + a,dp[i-1][1]+a);
		dp[i][2] = min(dp[i-1][2] + cost[i],dp[i-1][1]+cost[i]);
	}
	return min(min(dp[n][0],dp[n][1]),dp[n][2]);
}
void pri(LL x){
	for (int i=2;i*i<=x;i++){
		if (x % i == 0) gcd.push_back(i);
		while (x % i == 0) x/=i;
	}
	if (x != 1)
		gcd.push_back(x);
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&val[i]);
	}
	pri(val[1]);
	pri(val[1]+1);
	pri(val[1]-1);
	pri(val[n]);
	pri(val[n]-1);
	pri(val[n]+1);
	sort(gcd.begin(),gcd.end());
	Ans = 1e17;
	for (int i=0;i<(int)gcd.size();i++){
		if ((i == 0) || (gcd[i]!=gcd[i-1])){
			Ans = min(Ans,calc(gcd[i]));
		}
	}
	printf("%I64d\n",Ans);
	return 0;
}
