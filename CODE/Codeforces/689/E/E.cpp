#include<bits/stdc++.h>
using namespace std;
const int maxn = 205000;
const int Mod = 1e9+7;
int n,k,l[maxn],r[maxn],y[maxn*2],f[maxn*2];
int sum,Ans;
int find(int x){
	int L = 1,R = y[0];
	while (L <= R) {
		int Mid = (L + R) >> 1;
		if (y[Mid] < x) L = Mid + 1; else
		if (y[Mid] > x) R = Mid - 1; else
						return Mid;
	}
	return -1;
}
int fac[405050],inv[405050];
int Pow(int a,int b){
	int Ans = 1;
	for (;b;b>>=1,a=1LL*a*a % Mod){
		if (b&1)Ans =1LL * Ans * a % Mod;
	}
	return Ans;
}
void init(){
	fac[0] = 1;
	for (int i=1;i<=400000;i++){
		fac[i] = 1LL * fac[i-1] * i % Mod;
	}
	inv[400000] = Pow(fac[400000],Mod-2);
	for (int i = 399999;i>=0;i--){
		inv[i] = 1LL * inv[i+1] * (i+1) % Mod;
	}
}
int C(int x,int y){
	return 1LL * fac[x] * inv[y] % Mod * inv[x-y] % Mod;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		r[i]++;
		y[++y[0]] = l[i];
		y[++y[0]] = r[i];
	}
	sort(y+1,y+1+2*n);
	y[0] = 0;
	for (int i=1;i<=2*n;i++){
		if (i == 1 || y[i]!=y[i-1]){
			y[++y[0]] = y[i];
		}
	}
	for (int i=1;i<=n;i++){
		f[find(l[i])]++;
		f[find(r[i])]--;
	}
//	for (int i=1;i<=y[0];i++) printf("%d ",f[i]);
//	puts("");
	sum = 0;
	y[y[0]+1] = y[y[0]];
	Ans = 0;
	for (int i=1;i<=y[0];i++){
		sum = sum + f[i];
		if (sum < k) continue;
//		printf("C(%d,%d) = %d\n",sum,k,C(sum,k));
		Ans = (Ans + (1LL * (y[i+1]-y[i]) * C(sum,k) % Mod)) % Mod;
	}
	printf("%d\n",Ans);
}
