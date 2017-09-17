#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
LL cnt[1<<20],ans[1<<20],Ans,n,m,v[1<<20];
LL s[20][100500],a[100500];
LL count(LL x){
	LL ans = 0;
	for (;x;x>>=1)
		if (x & 1)ans++;
	return ans;
}

void FWT(LL a[],LL n){
	for (LL d=1;d<n;d<<=1){
		for (LL m=d<<1,i=0;i<n;i+=m){
			for (LL j=0;j<d;j++){
				LL x,y;
				x = a[i+j];
				y = a[i+j+d];
				a[i+j] = x + y;
				a[i+j+d] = x-y;
			}
		}
	}
}
void IFWT(LL a[],LL n){
	for (LL d=1;d<n;d<<=1){
		for (LL m=d<<1,i=0;i<n;i+=m){
			for (LL j=0;j<d;j++){
				LL x,y;
				x = a[i+j];
				y = a[i+j+d];
				a[i+j] = (x+y) >> 1;
				a[i+j+d] = (x-y) >> 1;
			}
		}
	}
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	for (LL i=0;i<n;i++){
		for (LL j=0;j<m;j++){
			s[i][j] = getchar() - 48;
			while (s[i][j]!=0 && s[i][j]!=1) s[i][j] = getchar() - 48;
		}
	}
	memset(cnt,0,sizeof(cnt));
	memset(v,0,sizeof(v));
	for (LL i=0;i<m;i++){
		a[i] = 0;
		for (LL j=0;j<n;j++)
			a[i] = a[i] * 2 + s[j][i]; 
		cnt[a[i]]++;
	}
	for (LL i=0;i<(1<<n);i++){
		LL x = count(i);
		v[i] = min(x,n-x);
	}
	FWT(cnt,1<<n);
	FWT(v,1<<n);
	for (LL i=0;i<(1<<n);i++){
		ans[i] = cnt[i] * v[i];
	}
	IFWT(ans,1<<n);
	Ans = 0x3fffffffffffffff;
	for (LL i=0;i<(1<<n);i++)
		Ans = min(Ans,ans[i]);
	printf("%I64d\n",Ans);
}
