#include<cstdio> 
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL len,a[5005];
LL n,m,mid[250505],pre[250505],suf[250505],all[250505];
LL f[250505],b[250505],Ans;
LL Mid(){
	LL Ans = 0;
	LL Rec = 0;
	for (LL i=1;i<=len;i++){
		Rec = Rec + a[i];
		if (Rec < 0) Rec = 0;
		Ans = max(Ans,Rec);
	}
	return Ans;
}
LL Pre(){
	LL Ans = 0;
	LL Rec = 0;
	for (LL i=1;i<=len;i++){
		Rec = Rec + a[i];
		Ans = max(Ans,Rec);
	}
	return Ans;
}
LL Suf(){
	LL Ans = 0;
	LL Rec = 0;
	for (LL i=len;i>=1;i--){
		Rec = Rec + a[i];
		Ans = max(Ans,Rec);
	}
	return Ans;
} 
LL All(){
	LL Ans = 0;
	for (LL i=1;i<=len;i++) Ans = Ans + a[i];
	return Ans;
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	for (LL i=1;i<=n;i++){
		scanf("%I64d",&len);
		for (LL j=1;j<=len;j++){
			scanf("%I64d",&a[j]);
		}
		mid[i] = Mid();
		pre[i] = Pre();
		suf[i] = Suf();
		all[i] = All();
	}
	for (LL i=1;i<=m;i++){
		scanf("%I64d",&b[i]);
	}
	Ans = 0;
	f[0] = 0;
	for (LL i=1;i<=m;i++){
		f[i] = max(f[i-1]+all[b[i]],suf[b[i]]);
		Ans = max(Ans,mid[b[i]]);
		Ans = max(Ans,f[i-1]+pre[b[i]]);
	}
	Ans = max(Ans,f[m]);
	printf("%I64d\n",Ans);
	return 0;
}
