#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1000005;
int n,a[maxn],sum[maxn];
int main(){
	scanf("%d",&n);
	sum[0] = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]+=a[i];
	}
	if (sum[n] & 1) puts("First"); else{
		bool flag = false;
		for (int i=1;i<=n;i++) if (sum[i] & 1) flag = true;
		if (flag) puts("First"); else puts("Second");
	}
	return 0;
}
/*
考虑整一段是奇数，全部取完就行了
考虑整一段是偶数，只需要取出一段就赢了。
就是看能不能取出这一小段，使得这一段的数值和是奇数。
考虑得到前缀和，如果所有前缀和都是偶数，那么Second，否则First 
*/
