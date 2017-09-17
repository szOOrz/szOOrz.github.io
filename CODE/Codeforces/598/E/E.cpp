#include<bits/stdc++.h> 
using namespace std;
/*
用dp[i,j,k]表示一个n*m的巧克力，切出k的巧克力，需要花费的最小代价
先考虑横着且，设中间转折点为t
dp[i,j,k] = min(dp[i,t,k-i*(j-t)] + i*i);
dp[i,j,k] = min(dp[t,j,k-j*(i-t)] + j*j); 
其中dp[1,1,1] = 0,dp[1,1,0] = 0; 
*/
int T,n,m,k,dp[31][31][51];
int main(){
	memset(dp,0x3f,sizeof(dp));
	dp[1][1][1] = 0;
	dp[1][1][0] = 0;
	for (int i=1;i<=30;i++){
		for (int j=1;j<=30;j++){
			for (int k=0;k<=50;k++){
				if (k == 0 || k == i*j) {dp[i][j][k] = 0; continue;}
				int &rec = dp[i][j][k];
				for (int h=0;h<=k;h++){
					for (int t=1;t<=j-1;t++){
						rec = min(rec,dp[i][t][h] + dp[i][j-t][k-h] + i*i);
					}
					for (int t=1;t<=i-1;t++){
						rec = min(rec,dp[t][j][h] + dp[i-t][j][k-h] + j*j);
					}
				}
//				if (i >= 18) printf("dp[%d,%d,%d] =%d\n",i,j,k,dp[i][j][k]);
			}
		}
	} 
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",dp[n][m][k]);
	}
	return 0;
}
