//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
//样例都没过哟！！！！！ 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105000;
typedef long long LL;
LL n,A,cf,cm,m;
LL sum[maxn],a[maxn];
LL ans,ansl,ansr;
LL get(int l,int r,LL m){
//	printf("Get(%d,%d,%lld\n",l,r,m);
	LL x = a[l];
	LL num = l;
	x += m/l;
	x =max(x,A);
//	printf("%d*%d+%d*%d\n",cm,x,cf,(n-r));
	return cm*x+cf*(n-r);
}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&A,&cf,&cm,&m);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		} 
	sort(a+1,a+1+n);
	sum[0] = 0;
	for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
	int l = 1,r = n+1;
	//r+1~n
	//(n-r)个元素
	//需要A*(n-r)
	//满足A*(n-r) - (sum[n] - sum[r])可行 
	while ((l<=(r-1)) && m - (A - a[r-1]) >= 0 ) m-=(A-a[r-1]),r--;
	while ((l+1<=r) && a[l+1] * (l+1) - sum[l+1] <= m) l++;
//	printf("M = %d",m);
//	printf("-(%d * %d - %d)\n",a[l],l,sum[l]);
	ans = get(l,r,m-(a[l]*l-sum[l]));
	printf("(%d,%d,%lld\n",l,r,ans);
	ansl = l;
	ansr = r;
	while (r <= n+1){
		//保证r+1~n都是A
		m+=a[r];
		r++;
		//剩下的m可以分配给前面的
		while ((l+1<=r) && a[l+1] * (l+1) - sum[l+1] <= m) l++;
		int rec =get(l,r,m-(a[l]*l-sum[l]));
		printf("(%d,%d,%lld\n",l,r,rec);
		if (rec > ans){
			ans = rec;
			ansl = l;
			ansr = r;
		}
	}
	printf("%d\n[%d,%d]\n",ans,ansl,ansr);
	return 0;
}
