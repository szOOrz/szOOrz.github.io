#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
int main(){
	scanf("%I64d",&n);
	LL i = 1,Rec = 0;
	while (Rec+i < n){
		Rec = Rec + i;
		i++;
	}
	printf("%I64d\n",n - Rec);
	return 0;
}
