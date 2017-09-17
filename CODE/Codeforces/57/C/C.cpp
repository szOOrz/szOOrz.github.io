#include<bits/stdc++.h>
typedef long long LL;
const int Mod = 1000000007;
int n;
using namespace std;
void exgcd(int a,int b,int &x,int &y){
	if (!b){
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int inv(int a){
	int d,x,y;
	exgcd(a,Mod,x,y);
	return (x%Mod+Mod)%Mod;
}
int fac(int x){
	int ans = 1;
	for (int i=1;i<=x;i++) ans = 1LL * ans * i % Mod;
	return ans;
}
int main(){
	scanf("%d",&n);
	if (n == 1){
		puts("1");
		return 0;
	}
	int Ans = 2LL * fac(2*n-1);
	Ans = 1LL * Ans * inv(fac(n-1)) % Mod;
	Ans = 1LL * Ans * inv(fac(2*n-1-(n-1))) % Mod;
	Ans = ((Ans - n) % Mod + Mod) % Mod;
	printf("%d\n",Ans);
	return 0;
}
