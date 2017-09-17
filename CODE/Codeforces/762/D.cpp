#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
const int maxn = 100010;
LL dp[maxn][4];
int n,a[3][maxn];
LL sum(int x,int l,int r){
	if (l > r) swap(l,r);
	LL res = 0;
	for (int i=l;i<=r;i++) res+=a[i][x];
	return res;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<3;i++)
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	memset(dp,0xc0,sizeof(dp));
	dp[0][0] = 0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<3;j++)
			for (int k=0;k<3;k++)
				dp[i][j] = max(dp[i][j],dp[i-1][k] + sum(i,j,k));
		dp[i][0] = max(dp[i][0],dp[i-1][3]+sum(i,0,2));
		dp[i][2] = max(dp[i][2],dp[i-1][3]+sum(i,0,2));
		dp[i][3] = (dp[i][3],max(dp[i-1][0],dp[i-1][2])+sum(i,0,2));
	}
	printf("%I64d\n",dp[n][2]);
	return 0;
}
