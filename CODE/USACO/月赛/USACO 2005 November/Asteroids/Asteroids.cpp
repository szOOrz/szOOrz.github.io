/*匈牙利算法模板题：最小点覆盖数=最大匹配*/
#include<cstdio>
#include<cmath>
#include<cstring>
#define M 10050
#define N 505
struct E{
	int to,nexte;
}edge[M];
int last_edge[N],flag[N];
bool mark[N];
int n,k,num_edge,ans;
void add_edge(int a,int b)
{
	num_edge++;
	edge[num_edge].to=b;
	edge[num_edge].nexte=last_edge[a];
	last_edge[a]=num_edge;
}
bool find(int x)
{
	if (!x) return true;
	int e=last_edge[x];
	while (e)
	{
		int v=edge[e].to;
		if (!mark[v]) 
		{
			mark[v]=true;
		//	printf("%d %d %d %d\n",e,x,v,flag[v]);
			if (find(flag[v]))
			{
				flag[v]=x;
				return true;
			}
		}
		e=edge[e].nexte;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&k);
	memset(last_edge,0,sizeof(last_edge));
	num_edge=0;
	int a,b;
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	//for (int i=1;i<=k;i++)
	//{
		//printf("%d %d %d\n",i,edge[i].to,edge[i].nexte);
	//}
	memset(flag,0,sizeof(flag));
	ans=0;
	for (int i=1;i<=n;i++)
	{
		memset(mark,0,sizeof(mark));
		if (find(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
