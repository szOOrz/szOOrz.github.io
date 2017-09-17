#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxm = 15;
long long Ans;
int n,m,a[maxm];
int main(){
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	Ans = 1LL * n * (n-1);
	for (int i=1;i<=m;i++){
		Ans = Ans - 1LL * a[i] * (a[i]-1);
	}
	printf("%I64d\n",Ans / 2);
}
