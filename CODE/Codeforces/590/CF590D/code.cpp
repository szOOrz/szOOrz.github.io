#include<bits/stdc++.h>
using namespace std;
const int maxn = 155;
int dp[maxn*maxn][maxn],N,K,S,a[maxn],Ans;
int main(){
	memset(dp,0x3f,sizeof(dp));
	dp[0][0] = 0;
	scanf("%d%d%d",&N,&K,&S);
	int Maxs = (N * (N-1)) / 2;
	for (int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		for (int j=Maxs;j>=0;j--)
			for (int k=K;k>=0;k--)
				if ((j - (i-k) >= 0) && (k-1 >= 0))
					dp[j][k] = min(dp[j][k],dp[j-(i-k)][k-1] + a[i]);
	}
	Ans = 0x3fffffff;
	for (int i=0;i<=min(S,Maxs);i++) Ans = min(Ans,dp[i][K]);
	printf("%d\n",Ans);
}
