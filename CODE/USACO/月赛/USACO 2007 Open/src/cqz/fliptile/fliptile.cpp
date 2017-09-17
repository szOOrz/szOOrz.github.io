#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
int b[20][20],c[20][20],num[20][20],ans[20][20];
int val[20];
int cnt,m,n,ans_cnt;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
void on(int x,int y)
{
	b[x][y]=b[x][y] ^ 1;
	c[x][y]=1;
	cnt++;
	for (int d=0;d<4;d++)
	{
		int xx=x+dx[d];
		int yy=y+dy[d];
		if ((xx>=1) && (yy>=1) && (xx<=m) && (xx<=n)) 
			b[xx][yy]=b[xx][yy] ^ 1;
	}
}
bool small()
{
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		if (ans[i][j]>c[i][j]) return true;else
		if (ans[i][j]<c[i][j]) return false; 
	}
	return false;
}
void slove()
{
	cnt=0;
	memset(c,0,sizeof(c));
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) 
			b[i][j]=num[i][j];
	for (int i=1;i<=n;i++)
		if (val[i]) on(1,i);
	for (int i=2;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (b[i-1][j]) on(i,j);
		}
	}
	bool flag=true;
	for (int i=1;i<=n;i++)
		if (b[m][i]) flag=false;
	//printf("%d %d %d\n",flag,cnt,ans_cnt);
	if (flag)
	{
		if (cnt<ans_cnt)
		{
			ans_cnt=cnt;
			for (int i=1;i<=m;i++)
				for (int j=1;j<=n;j++)
					ans[i][j]=c[i][j];
		}
		else
		if (cnt==ans_cnt)
		{
			if (small())//c的字典序小于ans的字典序 
			{
				for (int i=1;i<=m;i++)
					for (int j=1;j<=n;j++)
						ans[i][j]=c[i][j];
			}
		}
	}
}
void dfs(int i)
{
	if (i==n+1)
	{
		slove();
		return ;
	}
	val[i]=0;
	dfs(i+1);
	val[i]=1;
	dfs(i+1);
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&num[i][j]);
	memset(val,0,sizeof(val));
	ans_cnt=5000;
	dfs(1); 
	if (ans_cnt==5000) puts("IMPOSSIBLE"); else 
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
} 
