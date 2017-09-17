/*
ID:cqz15311
PROG:maze1
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
/*
反向BFS2次 
*/

using std::min;
using std::max;
int dist[105][105];
int w,h,map[105][105][5],ans;
struct Q{
	int x[105*105],y[105*105],step[105*105];
	int front,rear;
	void clear()
	{
		front=0;rear=0;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
	}
	bool empty()
	{
		return front>=rear;
	}
	void push(int a,int b,int t)
	{
		x[rear]=a;
		y[rear]=b;
		step[rear]=t;
		dist[a][b]=t;
		rear++;
	}
	void pop()
	{
		front++;
	}
};
Q q;
bool check(int a,int b,int c)
{
	if ((1<=a) && (a<=h) && (1<=b) && (b<=w)) 
			if (dist[a][b]>c) return true; 
	return false;
}
void bfs(int sx,int sy)
{
	int X,Y,XX,YY,S;
	q.clear();
	q.push(sx,sy,1);
	while (!q.empty())
	{
		X=q.x[q.front];
		Y=q.y[q.front];
		S=q.step[q.front]+1;
		q.pop();
		if (map[X][Y][1]) 
		{
			XX=X;YY=Y-1;
			if (check(XX,YY,S)) q.push(XX,YY,S);
		}
		if (map[X][Y][2])
		{
			XX=X-1;YY=Y;
			if (check(XX,YY,S)) q.push(XX,YY,S);
		}
		if (map[X][Y][3])
		{
			XX=X;YY=Y+1;
			if (check(XX,YY,S)) q.push(XX,YY,S);
		
		}
		if (map[X][Y][4])
		{
			XX=X+1;YY=Y;
			if (check(XX,YY,S)) q.push(XX,YY,S);
		}
	}
}
int main()
{
	 freopen("maze1.in","r",stdin);
	 freopen("maze1.out","w",stdout);
	 scanf("%d%d",&w,&h);
//1:左 
//2:上 
//3:右 
//4:下 
	 memset(map,0,sizeof(map));
	 for (int i=1;i<=h+1;i++)
	 {
		 char ch='A';
		 while (ch!='+') ch=getchar();	
		 for (int j=1;j<=w;j++)
		 {
		 	ch=getchar();
		 	if (ch==' ') map[i-1][j][4]=1;
		 	if (ch==' ') map[i][j][2]=1;
		 	ch=getchar();
		 }
		 if (i==(h+1)) break;
		 ch=getchar();
		 for (int j=1;j<=w+1;j++)
		 {
		 	ch=getchar();
		 	if (ch==' ') map[i][j-1][3]=1;
		 	if (ch==' ') map[i][j][1]=1;
		 	ch=getchar();
		 }
	 }
	 //init
	 memset(dist,0x7F,sizeof(dist));
	 for (int i=1;i<=h;i++)
	 {
	 	if (map[i][1][1]==1) bfs(i,1);
	 	if (map[i][w][3]==1) bfs(i,w);
	 }
	 for (int i=2;i<=w-1;i++)
	 {
	 	if (map[1][i][2]==1) bfs(1,i);
	 	if (map[h][i][4]==1) bfs(h,i);
	 }
	 //find
	 
	 ans=0;
	 for (int i=1;i<=h;i++)
	 {
	 	for (int j=1;j<=w;j++)
	 	{
//	 		printf("%5d ",dist[i][j]);
			ans=max(ans,dist[i][j]);
	 	}
	 }
	 printf("%d\n",ans);
	 
	 fclose(stdin);
	 fclose(stdout);
	 return 0;
}
