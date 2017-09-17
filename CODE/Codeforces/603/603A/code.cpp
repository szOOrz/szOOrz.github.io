#include<bits/stdc++.h>
using namespace std;

const int maxn = 100009;
int f[maxn], g[maxn], h[maxn], n;
char s[maxn];
int main(){
	scanf("%d", &n);
	scanf("%s", s+1); s[0] = '#';
	f[0] = 0; g[0] = -1e9; h[0] = -1e9;
	for (int i=1; i<=n; i++){
		f[i] = f[i-1] + (s[i-1] != s[i]);
		g[i] = max(f[i-1] + (s[i-1] == s[i]), g[i-1] + (s[i-1] != s[i]));
		h[i] = max(g[i-1] + (s[i-1] == s[i]), h[i-1] + (s[i-1] != s[i]));
	}
	printf("%d\n", max(f[n], max(g[n], h[n])));
	return 0;
}
