#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn = 1e5+100;
long long b[maxn],a[maxn],k[maxn];
int n,f[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&b[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]),b[i]-=a[i];
	for (int i=2;i<=n;i++) scanf("%d%d",&f[i],&k[i]);
	for (int i=n;i>=2;i--){
		if (b[i] > 0) b[f[i]] += b[i]; else{
			if ((double)b[i] > (double)1e17 / k[i]) {
				puts("NO"); return 0;
			}
			if ((double)b[f[i]] < -(double)b[i] * k[i] -1e17){
				puts("NO"); return 0;
			}
			b[f[i]] += 1LL * k[i] * b[i];
		}
		b[i] = 0;
	}
	if (b[1] >= 0) puts("YES"); else puts("NO");
	return 0;
}
