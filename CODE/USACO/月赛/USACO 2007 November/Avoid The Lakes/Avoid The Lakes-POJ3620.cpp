#include<iostream> 
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int n,m,k;
bool mark[200][200],flag[200][200];
int ans,cnt,front,rear,qx[150000],qy[150000];
bool check(int x,int y)
{
	return ((x>=1) && (x<=n) && (y>=1) && (y<=m) && flag[x][y] && mark[x][y]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			flag[i][j]=false;
	for (int i=1;i<=k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y) ;
		flag[x][y]=true;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			mark[i][j]=true;
	ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		if ((flag[i][j]) && (mark[i][j]))
		{
			front=0;
			rear=1;
			cnt=1;
			qx[0]=i;
			qy[0]=j;
			mark[i][j]=false;
			while (front<rear)
			{
				for (int d=0;d<4;d++)
				{
					int xx=qx[front]+dx[d];
					int yy=qy[front]+dy[d];
					//printf("%d %d %d\n",xx,yy,check(xx,yy));
					if (check(xx,yy))
					{
						qx[rear]=xx;
						qy[rear]=yy;
						mark[xx][yy]=false;
						cnt++;
						rear++;
					}
				}
				front++;
			}
			if (cnt>ans) ans=cnt;
//			for (int ta=1;ta<=n;ta++)
//			{
//				for (int tb=1;tb<=m;tb++) printf("%d",mark[ta][tb] && flag[ta][tb]);
//				printf("\n");
//			}
		}
	printf("%d",ans);
	return 0;
}
