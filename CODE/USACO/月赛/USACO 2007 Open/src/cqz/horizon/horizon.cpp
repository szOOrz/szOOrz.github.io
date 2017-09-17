#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
struct T{
	ll height;
};
T tree[40005*2*4];;
ll pt[40005*2],hash[40005*2];
ll n,x[40005],y[40005],z[40005];
ll max(ll x,ll y){if (x<y) return y;else return x;}
void pushdown(ll nod)
{
	if (tree[nod].height!=0)
	{
		tree[nod*2].height=max(tree[nod*2].height,tree[nod].height);
		tree[nod*2+1].height=max(tree[nod*2+1].height,tree[nod].height);
		tree[nod].height=0;
	} 
}
void add(ll nod,ll left,ll right,ll x,ll y,ll addval)
{
	if ((left==x) && (right==y))
	{
		tree[nod].height=max(tree[nod].height,addval);
		return ;
	}
	pushdown(nod);
	ll mid=(left+right) >> 1;
	if ((left<=x) && (y<=mid)) add(nod*2,left,mid,x,y,addval);else
	if ((mid<=x) && (y<=right)) add(nod*2+1,mid,right,x,y,addval);else	
	{
		add(nod*2,left,mid,x,mid,addval);
		add(nod*2+1,mid,right,mid,y,addval);
	}
}
ll query(ll nod,ll left,ll right)
{
	if (left+1==right)
	{
		return tree[nod].height*(hash[right]-hash[left]);
	} 
	pushdown(nod);
	ll mid=(left+right) >> 1;
	return query(nod*2,left,mid)+query(nod*2+1,mid,right);
} 
ll find(ll x)
{
	ll left=1,right=hash[0];
	while (left<=right)
	{
		ll mid=(left+right) >> 1;
		if (hash[mid]<x) left=mid+1; else
		if (hash[mid]>x) right=mid-1; else return mid;
	}
	return -1;
} 
int main()
{
//	freopen("horizon.in","r",stdin);
//	freopen("horizon.out","w",stdout);	
	scanf("%lld",&n);
	ll cnt=0; 
	for (ll i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
		pt[++cnt]=x[i];
		pt[++cnt]=y[i];
	}
	std::sort(pt+1,pt+1+cnt);
	hash[0]=1;
	hash[1]=pt[1];
	for (ll i=2;i<=cnt;i++)if (pt[i]!=hash[hash[0]])hash[++hash[0]]=pt[i];
	//ÀëÉ¢»¯
	memset(tree,0,sizeof(tree));
	for (ll i=1;i<=n;i++)
	{
		add(1,1,hash[0],find(x[i]),find(y[i]),z[i]);
	}
	printf("%lld",query(1,1,hash[0]));
	return 0;
} 
