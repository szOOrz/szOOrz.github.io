#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long double LD;
typedef pair<int,int> point;

const int maxn = 100009;
const LD PI = acos(-1);
int rk[maxn], n, ans1, ans2;
point p; LD a[maxn], t, best, now; 

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d%d", &p.x, &p.y);
		a[i] = atan2(p.x, p.y); rk[i] = i;
	}
	sort(rk+1, rk+n+1, cmp);
	rk[n+1] = rk[1];
	ans1 = rk[1]; ans2 = rk[2];
	best = a[ans2] - a[ans1];
	if (best < 0) best += 2*PI;
	for (int i=2; i<=n; i++){
		now = a[rk[i+1]] - a[rk[i]];
		if (now < 0) now += 2*PI;
		if (now < best){
			best = now;
			ans1 = rk[i]; ans2 = rk[i+1];
		}
	}
	printf("%d %d\n", ans1, ans2);		
	return 0;
}
