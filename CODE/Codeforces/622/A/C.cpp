#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 2e5+100;
int a[maxn],pre[maxn];
int l,r,x,n,m,ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	pre[1] = -1;
	for (int i=2;i<=n;i++){
		if (a[i] == a[i-1]) pre[i] = pre[i-1]; else pre[i] = i-1;
	}
	while (m--){
		scanf("%d%d%d",&l,&r,&x);
		if (a[r] == x){
			ans = pre[r];
		} else
			ans = r;
		if (l > ans) puts("-1"); else printf("%d\n",ans);
	}
	return 0;
}
