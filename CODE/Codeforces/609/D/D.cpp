#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL maxn = 2*1e5+100;
struct T{
	LL val,rank;
	bool operator < (const T &t) const{
		return val < t.val;
	}
}w[3][maxn],pre[3][maxn];
LL num[3],sum[3][maxn];
LL n,m,k,s;
LL l1,l2,x;
bool check(LL mid){
	for (LL i=0;i<=num[1];i++){
		LL j = k - i;
		if (j < 0) break;
		if (j > num[2]) continue;
		LL Need1 = sum[1][i];
		LL Need2 = sum[2][j];
//		printf("%I64d %I64d\n",i,j);
//		printf("Need1=%I64d Need2=%I64d\n",Need1,Need2);
		if (Need1 * pre[1][mid].val + Need2 * pre[2][mid].val <= s){
			l1 = i;
			l2 = j;
			return true;
		}
	}
	return false;
}//在第mid天之前及之前，能否完成条件 
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&s);
	pre[1][0].val = 0x3fffffff;
	pre[2][0].val = 0x3fffffff;
	for (LL t=1;t<=2;t++){
		for (LL i=1;i<=n;i++){
			scanf("%I64d",&x);
			if (x < pre[t][i-1].val){
				pre[t][i].val = x;
				pre[t][i].rank = i;
			} else
				pre[t][i] = pre[t][i-1];
		}
	}
	for (LL i=1;i<=m;i++){
		LL type;
		scanf("%I64d%I64d",&type,&x);
		num[type]++;
		w[type][num[type]].val = x;
		w[type][num[type]].rank = i;
	}
	for (LL t=1;t<=2;t++){
		sort(w[t]+1,w[t]+num[t]+1);
		sum[t][0] = 0;
		for (LL i=1;i<=num[t];i++){
			sum[t][i] = sum[t][i-1] + w[t][i].val;
//			printf("SUM : %I64d %I64d\n",i,sum[t][i]);
		}
	}
	LL L,R,Ans;
	L = 1,R = n;
	Ans = -1;
	while (L <= R){
		LL mid =(L + R) >> 1;
		if (check(mid)){
			Ans = mid;
			R = mid-1;
		} else
			L = mid+1;
	}
	printf("%I64d\n",Ans);
	if (Ans!=-1){
		for (LL i=1;i<=l1;i++){
			printf("%I64d %I64d\n",w[1][i].rank,pre[1][Ans].rank);
		}
		for (LL i=1;i<=l2;i++){
			printf("%I64d %I64d\n",w[2][i].rank,pre[2][Ans].rank);
		}
	}
	return 0;
}
