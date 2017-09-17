#include<bits/stdc++.h>
long double best,ans;
double eps = 1e-9;
int last,now;
double p[105];
int n;
double f[2][105],g[2];
using namespace std;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		p[i]/=100;
	}
	ans = 0;
	int last = 0,now = 1;
	for (int i=1;i<=300000;i++){
		last^=1;now^=1;
		best = 0;
		int w;
		for (int j=1;j<=n;j++){
			if ((1-f[last][j])*p[j]/f[last][j] > best){
				best = (1-f[last][j])*p[j]/f[last][j];
				w = j;
			}
		}
		for (int j=1;j<=n;j++){
			if (j == w){
				f[now][j] = f[last][j] + (1-f[last][j]) * p[j];
			} else
				f[now][j] = f[last][j];
		}
		if (f[last][w] < eps){
			g[now] = 1;
			for (int j=1;j<=n;j++)
				g[now] = g[now]*f[now][j]; 
		} else
			g[now] = g[last] * f[now][w] / f[last][w];
		ans = ans + (g[now] - g[last]) * i;
	}
	printf("%.16lf\n",(double)ans);
	return 0;
}
