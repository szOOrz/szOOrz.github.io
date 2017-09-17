/*
ID:cqz15311
LANG:C++
PROG:inflate
*/
#include<bits/stdc++.h>
using namespace std;
int dp[20005];
int n,m,a,b;
int main(){
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		for (int j=0;j<=m;j++){
			dp[j+b] = max(dp[j+b],dp[j]+a);
		}
	}
	printf("%d\n",dp[m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
