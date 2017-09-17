#include<bits/stdc++.h> 
using namespace std;
long long Ans;
int n;
int main(){
	scanf("%d",&n);
	Ans = 0;
	for (long long a=9,i=1;a<=9000000000;a*=10,i++){
		if (n >= a){
			Ans = Ans + a * i;
			n-=a;
		} else{
			Ans = Ans + n * i;
			break;
		}
	}
	printf("%I64d\n",Ans);
	return 0;
}
