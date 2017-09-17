//二分答案，枚举下界，然后BFS，时间复杂度100*110*100*log 110，远远不超
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
const int dx[4]={1,-1,0,0 };
const int dy[4]={0, 0,1,-1};
int x,y,n;
int a[105][105],lans,rans,mid; 
bool bfs(int minval,int maxval)
{
	bool flag[105][105];
	int qx[10505],qy[10505],front,rear;
	memset(flag,true,sizeof(flag));
	if ((a[1][1]<minval) || (a[1][1]>maxval)) return false;
	front=0;rear=1;
	qx[0]=1;qy[0]=1;
	flag[1][1]=false;
	while (front<rear)
	{
		for (int d=0;d<4;d++)
		{
			x=qx[front]+dx[d];
			y=qy[front]+dy[d];
			if ((x>=1) && (y>=1) && (x<=n) && (y<=n))
			if ((a[x][y]>=minval) && (a[x][y]<=maxval) && (flag[x][y]))
			{
				flag[x][y]=false;
				qx[rear]=x;
				qy[rear]=y;
				rear++;
			}
		}
		front++;
	}
	return (!flag[n][n]);
}
bool check(int cz)
{
	for (int i=0;i<=110;i++)
	{
		if (bfs(i,i+cz)) return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	lans=0;rans=111;
	while (lans<rans)
	{
		int mid=(lans+rans) >> 1;
		if (check(mid))
		{
			rans=mid;
		}
		else
		{
			lans=mid+1;
		}
	}
	printf("%d",lans);
	return 0;
} 
