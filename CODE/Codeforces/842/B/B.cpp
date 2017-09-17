#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e5+100;
int D,R,n,Ans;
int x[maxn],y[maxn],r[maxn];
long double Dis,Min,Max;
const long double eps = 1e-10;
int main(){
	scanf("%d%d",&R,&D);
	R = R - D;
	D = D + R;
	scanf("%d",&n);
	Ans = 0;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
		Dis = sqrt(1.0* x[i] * x[i] + 1.0 * y[i] * y[i]);
		Min = max((long double)0.0,Dis - r[i]);
		Max = Dis + r[i];
		if ((Min - R >= -eps) && (D - Max >= -eps)) Ans++;
	}
	printf("%d\n",Ans);
	return 0;
}
