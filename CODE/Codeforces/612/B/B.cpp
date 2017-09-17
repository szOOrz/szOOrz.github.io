/*
给出一个由1~n这n个数组成的序列，现在要从1走到2走到3一直走到n，从i走到i+1需要花费abs(pos[i]-pos[i+1])的时间，问总共耗时 
*/
#include<bits/stdc++.h>
using namespace std;
int n,x;
long long Ans;
int pos[200005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		pos[x] = i;
	}
	Ans = 0;
	for (int i=2;i<=n;i++){
		Ans = Ans + abs(pos[i] - pos[i-1]);
	}
	printf("%I64d\n",Ans);
}
