#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,b,c,Ans;
int main(){
	scanf("%I64d",&n);
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	Ans = 0;
	if ((n>=b) && (b-c) <= a){
		Ans = 1 + (n-b) / (b-c);
		n = n - Ans * (b-c);
	}
	Ans = Ans + n / a;
	printf("%I64d\n",Ans);
	return 0;
}
