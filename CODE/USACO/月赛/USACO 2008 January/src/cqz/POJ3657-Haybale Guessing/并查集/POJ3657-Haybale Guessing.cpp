#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
struct L{
	int left,right,num;
};
const int maxq=50005;
L line[maxq],a[maxq];
int hash[maxq*2*3];
int point[maxq*2*3];
int n,q;
int father[maxq*2*3];
bool cmp(L x,L y){return x.num>y.num;}
int getfather(int x)
{
	if (x==father[x]) return x;
	father[x]=getfather(father[x]);
	return father[x];
}
int min(int x,int y){if (x<y) return x;else return y;}
int max(int x,int y){if (x<y) return y;else return x;}
bool check(int mid)
{
	memset(a,0,sizeof(a));
	for (int i=1;i<=hash[0];i++)
//	{
	father[i]=i;
//	printf("%d %d\n",i,father[i]);
//	}
//	printf("\n");
	for (int i=1;i<=mid;i++) a[i]=line[i];
	std::sort(a+1,a+1+mid,cmp); 
	int i=1;
	for (;i<=mid;)
	{
		int j=i;
		int L=a[j].left;
		int R=a[j].right;
		int ML=L;
		int MR=R;
		while ((a[j+1].num==a[i].num) && (j+1<=mid))
		{
			if ((a[j+1].left>R) || (a[j+1].right<L))	return false;
			L=max(L,a[j+1].left);
			R=min(R,a[j+1].right);
			ML=min(ML,a[j+1].left);
			MR=max(MR,a[j+1].right);
			j++;
		}
		if (L>R) return false;
		if (L>getfather(R)) return false;
		while (ML<=MR)
		{
			if (getfather(MR)==MR)
			{
				father[MR]=getfather(ML-1);
				MR--;
			}
			else
			{
				MR=getfather(MR);
			}
		}
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
//		printf("%d %d %d %d\n",lans,rans,mid,check(mid));
		if (check(mid)) //Ã»ÓĞÃ¬¶Ü
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
