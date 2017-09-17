#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 1e6+100;
int n,a[maxn],b[maxn];
long long Rec,Ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	Rec = 0;
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		Rec = Rec + (i - b[a[i]]);
		Ans = Ans + Rec;
		b[a[i]] = i;
	}
	printf("%.12lf\n",1.0 * ((Ans - n) * 2 + n) / n / n);
	return 0;
}
/*1 1
1 2 1 2
1 3 1 3
2 2
2 3 2 3
3 3*/
