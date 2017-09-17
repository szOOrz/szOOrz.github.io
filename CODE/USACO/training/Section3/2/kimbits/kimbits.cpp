/*
ID:cqz15311
LANG:C++
PROG:kimbits
*/
/*
用dp[i,j]表示长度为i，最多包含j个1有多少个 
C(n,0)+C(n,1)+…… 
*/
#include<bits/stdc++.h>
long long n,l,t,f[105][105];
int main(){
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	scanf("%lld %lld %lld",&n,&l,&t);
	for (int i=0;i<=n;i++) f[i][0] = f[0][i] = 1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j] = f[i-1][j] + f[i-1][j-1];
		}
	}
	for (int i=n;i>=1;i--){
		if (t > f[i-1][l]){
			putchar('1');
			t-=f[i-1][l];
			l--;
		} else putchar('0');
	}
	puts("");
	return 0;
}
