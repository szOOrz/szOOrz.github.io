/*
����һ����1~n��n������ɵ����У�����Ҫ��1�ߵ�2�ߵ�3һֱ�ߵ�n����i�ߵ�i+1��Ҫ����abs(pos[i]-pos[i+1])��ʱ�䣬���ܹ���ʱ 
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
