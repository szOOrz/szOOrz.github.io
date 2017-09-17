#include<bits/stdc++.h>
using namespace std;
int T,Ans,X1,X2,Y1,Y2;
int main(){
	Ans = 0;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		Ans += (abs(X1-X2)+1) * (abs(Y1-Y2)+1);
	}
	printf("%d\n",Ans);
}
