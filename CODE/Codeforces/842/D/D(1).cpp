#include<bits/stdc++.h>
using namespace std;

const int maxn = 300009;
int T[maxn*20][2], f[maxn*20], mark[maxn*20];
int n, m, a, x, t, size = 1;

void insert(int x){
	int o = 1; 
	for (int i=19; i>=0; i--){
		if (!T[o][x>>i&1]) T[o][x>>i&1] = ++size;
		o = T[o][x>>i&1]; 
	}
	if (!mark[o]){
		mark[o] = 1; o = 1;
		for (int i=19; i>=0; i--){
			o = T[o][x>>i&1];
			f[o]++;
		}
	}
}

int query(int x){
	int res = 0, o = 1, tmp;
	for (int i=19; i>=0; i--){
		tmp = x>>i&1;
		if (f[T[o][tmp]] == (1 << i)) { o = T[o][tmp^1]; res += 1 << i; }
		else o = T[o][tmp];
	}
	return res;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++){
		scanf("%d", &a);
		insert(a);
	}
	for (int i=1; i<=m; i++){
		scanf("%d", &t); x ^= t;
		printf("%d\n", query(x));
	}
	return 0;
}