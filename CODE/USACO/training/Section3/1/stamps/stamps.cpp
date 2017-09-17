/*
ID:cqz15311
LANG:C++
PROG:stamps
*/
#include<bits/stdc++.h>
using namespace std;
int k,n,x;
int dp[2500005];
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d%d",&k,&n);
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x); 
		for (int j=0;j<=2000000;j++){
			if (dp[j] + 1<dp[j+x])
				dp[j+x] = dp[j] + 1;
		}
	}
	for (int i=1;i<=2000000;i++){
		if (dp[i] > k){
			printf("%d\n",i-1);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
