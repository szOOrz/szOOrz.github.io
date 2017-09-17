#include <iostream>
#include <cstdio>
#include <cstring>
struct L
{
	int left,right;
};
int max(int a,int b){if (a<b) return b;else return a;}
int min(int a,int b){if (a>b) return b;else return a;}
int f[10050];
L line[20050];
int n,p,tot,ans;
int x,y,k;
int main()
{
	scanf("%d%d",&n,&p);
	for (int i=1;i<=p;i++) scanf("%d%d",&line[i].left,&line[i].right);
	//枚举每个可能的断点i 
	//然后扫描每一条线j 
	//对于先left~right，如果两者有小于i的，先加上n，然后将f[min(left,right)]+1，f[max(left,right)+1]-1 
	//就是类似线段覆盖的样子。判断没有被覆盖过的点的个数 
	//然后扫描一遍n，对前缀和为0的，tot加一，最后tot求得的是最大断点。
	for (int i=1;i<=n;i++) 
	{
		memset(f,0,sizeof(f));
		for (int j=1;j<=p;j++)
		{
			x=line[j].left;
			y=line[j].right;
			if (x<=i) x+=n;
			if (y<=i) y+=n;
			f[min(x,y)]++;
			f[max(x,y)]--;
		}
		k=0;
		tot=0;
		//for (int j=i+1;j<=i+n;j++) printf("%d ",f[j]);printf("\n");
		for (int j=i+1;j<=i+n;j++)
		{
			k+=f[j];
			if (k==0) tot++;
		}
		//tot++;
		//printf("%d\n",tot);
		if (tot>ans) ans=tot;
	}
	printf("%d",n-ans);
	return 0;
}
