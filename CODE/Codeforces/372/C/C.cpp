#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long LL;
const LL maxn = 150005;
const LL maxm = 305;
struct P{
	LL a,b,t;
	bool operator <(const P &y) const{
		return t < y.t;
	}
}p[maxm];
LL dp[2][maxn];
LL n,m,d;
LL q[maxn],t,front,rear;
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&d);
	for (LL i=1;i<=m;i++){
		scanf("%I64d%I64d%I64d",&p[i].a,&p[i].b,&p[i].t);
	}
	sort(p+1,p+1+m);
	for (LL i=1;i<=n;i++)	dp[1][i] = p[1].b - abs(p[1].a - i);
//	for (LL i=1;i<=10;i++) printf("%I64d ",dp[1][i]);
	for (LL i=2;i<=m;i++){
//		printf("\n%I64d %I64d %I64d\n",p[i].a,p[i].b,p[i].t);
		LL pre = (i-1) & 1;
		LL now = i & 1;
		LL t = (p[i].t - p[i-1].t) * d;
		front = rear = 0;
		for (LL j=1;j<=n;j++){
			while (front < rear && dp[pre][j] >= dp[pre][q[rear-1]])rear--;
			q[rear++] = j;
			while (front < rear && q[front] < j - t) front++;
			dp[now][j] = dp[pre][q[front]] + p[i].b - abs(p[i].a-j);
		}
		front = rear = 0;
		for (LL j=n;j>=1;j--){
			while (front < rear && dp[pre][j] >= dp[pre][q[rear-1]])rear--;
			q[rear++] = j;
			while (front < rear && q[front] > j + t) front++;
			dp[now][j] = max(dp[now][j],dp[pre][q[front]] + p[i].b - abs(p[i].a-j));
		}
	}
	LL Ans = -0x3fffffff;
	for (LL i=1;i<=n;i++){
//		printf("%I64d %I64d\n",i,dp[m&1][i]);
		if (Ans < dp[m&1][i]) Ans = dp[m&1][i];
	}
	printf("%I64d\n",Ans);
}

/*
dp[i][j]=max(dp[i-1][k])-|a[i]-j|
max(1,j-t*d)<=k<=min(n,j+t*d)
*/
