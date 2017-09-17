#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn],ans,n;
int main(){
	scanf("%d",&n);
	ans = 1e9;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=n/2+1;i<=n;i++)
		ans = min(ans,a[i] - a[i-n/2]);
	printf("%d\n",ans);
	return 0;
}
