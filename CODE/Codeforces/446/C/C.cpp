#include<bits/stdc++.h> 
using namespace std;
#define lc (nod << 1) 
#define rc (nod << 1 | 1)
#define mid ((l+r) >> 1)
const int maxn = 300009;
const int Mod = 1000000009;
const int base = 276601605;
const int q1 = 691504013;
const int q2 = 308495997;
int Pow1[maxn],Pow2[maxn],T[maxn<<2],lazy1[maxn<<2],lazy2[maxn<<2];
int n,m,a,b,c,s[maxn];

void calc(int nod,int l,int r,int a,int b){
	T[nod] = ((T[nod] + 1LL * a * (Pow1[r-l+3] - Pow1[2])
				      - 1LL * b * (Pow2[r-l+3] - Pow2[2]) % Mod) % Mod + Mod) % Mod;
	lazy1[nod] = (lazy1[nod] + a) % Mod;
	lazy2[nod] = (lazy2[nod] + b) % Mod;
}
void pushdown(int nod,int l,int r,int &a,int &b){
	calc(lc,l,mid,a,b);
	calc(rc,mid+1,r,1LL*a*Pow1[mid-l+1]%Mod,1LL*b*Pow2[mid-l+1]%Mod);
}
void update(int nod,int l,int r,int x,int y,int a,int b){
	if (l == x && y == r){
		calc(nod,l,r,a,b);
		return;
	}
 	if (y<=mid) update(lc,l,mid,x,y,a,b); else
 	if (mid+1<=x) update(rc,mid+1,r,x,y,a,b); else{
 		update(lc,l,mid,x,mid,a,b);
 		update(rc,mid+1,r,mid+1,y,1LL * a * Pow1[mid-x+1] % Mod,1LL * b * Pow2[mid-x+1] % Mod);
 	}
 	T[nod] =(T[lc]+T[rc]) % Mod;
}
int query(int nod,int l,int r,int x,int y){
	if (l == x && r == y) return T[nod];
	pushdown(nod,l,r,lazy1[nod],lazy2[nod]);
	if (y <= mid) return query(lc,l,mid,x,y); else
	if (mid+1<=x) return query(rc,mid+1,r,x,y); else
	return query(lc,l,mid,x,mid)+query(rc,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a);
		s[i] = (s[i-1] + a) % Mod;
	} 
	Pow1[0] = 1;
	for (int i=1;i<maxn;i++) Pow1[i] = 1LL * Pow1[i-1] * q1 % Mod;
	Pow2[0] = 1;
	for (int i=1;i<maxn;i++) Pow2[i] = 1LL * Pow2[i-1] * q2 % Mod;
	while (m--){
		scanf("%d%d%d",&c,&a,&b);
		if (c == 1)update(1,1,n,a,b,1,1); else
		printf("%d\n",((s[b] - s[a-1]) % Mod) + (1LL * base * query(1,1,n,a,b) % Mod + Mod) % Mod);
	}
	return 0;	
}
