#include<bits/stdc++.h>
const int maxn = 105000;
typedef long long LL;
using namespace std;
int d[maxn],h[maxn],Lmax[maxn],Rmax[maxn];
int n,q;
int top,Stack[maxn];
LL solve(int L,int R){
	top = 0;
	for (int i=L;i<=R;i++){
		//维护一个递减的单调栈
		while ((top > 0) && (d[Stack[top]] <= d[i])){
			Rmax[Stack[top]] = i-1;
			top--;
		}
		Stack[++top] = i;
	} 
	while (top > 0){
		Rmax[Stack[top]] = R;
		top--;
	}
	top = 0;
	
	for (int i=R;i>=L;i--){
		//维护一个递减的单调栈
		while ((top > 0) && (d[Stack[top]] < d[i])){
			Lmax[Stack[top]] = i+1;
			top--;
		}
		Stack[++top] = i;
	} 
	while (top > 0){
		Lmax[Stack[top]] = L;
		top--;
	}
	LL Ans = 0;
	for (int i=L;i<=R;i++){
		Ans = Ans + (LL)(Rmax[i]-i + 1) * (i - Lmax[i] + 1) * d[i];
	}
	return Ans;
}
	
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	for (int i=2;i<=n;i++) d[i] = abs(h[i] - h[i-1]);
	while (q--){
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%I64d\n",solve(L+1,R));
	}
}
