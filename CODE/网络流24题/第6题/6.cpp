#include<bits/stdc++.h>
using namespace std;
int main(){
	scanf("%d",&n);
	dp[0] = 0;
	LIS = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i] = 0;
		for (int j=0;j<i;j++)
		if (a[i] > a[j])
			dp[i] = max(dp[i],dp[j]+1);
		LIS = max(Ans,dp[i]);
	}
	printf("%d\n",Ans);
	int s = 0,t = n+1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			if (dp[i] == dp[j] + 1 && a[i] > a[j]){
				G.add_edge(j,i);
			}
		}
		if (dp[i] == LIS) G.add_edge(i,n+1);
	}
}
