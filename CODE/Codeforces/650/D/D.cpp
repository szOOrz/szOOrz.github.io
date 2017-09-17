#include<bits/stdc++.h>
const int maxn = 805050;
using namespace std;
struct Q{
	int a,b,id;
	bool operator < (const Q &t) const{
		return a < t.a;
	}
}q[maxn];
int y[maxn*2],Hash[maxn*2],h[maxn];
int n,m,Ans[maxn];
int dpl[maxn],dpr[maxn];
int find(int x){
	int l = 1,r = Hash[0];
	while (l < r){
		int mid = (l+r) >> 1;
		if (Hash[mid] > x) r = mid - 1; else
		if (Hash[mid] < x) l = mid + 1; else
						   return mid;
	}
	return l;
}
void init(){
	scanf("%d%d",&n,&m);
	y[0] = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		y[++y[0]] = h[i];
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&q[i].a,&q[i].b);
		q[i].id = i;
		y[++y[0]] = q[i].b;
	}
	sort(y+1,y+1+y[0]);
	for (int i=1;i<=y[0];i++)
		if (i == 1 || y[i]!=y[i-1])
			Hash[++Hash[0]] = y[i];
	for (int i=1;i<=n;i++) h[i] = find(h[i]);
	for (int i=1;i<=m;i++) q[i].b = find(q[i].b);
	sort(q+1,q+1+m);
}

int tree[maxn*4];//每个节点保存区间最大权的权
void build(int nod,int l,int r){
	if (l == r){
		tree[nod] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(nod*2,l,mid);
	build(nod*2+1,mid+1,r);
	tree[nod] = max(tree[nod*2],tree[nod*2+1]);
}
int query(int nod,int l,int r,int x,int y){
	if (y < x) return 0;
	if (l == x && y == r) return tree[nod];
	int mid = (l+r) >> 1;
	if ((l <= x) && (y <= mid))
		return query(nod*2,l,mid,x,y); else
	if ((mid+1<=x) && (y<=r))
		return query(nod*2+1,mid+1,r,x,y); else
	return max(query(nod*2,l,mid,x,mid),query(nod*2+1,mid+1,r,mid+1,y));
}
void Add(int nod,int l,int r,int x,int val){
	if (l == r){
		tree[nod] = max(tree[nod],val);
		return ;
	}
	int mid = (l+r) >> 1;
	if (x <= mid) Add(nod*2,l,mid,x,val); else Add(nod*2+1,mid+1,r,x,val);
	tree[nod] = max(tree[nod*2],tree[nod*2+1]);
}

void get_tree(){
	build(1,1,Hash[0]);
	int j = m;
	for (int i=n;i>=1;i--){
		while (j>=1 && q[j].a==i){
			Ans[q[j].id] = query(1,1,Hash[0],q[j].b+1,Hash[0]);
			j--;
		}
		dpl[i] = query(1,1,Hash[0],h[i]+1,Hash[0])+1;
		Add(1,1,Hash[0],h[i],dpl[i]);
	}

	build(1,1,Hash[0]);
	j = 1;
	for (int i=1;i<=n;i++){
		while (j<=m && q[j].a==i){
			Ans[q[j].id] += query(1,1,Hash[0],1,q[j].b-1) + 1;
			j++;
		}
		dpr[i] = query(1,1,Hash[0],1,h[i]-1)+1;
		Add(1,1,Hash[0],h[i],dpr[i]);
	}
}
int vis[maxn],Lis;
void solve(){
	memset(vis,0,sizeof(vis));
	Lis = 0;
	for (int i=1;i<=n;i++)Lis = max(Lis,dpl[i]);
	for (int i=1;i<=n;i++)
		if (dpl[i] + dpr[i] == Lis+1)
			vis[dpl[i]] ++;
	for (int i=1;i<=m;i++){
			Ans[q[i].id] = max(Ans[q[i].id],Lis-
			((dpl[q[i].a] + dpr[q[i].a] == Lis+1) && vis[dpl[q[i].a]] == 1)
			);
	}
}
void write(){
	for (int i=1;i<=m;i++){
		printf("%d\n",Ans[i]);
	}
}
int main(){
	init();
	get_tree();
	solve();
	write();
}
