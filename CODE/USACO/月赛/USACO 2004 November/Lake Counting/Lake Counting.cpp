#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

int n,m,ans;
char ch[500][500];
const int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};
bool flag[500][500];
inline void dfs(int i,int j)
{
	int xx,yy,k;
	for (int k=0;k<8;k++)
	{
		xx=i+dx[k];
		yy=j+dy[k];
		   if  ((xx>=0) and (xx<n) and (yy>=0) and (yy<m))
		   {
				if ((ch[xx][yy]=='W') and (flag[xx][yy]))
				{
					flag[xx][yy]=false;
					dfs(xx,yy);
				}
		   }
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%s",ch[i]);
	
	}
	
	ans=0;
	memset(flag,true,sizeof(flag));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		if ((flag[i][j]) and (ch[i][j]=='W'))
		{
			flag[i][j]=false;
			dfs(i,j);
			ans++;
		}
	printf("%d",ans);
	return 0;
}
