#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
int T;
LL n,Ans,i;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%I64d",&n);
		Ans = 1LL * (1+n) * n / 2;
		for (i=1;i<=n;i*=2){
			Ans = Ans - i*2;
		}
		printf("%I64d\n",Ans);
	}
	return 0;
}
