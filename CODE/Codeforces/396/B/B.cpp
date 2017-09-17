#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL prime[(int)1e5+10];
bool flag[(int)1e5+10];
typedef long long LL;
void init(){
	memset(flag,true,sizeof(flag));
	flag[1] = false;
	for (LL i=2;i<=1e5;i++){
		if (flag[i]){
			prime[++prime[0]] = i;
		}
		for (LL j=1;j<=prime[0] && i*prime[j]<=1e5;j++){
			flag[i*prime[j]] = false;
			if (i % prime[j] == 0) break;
		} 
	}
}
bool Isprime(LL k){
	for (LL i=1;i<=prime[0] && prime[i]*prime[i]<=k;i++){
		if (k % prime[i] == 0) return false;
	}
	return true;
}
LL under(LL n){
	for (LL i=n;1;i--)
		if (Isprime(i)) return i;
}
LL up(LL n){
	for (LL i=n+1;1;i++){
		if (Isprime(i)) return i;
	}
}
LL T,n,u,v;
int main(){
	init();
	scanf("%I64d",&T);
	while (T--){
		scanf("%I64d",&n);
		u = up(n);
		v = under(n);
//		printf("%I64d %I64d\n",u,v);
		LL p = 1LL * u * v + 2LL*(n-v-u+1);
		LL q = 1LL * 2 * u * v;
		LL d = __gcd(p,q);
		printf("%I64d/%I64d\n",p/d,q/d);
	}
	return 0;
}
