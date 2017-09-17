#include<bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int maxm = 1010;
int n,m,s,a[maxn];
double dp[maxn*maxm],dpp[maxn*maxm];
int main(){
	scanf("%d%d",&n,&m);
	s = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if (m == 1){
		puts("1");
		return 0;
	}
	memset(dp,0,sizeof(dp));
	dp[0] = m-1;
	for (int i=1;i<=n;i++){
		memset(dpp,0,sizeof(dpp));
		for (int j=0;j<=n*m;j++){
			double p = dp[j] / (m-1);
			dpp[j+1] += p;
			dpp[j+m+1] -= p;
			dpp[j+a[i]] -= p;
			dpp[j+a[i]+1] += p;
		}
		dp[0] = dpp[0];
		for (int j=1;j<=n*m;j++)
			dpp[j] += dpp[j-1],dp[j] = dpp[j];
	}
	double ans = 0;
	for (int j=0;j<s;j++) ans += dp[j];
	printf("%.12lf\n",ans+1.0);
	return 0;
}
/*
设s=a[1]+a[2]+…+a[n]，想知道这个人的最终排名，只需要知道n场比赛后另外m-1个人中总排名低于s的期望人数即可，因为每场比赛所有排名情况出现概率相同，所以另外m-1个人都是一样的，算一个人即可，以dp[i][j]表示i场比赛后这m-1个中总排名是j的期望人数，dp[0][0]=m-1表示还没比赛时排名是0的期望人数就是这m-1个人，在第i场比赛这m-1个人的排名都等概率取1~m中除a[i]的m-1个数，故有转移方程dp[i][j]=sum{dp[i-1][j-k],1<=k<=m,k!=a[i]}/(m-1)，用前缀和优化下该转移，dp[i-1][k]对区间[dp[i][k+1],dp[i][k+m]]扣去dp[i][k+a[i]]点的贡献都是dp[i-1][k]/(m-1)，所以每次在端点处更新最后来一遍前缀和即完成一步转移，最终答案就是dp[n][1]+…+dp[n][s-1]+1，因为该人的排名要在这些总排名靠前的人后面一名 
*/
