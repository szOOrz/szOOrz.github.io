#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
struct L{
	int left,right,num;
};
const int maxq=50005;L line[maxq],a[maxq];int hash[maxq*2*3];
int point[maxq*2*3];int n,q;bool tree[maxq*2*4*3];void pushdown(int nod){	if (tree[nod])	{		tree[nod*2]=true;		tree[nod*2+1]=true;													}}bool query(int nod,int left,int right,int x,int y){	if ((left==x) && (right==y)) return tree[nod];	pushdown(nod);	int mid=(left+right) >> 1;	if ((left<=x) && (y<=mid)) return query(nod*2,left,mid,x,y);else	if ((mid+1<=x) && (y<=right)) return query(nod*2+1,mid+1,right,x,y);else	return (query(nod*2,left,mid,x,mid) && query(nod*2+1,mid+1,right,mid+1,y));}void cover(int nod,int left,int right,int x,int y){	if ((left==x) && (right==y)) 	{										tree[nod]=true;		return ;	}	pushdown(nod);	int mid=(left+right) >> 1;	if ((left<=x) && (y<=mid)) cover(nod*2,left,mid,x,y);else	if ((mid+1<=x) && (y<=right)) cover(nod*2+1,mid+1,right,x,y);else	{		cover(nod*2,left,mid,x,mid);		cover(nod*2+1,mid+1,right,mid+1,y);	}}bool cmp(L x,L y){return x.num>y.num;}int min(int x,int y){if (x<y) return x;else return y;}int max(int x,int y){if (x<y) return y;else return x;}bool check(int mid){	memset(tree,false,sizeof(tree));	memset(a,0,sizeof(a));	for (int i=1;i<=mid;i++) a[i]=line[i];	std::sort(a+1,a+1+mid,cmp); 	int i=1;	for (;i<=mid;)	{		int j=i;		int L=a[j].left;		int R=a[j].right;		int ML=L;		int MR=R;		while ((a[j+1].num==a[i].num) && (j+1<=mid))		{			if ((a[j+1].left>R) || (a[j+1].right<L))				return false;			L=max(L,a[j+1].left);
			R=min(R,a[j+1].right);
			ML=min(ML,a[j+1].left);
			MR=max(MR,a[j+1].right);
			j++;
		}
		if (query(1,1,hash[0],L,R)) return false;
		cover(1,1,hash[0],ML,MR);
		i=j+1;
	}
	return true;
}
int find(int x)
{
	int left=1,right=hash[0];
	while (left<=right)
	{
		int mid=(left+right) >> 1;
		if (hash[mid]>x) right=mid-1; else
		if (hash[mid]<x) left=mid+1; else
		return mid;	
	}
	return -1;
}
bool cmp_val(int x,int y){return x<y;}
void lsh()
{
	int cnt=0;
	for (int i=1;i<=q;i++)
	{
		point[++cnt]=line[i].left;
		point[++cnt]=line[i].left+1;
		point[++cnt]=line[i].right;
		point[++cnt]=line[i].right+1;
	}
	std::sort(point+1,point+1+cnt,cmp_val);
	hash[0]=0;
	int now=-1;
	for (int i=1;i<=cnt;i++)
	if (point[i]!=now)
	{
		hash[0]++;
		hash[hash[0]]=point[i];
		now=point[i];
	}
	for (int i=1;i<=q;i++)
	{
		line[i].left=find(line[i].left);
		line[i].right=find(line[i].right);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&line[i].left,&line[i].right,&line[i].num);
	}
	lsh();
	int lans=1,rans=q; 
	int ans=0;
	while (lans<=rans)
	{ 
		int mid=(lans+rans)>>1;
		if (check(mid)) //Ã»ÓÐÃ¬¶Ü
			lans=mid+1;
		else
		{
			ans=mid;
			rans=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}





















