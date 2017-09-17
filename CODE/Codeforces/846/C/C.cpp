#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
typedef long long LL;
const LL inf = 0x3fffffff3fffffff;
LL n,sum[5005][5005],a[5005];
int C[5005];
int Aa,Ab,Ac; 
using namespace std;
int main(){
	scanf("%I64d",&n);
	for (int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
	}
	for (int i=0;i<=n;i++){
		sum[i][i] = 0;
		for (int j=i+1;j<=n;j++){
			sum[i][j] = sum[i][j-1] + a[j-1];
	//		printf("%d %d %I64d\n",i,j,sum[i][j]);
		}
	}
	for (int i=0;i<n;i++){
		C[i] = i;
		for (int j=i+1;j<=n;j++){
			if (sum[i][j] - sum[j][n] > sum[i][C[i]] - sum[C[i]][n]) C[i] = j;
		}
	//	printf("%d\n",C[i]);
	}
	LL RET = -inf;
	for (int a=0;a<=n;a++){
		for (int b=a;b<=n;b++){
			int c = C[b];
			if (c < b) break;
	//		printf("0 %d %d %d %d:%I64d\n",a,b,c,n,sum[0][a] - sum[a][b] + sum[b][c] - sum[c][n]);
			if (sum[0][a] - sum[a][b] + sum[b][c] - sum[c][n] > RET){
				Aa = a,Ab = b,Ac = c;
				RET = sum[0][a] - sum[a][b] + sum[b][c] - sum[c][n];
			}
		}
	}
	printf("%d %d %d\n",Aa,Ab,Ac);
	return 0;
}
