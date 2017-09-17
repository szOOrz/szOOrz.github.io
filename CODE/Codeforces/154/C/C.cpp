#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int maxn = 2e6 + 100;
//const LL Mod = 23333333333;
int n,m;
LL Hash[maxn],Pow[maxn];
LL Ans;
int x[maxn],y[maxn];
int main(){
	scanf("%d%d",&n,&m);
	Pow[0] = 1;
	for (int i=1;i<=n;i++){
		Pow[i] = 3LL * Pow[i-1]; 
	}
	for (int i=0;i<n;i++) Hash[i] = 0;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]--;y[i]--;
		Hash[y[i]] = (Hash[y[i]] + Pow[x[i]]);
		Hash[x[i]] = (Hash[x[i]] + Pow[y[i]]);
	}
	for (int i=0;i<m;i++){
		LL _x,_y;
		_x = (Hash[x[i]] + Pow[x[i]]);
		_y = (Hash[y[i]] + Pow[y[i]]);
		if (_x == _y) Ans++;
	}
	sort(Hash,Hash+n);
	int l = 0;
	for (int r=1;r<=n;r++){
		if (Hash[r]!=Hash[l]){
			Ans = Ans + 1LL * (r - l) * (r - l - 1) / 2;
			l = r;
		}
	}
	Ans = Ans + 1LL * (n-l) * (n-l-1) / 2;
	printf("%I64d\n",Ans);
}
