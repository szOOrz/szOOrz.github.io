#include<bits/stdc++.h>
using namespace std;
const int a[10] = {6,2,5,5,4,5,6,3,7,6};
int l,r,Ans;
void calc(int x){
	while (x){
		Ans = Ans + a[x % 10];
		x = x / 10;
	}
}
int main(){
	scanf("%d%d",&l,&r);
	Ans = 0;
	for (int i=l;i<=r;i++){
		calc(i);
	}
	printf("%d\n",Ans);
}
