#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 2009;
struct node{
	int p, q; LL d;
	bool operator < (const node &t){
		return d < t.d;
	}
} x[maxn*maxn];
LL a[maxn], b[maxn], n, m, cnt, L[2], R[2];
LL ans, S;

bool judge(node a, node b){
	if (a.p == b.p || a.p == b.q) return 1;
	if (a.q == b.p || a.q == b.q) return 1;
	return 0;
}

int main(){
	freopen("1.in","r",stdin);
	freopen("DL.out","w",stdout); 
	scanf("%I64d", &n);
	for (int i=1; i<=n; i++){
		scanf("%I64d", &a[i]);
		S += a[i];
	}
	scanf("%I64d", &m);
	for (int i=1; i<=m; i++){
		scanf("%I64d", &b[i]);
		S -= b[i];
	}
	ans = abs(S);
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			S += -2*a[i] + 2*b[j];
			if (abs(S) < ans){
				ans = abs(S); L[0] = i; R[0] = j;
			}
			S -= -2*a[i] + 2*b[j];
			x[++cnt].p = i; x[cnt].q = j; x[cnt].d = 2*a[i] - 2*b[j];
		}
	sort(x+1, x+cnt+1);
	
	for (int i=1, j=cnt; i<j; i++){
		S -= x[i].d;
		while (i<j&&S-x[j].d <= -ans) j--;
		for (int k=j; i<k&&S-x[k].d<ans; k--){
			if (judge(x[i], x[k])) continue;
			ans = abs(S - x[k].d);
			L[0] = x[i].p; R[0] = x[i].q;
			L[1] = x[k].p; R[1] = x[k].q;
		}
		S += x[i].d;
	}
	printf("%I64d\n", ans);
	if (!L[0]) puts("0");
	else if (!L[1]){
		puts("1");
		printf("%I64d %I64d\n", L[0], R[0]);
	}
	else{
		puts("2");
		printf("%I64d %I64d\n%I64d %I64d\n", L[0], R[0], L[1], R[1]);
	}
		
	return 0;
}
