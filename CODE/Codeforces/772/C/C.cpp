#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
const int maxn = 200500;
int dp[maxn],num[maxn],x,n,m,u,v,Ans;
int from[maxn],last;
bool flag[maxn];
int gcd(int a,int b){
	if (!b) return a; else return gcd(b,a%b);
}
int Pow(int a,int b,int Mod){
	int ans = 1;
	for (;b;b>>=1,a=1LL*a % Mod){
		if (b & 1) ans = 1LL * ans * a % Mod;
	}
	return ans;
}
typedef long long LL;
void exgcd(LL a,LL b,LL &x,LL &y){
	if (!b){
		x = 1.0;
		y = 0.0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
LL inv(LL a,LL P){
/*
ax == 1 (Mod P)
ax + py = 1
*/
	LL x,y;
	exgcd(a,P,x,y);
	return 1LL * (x % P + P) % P;
}
using namespace std;
vector<int> g[maxn];
int main(){
	scanf("%d%d",&n,&m);
	memset(flag,true,sizeof(flag));
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		flag[x] = false;
	}
	for (int i=0;i<m;i++) g[i].clear();
	memset(num,0,sizeof(num));
	for (int i=1;i<m;i++){
		if (flag[i]){
//			if (i == 448)printf("\n%d %d\n",i,gcd(i,m));
			g[gcd(i,m)].push_back(i);
			num[gcd(i,m)]++;
		}
	}
	if (flag[0]){
		num[0] = 1;
		g[0].push_back(0);
	}
/*	for (int i=0;i<m;i++){
		printf("%d:",i);
		for (int j=0;j<g[i].size();j++) printf("%d ",g[i][j]);
		puts("");
	}
*/	
	memset(from,-1,sizeof(from));
	for (int i=1;i<m;i++) dp[i] = num[i];
	last = -1;
	Ans = 0;
	for (int i=1;i<m;i++){
		if (m % i != 0) continue;
		u = i;
		if (dp[u] >= Ans){
			last = u;
			Ans = dp[u];
		}
//		printf("%d %d\n",u,dp[u]);
		for (int j=2;u*j<m;j++){
			v = u*j;
			if (m % v == 0){
				if (dp[u] + num[v] > dp[v]){
					dp[v] = dp[u] + num[v];
					from[v] = u;
				}
			}
		}
	}
	printf("%d\n",Ans+flag[0]);
	int tmp[maxn];
	tmp[0] = 0;
	if (flag[0]){
		tmp[++tmp[0]] = 0;
	}
//	printf("%d\n",last);
	for (int i=last;~i;i=from[i]){
		//printf("%d--->",i);
		for (int j=(int)g[i].size()-1;j>=0;j--)
			tmp[++tmp[0]] = g[i][j]/*,printf("%5d",g[i][j]);*/;
		//puts("");
		//puts("");
	}
//	Minid = tmp[0];
//	for (int i=tmp[0]-1;i>=1;i--){
//		if (tmp[Minid] < tmp[i]) 
//	}
	printf("%d",tmp[tmp[0]]);	
	for (int i=tmp[0]-1;i>=1;i--){
//		printf(" %d",tmp[i]);
		int a,b;
		a = tmp[i+1];b = tmp[i];
		int d = gcd(gcd(a,b),m);
		a/=d;
		b/=d;
		x = b * inv(a,m/d) % m;
		printf(" %d",x);
	}
	return 0;
}
/*

a = 2
b = 14
gcd(a,b) = 2
m / gcd(a,b) = 360
inv(1,360) = 1
ax == b (mod P)
…Ëgcd(a,b) = d
a/d *x == b/d (mod P) 
*/
