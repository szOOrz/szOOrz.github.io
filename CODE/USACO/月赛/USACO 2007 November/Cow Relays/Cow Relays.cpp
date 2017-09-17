#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::sort;
#define oo 10050*10050
struct Ma{
	int val[205][205];
}M,Matrix,Mans;
int hash[205],pos[1005];
int a[105],b[105],c[105],n,t,s,e;
int temp[205],cnt;
int min(int a,int b){if (a<b) return a; else return b;}
void build()
{
	memset(Matrix.val,-1,sizeof(Matrix.val));
	for (int i=1;i<=t;i++)
	{
//		printf("%d %d %d %d\n",a[i],b[i],pos[a[i]],pos[b[i]]);
		if (Matrix.val[pos[a[i]]][pos[b[i]]]==-1)
		{
			Matrix.val[pos[a[i]]][pos[b[i]]]=c[i];
			Matrix.val[pos[b[i]]][pos[a[i]]]=c[i];
		}
		else
		{
			Matrix.val[pos[a[i]]][pos[b[i]]]=min(Matrix.val[pos[a[i]]][pos[b[i]]],c[i]);
			Matrix.val[pos[b[i]]][pos[a[i]]]=min(Matrix.val[pos[b[i]]][pos[a[i]]],c[i]);
		}
	}
}
Ma calc(Ma a,Ma b)
{
	Ma c;
	memset(c.val,-1,sizeof(c.val)); 
	for (int i=1;i<=hash[0];i++)
	{
		for (int j=1;j<=hash[0];j++)
		{
			for (int k=1;k<=hash[0];k++)
			{
				if ((a.val[i][k]<0) || (b.val[k][j]<0)) continue;
				if (c.val[i][j]==-1) c.val[i][j]=a.val[i][k]+b.val[k][j]; else c.val[i][j]=min(c.val[i][j],a.val[i][k]+b.val[k][j]);
			}
		}
	}
	return c;
}
void power(int p)
{
	if (p==1)
	{
		M=Matrix;
		return ;
	}
	power(p>>1);
	Mans=calc(M,M);
	if (p & 1)
	{
		M=calc(Mans,Matrix);
	}
	else
	{
		M=Mans;
	}
}
bool cmp1(int a,int b){return a<b;} 
int main()
{
	scanf("%d%d%d%d",&n,&t,&s,&e);
	cnt=0;
	for (int i=1;i<=t;i++)
	{
		scanf("%d%d%d",&c[i],&a[i],&b[i]);
		temp[++cnt]=a[i];
		temp[++cnt]=b[i];
	}
	temp[++cnt]=s;
	temp[++cnt]=e;
	//for (int i=1;i<=cnt;i++) printf("%d ",temp[i]);
	//puts("");
	sort(temp+1,temp+1+cnt,cmp1);
	hash[0]=1;
	hash[1]=temp[1];
	pos[temp[1]]=1;
	for (int i=2;i<=cnt;i++)
		if (hash[hash[0]]!=temp[i])
		{
			hash[++hash[0]]=temp[i];
			pos[temp[i]]=hash[0];
		}
//	for (int i=1;i<=hash[0];i++) printf("%d %d\n",i,hash[i]);
//	puts("");
	build();
//	for (int i=1;i<=hash[0];i++)
//	{
//		for (int j=1;j<=hash[0];j++) printf("%16d  ",Matrix.val[i][j]);
//		puts("");
//	}
//	puts("");
	power(n);
//	for (int i=1;i<=hash[0];i++)
//	{
//		for (int j=1;j<=hash[0];j++) printf("%16d  ",M.val[i][j]);
//		puts("");
//	}
	printf("%d",M.val[pos[s]][pos[e]]);
	return 0;
}
