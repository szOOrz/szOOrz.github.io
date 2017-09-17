#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using std::max;
int n,m,a[55];
double dp[55][55][55],C[55][55],Pow[55][55];
void init(){
	memset(C,0,sizeof(C));
	C[0][0] = 1;
	for (int i=1;i<=50;i++){
		C[i][0] = 1;
		for (int j=1;j<=i;j++){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	for (int i=0;i<=50;i++){
		for (int j=0;j<=50;j++){
			Pow[i][j] = pow(i,j);
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	memset(dp,0,sizeof(dp));
	for (int i=0;i<=n;i++) dp[0][0][i] = i;
	for (int i=1;i<=m;i++){
		for (int j=0;j<=n;j++){
			for (int k=0;k<=n;k++){
				for (int c=0;c<=j;c++){
					int p = max(k,(c-1) / a[i]+1);
					dp[i][j][k] += 1.0 * dp[i-1][j-c][p] * Pow[i-1][j-c] * C[j][c] / Pow[i][j];
				}
			}
		}
	}
	printf("%.12lf\n",dp[m][n][0]);
	return 0;
}
