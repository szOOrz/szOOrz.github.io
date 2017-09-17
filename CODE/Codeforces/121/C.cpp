#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long LL;
LL t[1500],n,k;
LL fac[20],base,tmp,rec[20],Ans;
bool used[20];
void init(LL x){
	if (x > 1e8) return;
	t[++t[0]] = x*10+4;
	init(x*10+4);
	t[++t[0]] = x*10+7;
	init(x*10+7);
}
bool check(LL x){
	for (LL i=1;i<=t[0];i++){
		if (t[i] == x){
//			printf("%d   ----   %I64d %I64d\n",i,t[i],x);
			return true;
		}
	}
	return false;
}
int main(){
	t[0] = 0;
	init(0);
	sort(t+1,t+1+t[0]);
	scanf("%I64d%I64d",&n,&k);
	Ans = 0;
	base = 0;
	if (n > 13){
		for (LL i=1;i<=t[0];i++){
			if (t[i] <= n-13) Ans++;
		}
		base = n - 13;
		n = 13;
	}
	
	fac[0] = 1;
	for (LL i=1;i<=13;i++) fac[i] = 1LL * fac[i-1] * i;
	if (k > fac[n]){
		puts("-1");
		return 0;
	}
	k--;
	memset(used,false,sizeof(used));
	memset(rec,0,sizeof(rec));
	for (LL i=n;i>=1;i--){
		tmp = k / fac[i-1];
		k -= tmp*fac[i-1];
//		printf("%I64d\n",i);
		for (LL j=1;j<=n;j++){
			if (!used[j] && tmp==0){
				used[j] = true;
				rec[n - i + 1] = j;
				break;
//				printf("%I64d %I64d %d\n",n,i,1);
			} else
			if (!used[j]) tmp--;
		}
	}
	for (int i=1;i<=n;i++){
//		printf("%I64d %I64d\n",base+i,base+rec[i]);
		Ans += (check(base+i) && check(base+rec[i]));
	} 
	printf("%I64d\n",Ans);
}
