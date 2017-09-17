/*
给定一个整数N，当N=12的时候是这样一幅图：
然后你要从最上面的H点出发，走一条道路，
这条道路中间不包括任何灰色三角形，最后
回到H。N是偶数，N<=10^6，问有多少情况，
答案对1e9+9取模

sol:
令f[i]表示陷进去i层的方案数，（强制不能从洞口经过）
于是有f[1] = 1, f[i] = 4 + 2 * f[i-1]
按照如图所示的阶段划分，令g[i]表示第i个蓝点到红点的方案数，
g[i] = 3*f[i-1] + g[i+1]*(f[i-1]+1) + 4
g[n/2] = 1
ans = 2 * (g[1] * g[1] + 2 * g[1] + 2)
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000009;
const int Mod = 1e9+9;
int n,f[maxn],g[maxn];
int main(){
	scanf("%d",&n);
	f[0] = 0;
	f[1] = 4;
	for (int i=2;i<=n/2-2;i++)
		f[i] = (4 + 2 * f[i-1]) % Mod;
	g[n/2] = 1;
	for (int i=n/2-1;i>=1;i--)
		g[i] = (3LL * f[i-1] + 1LL * g[i+1] * (f[i-1] + 1) + 4) % Mod;
	printf("%I64d\n",2LL * (1LL * g[1] * g[1] + 2 * g[1] + 2) % Mod);
	return 0;
}
