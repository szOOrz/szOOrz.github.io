#include<bits/stdc++.h>
using namespace std;
long long t,Ans,s,x;
int main(){
	scanf("%I64d%I64d",&s,&x);
	bool flag = false;
	if (s == x) flag =true;
	if ((s - x) & 1){
		puts("0");
		return 0;
	}
	t = (s-x) / 2;
	Ans = 1;
	for (int i=0;i<=50;i++){
		if ((x & 1) == 1){
			if (t & 1) Ans = 0; else
					   Ans *=2;
		}
		x>>=1;
		t>>=1;
	}
	if (flag) Ans-=2;
	printf("%I64d\n",Ans);
	return 0;
}
