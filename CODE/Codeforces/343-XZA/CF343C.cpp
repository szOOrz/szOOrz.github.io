/*
一条水平的磁道上有n个磁头和m个待扫描的点，
磁头可以左右互不干扰的移动去扫描点，每秒
移动一个单位，求最少要花多少时间。

显然二分答案+贪心。
注意贪心时，一开始可以往左，或往右。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100009;
LL a[maxn], b[maxn];
LL n, m, l = 0, r = 2e10, mid;

bool check(LL limit){
	LL p = 1, s, p1;
	for (int i=1; i<=n&&p<=m; i++){
		//printf("%d %I64d\n", i, p);
		if (a[i] - b[p] > limit) return false;
		p1 = s = p;
		while (p <= m && abs(a[i] - b[s])
			+ abs(b[s] - b[p]) <= limit) p++;
		while (p1 <= m && abs(a[i] - b[p1])
			+ abs(b[p1] - b[s]) <= limit) p1++;
		p = max(p1, p);
	}
	return p > m;
}

int main(){
	scanf("%I64d%I64d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%I64d", &a[i]);
	for (int i=1; i<=m; i++) scanf("%I64d", &b[i]);
	sort(a+1, a+n+1); sort(b+1, b+m+1);
	while (l < r){
		mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}