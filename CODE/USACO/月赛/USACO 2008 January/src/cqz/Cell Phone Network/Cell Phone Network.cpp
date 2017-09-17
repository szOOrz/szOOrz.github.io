#include<iostream>
#include<cmath>
using namespace std;
const int oo=10005;
int dp[10005][4],mark[10005];
struct E{
	int from,to,next;
}edge[20005];
int cnt,point[10005],n,a,b;
void add_edge(int a,int b)
{
	edge[cnt].from=a;
	edge[cnt].to=b;
	edge[cnt].next=point[a];
	point[a]=cnt;
	cnt++;
}
void dfs(int i)
{
	int c,k;
	bool flag;
	int e=point[i];
	while (e!=-1)
	{
		c=edge[e].to;
		if (mark[c]==-1)
		{
			mark[c]=i;
			dfs(c);
		}
		e=edge[e].next;
	}	//让他的子节点先处理完 
	e=point[i];
	dp[i][1]=0;
	dp[i][2]=0;
	dp[i][3]=0;
	flag=false;
	while (e!=-1)
	{
		c=edge[e].to;
		if (mark[c]==i)
		{
			dp[i][1]+=min(dp[c][1],min(dp[c][2],dp[c][3]));
			flag=flag || (dp[c][1]<=dp[c][2]);
			dp[i][2]+=min(dp[c][1],dp[c][2]);
			dp[i][3]+=dp[c][2];
		}
		e=edge[e].next;
	}
	if (!flag)
	{
		//dp[i][2]得找一个dp[c][1]
		e=point[i];
		k=oo;
		while (e!=-1) 
		{
			c=edge[e].to;
			if (mark[c]==i)
			{
				k=min(k,dp[c][1]-dp[c][2]);
			}
			e=edge[e].next;
		}
		dp[i][2]+=k;
	}
	dp[i][1]++;
//	printf("dp[%d] 1:%d 2:%d 3:%d  %d\n",i,dp[i][1],dp[i][2],dp[i][3],flag);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) point[i]=-1;
	cnt=0;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add_edge(a,b);
		add_edge(b,a);//建立双向边，因为不知道哪个是跟 
	} 
	for (int i=1;i<=n;i++) mark[i]=-1;
	mark[1]=0;
	dfs(1);
	printf("%d",min(dp[1][1],dp[1][2]));
	return 0;
} 
