/*
ID:cqz15311
PROG:castle
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
int mark[55][55],qx[55*55],qy[55*55],front,rear,a,b,m,n,x,cnt,val[55*55];
bool wall[55][55][4];
int sum;
int ans1,ans2,ans3,ans4_1,ans4_2;
char ans4_3;
void push(int a,int b,int num)
{
	if (mark[a][b]) return ;
	qx[rear]=a;
	qy[rear]=b;
	mark[a][b]=num;
	rear++;
}
int dx[4]={1,0,-1, 0};
int dy[4]={0,1, 0,-1};
int bfs(int sx,int sy,int num)
{
	front=rear=0;
	push(sx,sy,num);
	while (front<rear)
	{
		a=qx[front];b=qy[front];front++;
		for (int d=0;d<4;d++)
		{
			if (!wall[a][b][d])
			{
				push(a+dx[d],b+dy[d],num);
			}
		}
	}
	return rear;
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			wall[i][j][0]=(x >> 3) & 1;//南
			wall[i][j][1]=(x >> 2) & 1;//东
			wall[i][j][2]=(x >> 1) & 1;//北
			wall[i][j][3]=(x >> 0) & 1;//西 
		}
	}
	memset(mark,0,sizeof(mark));
	cnt=0;
	ans2=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (!mark[i][j]) 
			{
				cnt++;
				val[cnt]=bfs(i,j,cnt);
				ans2=max(ans2,val[cnt]);
			}
		}
	ans1=cnt;
	ans3=0;
	for (int j=1;j<=m;j++)
	{
		for (int i=n;i>=1;i--)
		{
			if (i-1>=1)
			if (mark[i-1][j]!=mark[i][j])
			{
				sum=val[mark[i-1][j]]+val[mark[i][j]];
				if (sum>ans3)
				{
					ans3=sum;
					ans4_1=i;
					ans4_2=j;
					ans4_3='N';
				}
			}
			if (j+1<=m)
			if (mark[i][j+1]!=mark[i][j])
			{
				sum=val[mark[i][j+1]]+val[mark[i][j]];
				if (sum>ans3)
				{
					ans3=sum;
					ans4_1=i;
					ans4_2=j;
					ans4_3='E';
				}
			}
		}
	}
	//for (int i=1;i<=n;i++)
	//{
	//	for (int j=1;j<=m;j++)
	//	{
	//		printf("%d ",mark[i][j]);
	//	}
	//	puts("");
	//}
	//for (int i=1;i<=cnt;i++) printf("%d\n",val[i]);
	printf("%d\n%d\n%d\n%d %d %c\n",ans1,ans2,ans3,ans4_1,ans4_2,ans4_3);
	return 0;
}
