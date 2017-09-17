#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
const LL maxn = 3*1e5 + 100;
LL q,n,Time;
vector<int> son[maxn];
LL T1[maxn],T2[maxn],In[maxn],Out[maxn],deep[maxn];
void dfs(LL u){
	In[u] = ++Time;
	for (LL i=0;i<(int)son[u].size();i++){
		LL v = son[u][i];
		deep[v] = deep[u] + 1;
		dfs(v);
	}
	Out[u] = Time;
}
#define lowbit(x) ((x & (-x)))
void Add(LL a[],LL x,LL addval){
	LL Ans = 0;
	for (;x<=n;x+=lowbit(x)){
		a[x]=((a[x]+addval) % Mod + Mod) % Mod;
	}
}
LL Get(LL a[],LL x){
	LL Ans = 0;
	for (;x>0;x-=lowbit(x)){
		Ans = ((Ans + a[x]) % Mod + Mod) % Mod;
	}
	return Ans;
}
int main(){
	scanf("%I64d",&n);
	for (LL i=2;i<=n;i++){
		LL f;
		scanf("%I64d",&f);
		son[f].push_back(i);
	}
	deep[1] = 0;
	Time = 0;
	dfs(1);
//	for (LL i=1;i<=n;i++){
//		printf("(%I64d,%I64d)\n",In[i],Out[i]);
//	}
	scanf("%I64d",&q);
	while (q--){
		LL type,v,x,k;
		scanf("%I64d",&type);
		if (type == 1){
			scanf("%I64d%I64d%I64d",&v,&x,&k);
			Add(T1,Out[v]+1,((-x-k*deep[v]) % Mod + Mod) % Mod);
			Add(T1,In[v],(+x+k*deep[v]) % Mod);
			Add(T2,Out[v]+1,((-k) % Mod + Mod) % Mod);
			Add(T2,In[v],k % Mod);
		}else{
			scanf("%I64d",&v);
			printf("%I64d\n",((Get(T1,In[v])-Get(T2,In[v])*deep[v]) % Mod + Mod) % Mod);
		}
//		puts("TREE!");
//		for (LL i=1;i<=n;i++) printf("%I64d ",Get(T1,In[i]));
//		puts("");
	}
}
