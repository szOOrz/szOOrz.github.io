#include<bits/stdc++.h> 
using namespace std;
const int maxn = 200500;
const int maxai = 1000000;
const int Mod = 1e9+7;
//----------------- init to get pimre------------ 
typedef long long LL;
vector<int> pri[maxai + 10];
bool Isprime[maxai + 10];
int prime[maxai];
void get_prime(){
	for (int i=0;i<=maxai;i++) pri[i].clear();
	memset(Isprime,true,sizeof(Isprime));
	Isprime[0] = Isprime[1] = false;
	prime[0] = 0;
	for (int i=2;i<=maxai;i++){
		if (Isprime[i]){
			prime[++prime[0]] = i;
			pri[i] .push_back(i);
		}
		for (int j=1;j<=prime[0];j++){
			if (i * prime[j] > maxai) break;
			int u = i * prime[j];
			Isprime[u] = false;
			for (int k=0;k<pri[i].size();k++){
				pri[u] . push_back(pri[i][k]);
			}
			if (i % prime[j] == 0) break;
			pri[u] . push_back(prime[j]);
		}
	}
}
//-----------------------------------------
//---------------------to get inv
LL Pow(LL a,LL b){
	LL Ans = 1;
	for (;b;b>>=1,a=a*a % Mod){
		if (b & 1) Ans = Ans * a % Mod;
	}
	return Ans;
}
LL inv(LL x){
	return Pow(x % Mod,Mod-2);
}
void init(){
	get_prime();
}
//-----------------------------------Slove-------------
struct Ques{
	int l,r,id;
	bool operator < (const Ques &x) const{
		return r < x.r;
	}
}q[maxn]; 
LL result[maxn + 10];
int n,Q;
//---------------------TREE-----------------------
LL pre[maxn];
LL c[maxn];
int last[maxai + 10];
#define lowbit(x) (x & (-x))
void change(int x,LL val){
	for (;x<=n;x+=lowbit(x)){
		c[x] = (c[x] * val) % Mod;
	}
}
LL Get(int x){
	LL Ans = 1;
	for (;x>0;x-=lowbit(x)) Ans = Ans * c[x] % Mod;
	return Ans;
}
//---------------------TREE-----------------------
LL a[maxn];
void solve(){
	for (int i=1;i<=n;i++) c[i] = 1;
	memset(last,-1,sizeof(last));
	int j = 1;
	for (int i=1;i<=n;i++){
		for (int k=0;k<pri[a[i]].size();k++){
			int p = pri[a[i]][k];
			if (last[p] != -1){
				change(last[p],p * inv(p-1) % Mod);
			}
			change(i,(p-1) * inv(p) % Mod);
			last[p] = i;
		}
		
		for (;j<=Q && q[j].r==i;j++){
			LL Ans = pre[q[j].r] * inv(pre[q[j].l-1])% Mod * Get(q[j].r) % Mod * inv(Get(q[j].l - 1)) % Mod;
			result[q[j].id] = Ans;
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	pre[0] = 1;
	for (int i=1;i<=n;i++) pre[i] = (pre[i-1] * a[i]) % Mod;
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i] . id = i;
	}
	sort(q+1,q+1+Q);
	solve();
	for(int i=1;i<=Q;i++){
		printf("%I64d\n",result[i]);
	}
}
