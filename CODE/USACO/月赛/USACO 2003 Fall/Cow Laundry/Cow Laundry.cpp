#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
int n,ans,k[1005],a[1005],b[1005];
int tree[4005];
void add(int nod,int left,int right,int x)
{
	if (left==right)
	{
		tree[nod]++;
		return ;
	}
	int mid=(left+right) >> 1;
	if (x<=mid) add(nod*2,left,mid,x); else add(nod*2+1,mid+1,right,x);
	tree[nod]=tree[nod*2]+tree[nod*2+1];
}
int query(int nod,int left,int right,int x,int y)
{
	//printf("%d %d %d %d\n",left,right,x,y);
	//getchar();
	if ((left==x) && (right==y))  return tree[nod];
	int mid=(left+right) >> 1;
	if ((left<=x) && (y<=mid)) return query(nod*2,left,mid,x,y); else 
	if ((mid+1<=x) && (y<=right)) return query(nod*2+1,mid+1,right,x,y); else 	 
	{
		return query(nod*2,left,mid,x,mid) + query(nod *2+1,mid+1,right,mid+1,y);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]); 
		k[a[i]]=i;	 
	}
	memset(tree,0,sizeof(tree));
	for (int i=1;i<=n;i++)
	{
		ans+=query(1,1,n,k[b[i]],n);
		add(1,1,n,k[b[i]]);
	}
	printf("%d",ans);
	return 0;
}
