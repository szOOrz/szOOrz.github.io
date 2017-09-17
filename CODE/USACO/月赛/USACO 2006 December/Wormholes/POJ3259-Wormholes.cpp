#include <iostream> 
#include <cstdio>
#include <cstring>
struct E{
	int from,to,dist,next;
};
const int oo=999999999;
E edge[3505+3505+205];
int queue[1050*550],front,rear;
int flag[555],ans[555];
bool mark[555];
int n,m,w,cnt;
int last_edge[555];
void add_edge(int x,int y,int z)
{
	edge[cnt].from=x;
	edge[cnt].to=y;
	edge[cnt].next=last_edge[x];
	edge[cnt].dist=z;
	last_edge[x]=cnt;
	cnt++;
}
bool spfa(int s)
{
	memset(flag,0,sizeof(flag));
	memset(mark,true,sizeof(mark));
	front=0;
	rear=1;
	queue[0]=s;
	ans[s]=0;
	mark[s]=false;
	flag[s]=1;
	while (front<rear)
	{
		int u=queue[front];
		mark[u]=true;
		int e=last_edge[u];
		while (e!=-1)
		{
			int v=edge[e].to;
			if ((ans[u]+edge[e].dist)<ans[v])
			{
				ans[v]=edge[e].dist+ans[u];
				if (mark[v]) 
				{
					queue[rear]=v;
					flag[v]++;
					mark[v]=false;
					if (flag[v]>=n) return true;
					rear++;
				}
			}
			e=edge[e].next;
		}
		front++;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&w);
		for (int i=1;i<=n;i++) last_edge[i]=-1;
		cnt=0;
		int x,y,z;
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add_edge(x,y,z);
			add_edge(y,x,z);
		}
		for (int i=1;i<=w;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			add_edge(x,y,-z);
		}
		for (int i=1;i<=n;i++) ans[i]=oo;
		bool found=false;
		for (int i=1;i<=n;i++)
			if (ans[i]==oo)
			{
				if (spfa(i))
				{
					printf("YES\n");
					found=true;
					break;
				}
			}
		if (!found)	printf("NO\n");
	}
	return 0;
}
