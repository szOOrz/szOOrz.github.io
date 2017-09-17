#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9+7;
const int maxm = 1e5+10;
const int maxn = maxm * 2;
vector<int> f[maxn];
int dp[maxn],c[maxn];
int y[maxn],n,m,s[maxn],t[maxn];
#define lowbit(x) ((x & (-x)))
void Add(int x,int val){
	for (;x<=n;x+=lowbit(x))
		c[x] = (c[x] + val) % Mod; 
}
int get(int l,int r){
//	printf("Sum %d %d\n",l,r);
	int ans = 0;
	for (l--;l>0;l-=lowbit(l)) ans = ((ans - c[l]) % Mod + Mod) % Mod;
	for (;r>0;r-=lowbit(r)) ans = (ans + c[r]) % Mod;
//	printf("%d\n",ans);
	return ans;
}

int find(int x){
	int l = 1,r = y[0];
	while (l <= r){
		int mid = (l + r) >> 1;
		if (y[mid] < x){
			l = mid+1;
		} else
		if (y[mid] > x){
			r = mid-1;
		} else
			return mid;
	}
	return -1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&s[i],&t[i]);
		y[++y[0]] = s[i];
		y[++y[0]] = t[i];
	}
	sort(y+1,y+1+2*m);
	y[0] = 0;
	for (int i=1;i<=2*m;i++){
		if (i == 1 || y[i]!=y[i-1]){
			y[++y[0]] = y[i];
		}
	}
	for (int i=1;i<=m;i++){
		f[find(t[i])].push_back(find(s[i]));
	}
	if (find(0) == -1 || find(n) == -1){
		puts("0");
		return 0;
	}
	n = find(n);
	memset(dp,0,sizeof(dp));
	dp[1] = 1;
	Add(1,1);
	for (int i=2;i<=n;i++){
		dp[i] = 0;
		for (int j=0;j<(int)f[i].size();j++){
			dp[i] = (dp[i] + get(f[i][j],i)) % Mod;
		}
//		printf("%d %d\n",i,dp[i]);
		Add(i,dp[i]);
	}
	printf("%d\n",dp[n]);
}
