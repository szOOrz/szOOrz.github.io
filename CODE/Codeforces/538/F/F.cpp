#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
const int maxn = 2e5+100;
struct A{
	int v,id;
	bool operator <(const A &x) const{
		return v < x.v || v == x.v && id < x.id;
	}
}a[maxn];
#define lowbit(x) ((x & (-x)))
int c[maxn],Ans[maxn];
int n,k;
void Add(int x){
	for (;x<=n;x+=lowbit(x)){
		c[x]++;
	}
}
int get(int x){
	int ans = 0;
	for (;x>0;x-=lowbit(x))
		ans+=c[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		a[i].id = i;
	}
	std::sort(a+1,a+1+n);
	memset(c,0,sizeof(c));
	memset(Ans,0,sizeof(Ans));
	for (int i=1;i<=n;i++){
		Add(a[i].id);
		for (int k=1;k<=n;k++){
			int st,ed;
			st = (a[i].id-1) * k + 2;
			ed = std::min(n,a[i].id * k + 1);
			if (st > n) break;
			Ans[k] += get(ed) - get(st-1);
		}
	}
	for (int i=1;i<=n-1;i++){
		printf("%d ",Ans[i]);
	}
	return 0;
}
/*
考虑把所有数排序，然后逐个加入到树状数组原来的位置里面。
同时计算它作为k（枚举）叉堆的父亲的时候其子节点的贡献。 
*/
