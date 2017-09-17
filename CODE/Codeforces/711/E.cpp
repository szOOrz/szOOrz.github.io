#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e6+3; 
LL n,k,Ans1,Ans2; 
LL Pow(LL a,LL b,LL Mod){
	LL Ans = 1LL;
	for (;b;b>>=1,a=a*a % Mod){
		if (b & 1) Ans = Ans * a % Mod;
	}
	return Ans;
}
LL gcd(LL a,LL b){
	if(!b) return a; else return gcd(b,a%b);
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	if (n<=63 && k>(1LL<<n)){
		puts("1 1");
		return 0;
	}
	LL s= Pow(2,n,Mod);
	LL t = s;
	Ans1 = 1;
	for (int i=1;i<=k-1;i++){
		Ans1 = (Ans1 * (--s)) % Mod;
		if (!Ans1) break;
	}
	LL num = 0;
	for (LL i=2;i<=k-1;i*=2){
		num = num + (k-1) / i;
	}
	LL inv = Pow(Pow(2,num,Mod),Mod-2,Mod);
	Ans1 = Ans1 * inv % Mod;
	Ans2 = Pow(Pow(2,n,Mod),k-1,Mod);
	Ans2 = Ans2 * inv % Mod;
	Ans1 = (Ans2 - Ans1 + Mod) % Mod;
	printf("%I64d %I64d\n",Ans1,Ans2);
	return 0;
}
