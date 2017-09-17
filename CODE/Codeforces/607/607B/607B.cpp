#include<bits/stdc++.h>
using namespace std;
int n,a[505],dp[505][505];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	for (int i=1;i<=n;i++) dp[i][i] = 1;
	for (int l=2;l<=n;l++){
		for (int i=1;i+l-1<=n;i++){
			int j = i+l-1;
			if (a[i] == a[j] && l >= 3) dp[i][j] = dp[i+1][j-1];
	   else if (a[i] == a[j]) dp[i][j] = 1;
	   		for (int k=1;k<=n;k++){
	   			dp[i][j] =min(dp[i][j],dp[i][k]+dp[k+1][j]);
	   		}
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
	
}
