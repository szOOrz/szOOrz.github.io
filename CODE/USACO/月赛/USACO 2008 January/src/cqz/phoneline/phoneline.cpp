/*
有N个点和M条边。你可以将其中K条边的权值变成0。你要找一条1到N的路径，要使得路径上的最大值最小。
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
struct E{
	int from,to,dist,next;
};
E edge[22222];
int n,p,k;
int front,rear;
int Dist[1005];
int queue[999999],point[1005];
bool flag[1005];
int cnt;
bool spfa(int mx)
{
	for (int i=1;i<=n;i++) Dist[i]=k+1;
	Dist[1]=0;
	front=0;rear=1;
	queue[0]=1;
	memset(flag,true,sizeof(flag));
	flag[1]=false;
	while (front<rear)
	{
		int x=queue[front];
		int e=point[x];
		while (e!=-1)
		{
			if (edge[e].dist>mx)
			{
				if (Dist[x]+1<Dist[edge[e].to])
				{
					Dist[edge[e].to]=Dist[x]+1;
					if (flag[edge[e].to])
					{
						queue[rear]=edge[e].to;
						rear++;
						flag[edge[e].to]=false;
					}
				}	
			}
			else
			{
				if (Dist[x]<Dist[edge[e].to])
				{
					Dist[edge[e].to]=Dist[x];
					if (flag[edge[e].to])
					{
						queue[rear]=edge[e].to;
						rear++;
						flag[edge[e].to]=false;
					}
				}
			}
			e=edge[e].next;
		}
		flag[x]=true;
		front++;
	}
	return (Dist[n]<=k);
}
void add_edge(int x,int y,int z)
{
	edge[cnt].from=x;
	edge[cnt].to=y;
	edge[cnt].dist=z;
	edge[cnt].next=point[x];
	point[x]=cnt;
	cnt++;
} 
int main()
{
	//freopen("phoneline.in","r",stdin);
	//freopen("phoneline.out","w",stdout); 
	scanf("%d%d%d",&n,&p,&k);
	cnt=0;
	for (int i=1;i<=n;i++) point[i]=-1;
	int x,y,z;
	for (int i=1;i<=p;i++) 
	{
		scanf("%d%d%d",&x,&y,&z);
		 add_edge(x,y,z);
		 add_edge(y,x,z);
	} 
	/*
	二分答案，然后用spfa验证是否能够到达，其中 pfa的Dist数组保存最少删多少边能到达某个点 
	*/
	int left=0,right=1000005;
	while (left<right)
	{
		int mid=(left+right) >> 1;
		if (spfa(mid)) right=mid;else
					   left=mid+1;
	}
	if (left==1000005) printf("-1\n"); else	printf("%d",left);
}
