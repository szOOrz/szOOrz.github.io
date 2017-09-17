#include<bits/stdc++.h>
using namespace std;
int n,k,Ans[505][505],cnt,Res;
int main(){
	scanf("%d%d",&n,&k);
	cnt = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<k;j++){
			Ans[i][j] = ++cnt;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=k;j<=n;j++){
			Ans[i][j] = ++cnt;
		}
	}
	Res = 0;
	for (int i=1;i<=n;i++) {
		Res+=Ans[i][k];
	}
	printf("%d\n",Res);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			printf("%d ",Ans[i][j]);
		}
		puts("");
	}
	puts("");
}
