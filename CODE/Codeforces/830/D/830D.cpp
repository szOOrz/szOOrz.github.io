#include<bits/stdc++.h> 
const int Mod = 1e9+7;
using namespace std;
int f[505][505],g[505],ans,n;
int main(){
	scanf("%d",&n);
	f[1][0] = f[1][1] = 1;
	for (int i=1;i<=n;i++) g[i] = 1LL * i * (i-1) % Mod;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=n;j++){
			for (int k=0;k<=n-j;k++){
				int t = 1LL * f[i-1][j] * f[i-1][k] % Mod;
				f[i][j+k] = (f[i][j+k] + 1LL * t * ((j+k)*2+1) % Mod) % Mod;
				f[i][j+k-1] = (f[i][j+k-1] + 1LL * t * g[j+k] % Mod) % Mod;
				f[i][j+k+1] = (f[i][j+k+1] + t) % Mod;
			} 
		}
	} 
	printf("%d\n",f[n][1]);
}
