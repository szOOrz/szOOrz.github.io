#include<iostream> 
#include<algorithm>

struct E{
	int x,y,dist;
};
E edge[100500];
int n,m,a,b,c;
int k,ans,xx,yy;
int father[1050];
bool cmp(E x,E y)
{
	return x.dist>y.dist;
}
int getfather(int x)
{
	if (father[x]==x) return x;
	father[x]=getfather(father[x]);
	return father[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		edge[i].x=a;
		edge[i].y=b;
		edge[i].dist=c;
	}
	std::sort(edge+1,edge+1+m,cmp);
	for (int i=1;i<=n;i++) father[i]=i;
	k=0;
	ans=0;
	for (int i=1;i<=m;i++)
	{
		xx=getfather(edge[i].x);
		yy=getfather(edge[i].y);
		if (xx!=yy)
		{
			ans+=edge[i].dist;
			father[xx]=yy;
			k++;
		}
		if (k==(n-1)) break;
	}
	if (k!=(n-1)) printf("-1\n"); else printf("%d",ans);
	return 0;
}
