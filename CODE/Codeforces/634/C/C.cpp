#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn = 200009;
int c1[maxn], c2[maxn], num[maxn];
int n, K, a, b, Q, t, x, y;

void update(int c[], int x, int y){ 
	for (; x<=n; x+=lowbit(x)) c[x] += y;
}

int query(int c[], int x, int y){
	int res = 0;
	for (; y; y-=lowbit(y)) res += c[y];
	for (--x; x; x-=lowbit(x)) res -= c[x];
	return res;
}

int main(){
	scanf("%d%d%d%d%d", &n, &K, &a, &b, &Q);
	while (Q--){
		scanf("%d%d", &t, &x);
		if (t == 1){
			scanf("%d", &y);
			if (num[x] + y <= b){
				update(c1, x, y); update(c2, x, y);
			}
			else if (num[x] + y <= a){
				if (num[x] < b) update(c1, x, b-num[x]);
				update(c2, x, y);
			}
			else{
				if (num[x] < b) update(c1, x, b-num[x]);
				if (num[x] < a) update(c2, x, a-num[x]);
			}
			num[x] += y;
		}
		else
			printf("%d\n", query(c1, 1, x-1) + query(c2, x+K, n));
	}
	return 0;
}
