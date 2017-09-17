#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath> 
using namespace std;
typedef __int64 LL;
const LL Mod = 1e9+7;
const LL sqrtn = 10000007;
LL n,m,a[sqrtn],b[sqrtn],t,Ans,inv2;
LL Pow(LL a,LL b){
	LL Ans = 1LL;
	for (;b;b>>=1,a=1LL*a*a % Mod){
		if (b & 1)Ans = 1LL * Ans * a % Mod;
	}
	return Ans;
}
LL sum(LL a,LL b){
	if (a > b) return 0;
	LL x = (b-a+1);
	LL y = (a + b);
	if (x&1) y>>=1; else x>>=1;
	x%=Mod;
	y%=Mod;
	return 1LL * x * y % Mod;
}
bool cmp(LL a,LL b){
	return a > b;
}
int main(){
	//freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	inv2 = Pow(2,Mod-2);
	scanf("%I64d%I64d",&n,&m);
/*
4000000000
41925514
*/
	t = sqrt(n);
	while ((t+1) * (t+1) <= n) t++;
	a[0] = 0;
	for (LL i=1;i<=t;i++){
		a[++a[0]] = n / i;
	} 
	for (LL i=1;i<=a[0];i++){
		a[2*a[0]-i+1] = n / a[i];
	}
	a[0]=a[0]*2;
	b[0] = 0;
	for (LL i=1;i<=a[0];i++) b[i] = n / a[i];
	b[0] = 0;
	b[a[0]+1] = n+1;
	Ans = 0;
	if (m > n) Ans=Ans + (m-n) % Mod *(n % Mod) % Mod,m=n;
	Ans  = (Ans + m % Mod * (n % Mod) % Mod) % Mod;
	for (LL i=1;i<=a[0];i++){
		if (b[i] >= m){
			Ans = ((Ans - 1LL * a[i] % Mod * sum(b[i-1]+1,m)) % Mod + Mod) % Mod;
			break;
		} else{
			Ans = ((Ans - 1LL * a[i] % Mod * sum(b[i-1]+1,b[i])) % Mod + Mod) % Mod;
		}
	}
	printf("%I64d\n",Ans);
	return 0;
}
/*
10 * 1 + 5 * 1 + 3 * 0 + 3 * 2
(6-5+1) * 2

n % 1 + n % 2 + n % 3 ……+ n % m
= n - n div 1 * 1 + n - n div 2 * 2 + n - n div 3 * 3
= n*m - 
(n div 1 * 1 + n div 2 * 2 + n div 3 * 3……)
35 div 5 = 7

设n div i = j;
那么n div j = i 

设满足使得递增的排序是:
a1,a2,a3,a4,a5
那么显然
a1到a2-1
a2到a3-1
……
都是相同的。
只有sqrt种可能性。

10 / 6 = 1

10 / 1 = 10
10 / 2 = 5
10 / 3 = 3
10 / 3 = 3
10 / 5 = 2
10 / 10= 1

1  2 3 3 5 10
10 5 3 3 2 1



10 * 1 + 5 * 1 + 3 * 0 + 3 * 2
(6-5+1) * 2


5%1=0
5%2=1
5%3=2
5%4=1
5%5=0
10000000000000 10000000000000
*/
