#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
long long Q,H,S,D,N,Ans;
int main(){
	scanf("%lld%lld%lld%lld",&Q,&H,&S,&D);
	if (2*Q<H) H = 2*Q;
	if (2*H<S) S = 2*H;
	if (2*S<D) D = 2*S;
	scanf("%lld",&N);
	N = N * 4; 
	Ans = 0;
	Ans = Ans + N / 8 * D;
	N = N % 8;
	Ans = Ans + N / 4 * S;
	N = N % 4;
	Ans = Ans + N / 2 * H;
	N = N % 2;
	Ans = Ans + N / 1 * Q;
	printf("%lld\n",Ans);
	return 0;
}
