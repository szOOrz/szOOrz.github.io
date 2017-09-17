#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
const LL maxn =2002;
LL sa,sb;
LL n,m,a[maxn],b[maxn];
struct V{
	LL val,a,b;
	bool operator < (const V &t) const{
		return val < t.val;
	}
}va[maxn*maxn],vb[maxn*maxn];
LL Ans,_rec,x[5],y[5],num;
LL find1(LL x){
	LL L = 1,R = vb[0].val;
	LL Ans = -1;
	while (L <= R) {
		LL mid = (L + R) >> 1;
		if (x <= vb[mid].val*2){
			Ans = mid;
			R = mid-1;
		} else
			L = mid+1;
	}
	return Ans;
}
LL find2(LL x) {
	LL L = 1,R = vb[0].val;
	LL Ans = -1;
	while (L <= R) {
		LL mid = (L + R) >> 1;
		if (x >= vb[mid].val*2){
			Ans = mid;
			L = mid+1;
		} else
			R = mid-1;
	}
	return Ans;	
}
LL ans;
int main(){
//	freopen("1.in","r",stdin);
	//freopen("JR.out","w",stdout); 
	scanf("%I64d",&n);
	sa = 0;
	for (LL i=1;i<=n;i++) scanf("%I64d",&a[i]),sa+=a[i];
	scanf("%I64d",&m);
	sb = 0;
	for (LL i=1;i<=m;i++) scanf("%I64d",&b[i]),sb+=b[i];
	//考虑不进行交换
	Ans = abs(sa - sb);
	num = 0;
	//考虑进行一次交换
	for (LL i=1;i<=n;i++){
		for (LL j=1;j<=m;j++){
			if (abs((sa + b[j] - a[i])-(sb - b[j] + a[i])) < Ans){
				Ans = abs((sa + b[j] - a[i])-(sb - b[j] + a[i]));
				num = 1;
				x[1] = i;
				y[1] = j;
			}
		}
	} 
	//考虑进行两次交换
	va[0].val = 0;
	for (LL i=1;i<=n;i++){
		for (LL j=i+1;j<=n;j++){
			va[++va[0].val].val = a[i] + a[j];
			va[va[0].val] . a = i;
			va[va[0].val] . b = j;
		}
	}
	sort(va+1,va+1+va[0].val);
	vb[0].val = 0;
	for (LL i=1;i<=m;i++){
		for (LL j=i+1;j<=m;j++){
			vb[++vb[0].val].val = b[i] + b[j];
			vb[vb[0].val] . a = i;
			vb[vb[0].val] . b = j;
		} 
	}
	sort(vb+1,vb+1+vb[0].val);
	for (LL i=1;i<=va[0].val;i++){
//如果上面大
/*
sa - va[i] + ***** >= sb + va[i] - ******
(- sa + sb + 2*va[i]) / 2 >=  (*****)
	也就是找到一个满足条件的最大的 ****
*/ 
//		printf("%d %d\n",va[i].a,va[i].b); 
		LL u = find1((-sa+sb+2*va[i].val));//找到比这个小于等于的最大的。
//		printf("--*%d\n",u); 
//		if (u!=-1) printf("----%d %d\n",vb[u].a,vb[u].b);
		if (u != -1){
			_rec = abs(sa - va[i].val + vb[u].val - (sb + va[i].val - vb[u].val));
			if (_rec < Ans){
				Ans = _rec;
				num = 2;
				x[1] = va[i].a;
				x[2] = va[i].b;
				y[1] = vb[u].a;
				y[2] = vb[u].b;
			} 
		}
		u = find2((-sa+sb+2*va[i].val));//注意到，因为找的是整数，所以可以除
//		printf("--*%d\n",u);
//		if (u!=-1) printf("----%d %d\n",vb[u].a,vb[u].b);
		//找大于这个的最小的 
		if (u != -1){
			_rec = abs(sa - va[i].val + vb[u].val - (sb + va[i].val - vb[u].val));
			if (_rec < Ans){
				Ans = _rec;
				num = 2;
				x[1] = va[i].a;
				x[2] = va[i].b;
				y[1] = vb[u].a;
				y[2] = vb[u].b;
			} 
		}
	}
	printf("%I64d\n",Ans);
	printf("%I64d\n",num);
	for (LL i=1;i<=num;i++){
		printf("%I64d %I64d\n",x[i],y[i]);
	}
	return 0;
}
