#include<iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
struct E{
	int from,to,dist,next;
};
const int oo=900000000;
const int maxm=100500;
const int maxn=1050;
E edge1[maxm],edge2[maxm];
bool mark[maxn];
int ans1[maxn],ans2[maxn];
int n,m,x;
int last_edge1[maxn],last_edge2[maxn];
int mdist;
int cnt;
int front,rear,queue[maxm*10];
void add_edge1(int x,int y,int z)
{
	edge1[cnt].from=x;
	edge1[cnt].to=y;
	edge1[cnt].dist=z;
	edge1[cnt].next=last_edge1[x];
	last_edge1[x]=cnt;
}//1是反向边 

void add_edge2(int x,int y,int z)
{
	edge2[cnt].from=x;
	edge2[cnt].to=y;
	edge2[cnt].dist=z;
	edge2[cnt].next=last_edge2[x];
	last_edge2[x]=cnt;
}//2是正向边 

void spfa1(int s)
{
	memset(mark,true,sizeof(mark));
	front=0;
	rear=1;
	queue[0]=s;
	ans1[s]=0;
	mark[s]=false;
	int u,v,e;
	while (front<rear)
	{
		u=queue[front];
		mark[u]=true;
		e=last_edge1[u];
		while (e!=-1)
		{
			v=edge1[e].to;
			if (ans1[v]>ans1[u]+edge1[e].dist)
			{
				ans1[v]=ans1[u]+edge1[e].dist;
				if (mark[v])
				{
					queue[rear]=v;
					mark[v]=false;
					rear++;
				}
			}
			e=edge1[e].next;
		}
		front++; 
	}
}

void spfa2(int s)
{
	memset(mark,true,sizeof(mark));
	front=0;
	rear=1;
	queue[0]=s;
	ans2[s]=0;
	mark[s]=false;
	int u,v,e;
	while (front<rear)
	{
		u=queue[front];
		mark[u]=true;
		e=last_edge2[u];
		while (e!=-1)
		{
			v=edge2[e].to;
			if (ans2[v]>ans2[u]+edge2[e].dist)
			{
				ans2[v]=ans2[u]+edge2[e].dist;
				if (mark[v])
				{
					queue[rear]=v;
					mark[v]=false;
					rear++;
				}
			}
			e=edge2[e].next;
		}
		front++;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for (int i=1;i<=n;i++)
	{
		last_edge1[i]=-1;
		last_edge2[i]=-1;
	}
	cnt=0;
	for (int i=1;i<=m;i++)
	{
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		add_edge1(b,a,t);//反向 
		add_edge2(a,b,t);
		cnt++;
	}
	for (int i=1;i<=n;i++) ans1[i]=oo;
	for (int i=1;i<=n;i++) ans2[i]=oo;
	spfa1(x);
	spfa2(x);
	mdist=0;
	for (int i=1;i<=n;i++)
		if (ans1[i]+ans2[i]>mdist) mdist=ans1[i]+ans2[i];
	printf("%d",mdist);
	return 0;
}
