#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const double eps = 1e-8;
LL count(LL x){
	LL t = 1,res = 0;
	while (x >= 2*t-1){
		res = res + t;
		t = t*10;
	}
	if (x / t == 1) res += x - t + 1;
	return res;
}
const int maxn = 1005;
int n;
double p[maxn];
LL l[maxn],r[maxn];
double dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64u%I64u",&l[i],&r[i]);
		p[i] = (count(r[i]) - count(l[i]-1)) * 1.0 / (r[i] - l[i] + 1);
//		printf("%lf\n",p[i]);
	}
	memset(dp,0,sizeof(dp));
	dp[1][1] = p[1];
	dp[1][0] = 1-p[1];
	for (int i=2;i<=n;i++){
		dp[i][0] = dp[i-1][0] * (1-p[i]);
		for (int j=1;j<=i;j++){
			dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1-p[i]);
		}
	}
/*	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++){
			printf("%d %d %lf\n",i,j,dp[i][j]);
		} 
	}
*/	int k;
	scanf("%d",&k);
	double tmp = n * k / 100.0,ans = 0;
	int need = ceil(tmp);
//	printf("%d\n",need);
	for (int i=need;i<=n;i++){
		ans = ans + dp[n][i];
//		printf("(%d,%d):%.10lf\n",n,i,dp[n][i]);
	}
	printf("%.100lf\n",ans);
}
