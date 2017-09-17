#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
/*
输入n*m的方格，有*和.组成，
输出n*m的矩阵，如果str[i][j] = '.'直接输出'.'，
如果str[i][j] = '*'，则假设str[i][j]='.'，
上下左右四个方向相连的'.'的个数
*/
int n,m;
const int maxn = 1005;
char a[maxn][maxn];
int vis[maxn][maxn],cnt[maxn*maxn],num;
int qx[maxn*maxn],qy[maxn*maxn],front,rear;
int x,y,_x,_y;
int b[10];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	memset(vis,0,sizeof(vis));
	num = 0;
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (!vis[i][j] && a[i][j] == '.'){
				num++;
				front = rear = 0;
				qx[rear] = i;
				qy[rear] = j;
				vis[i][j] = num;
				rear++;
				while (front < rear){
					x = qx[front];
					y = qy[front];
					front++;
					for (int d=0;d<4;d++){
						_x = x + dx[d];
						_y = y + dy[d];
						if (_x<0||_x>=n||_y<0||_y>=m) continue;
						if (a[_x][_y]=='*'||vis[_x][_y])continue;
						vis[_x][_y] = num;
						qx[rear] = _x;
						qy[rear] = _y;
						rear++;
					}
				}
				cnt[num] = rear;
			}
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (a[i][j] == '.') putchar('.'); else{
				b[0] = 0;
				if (i-1>=0 && vis[i-1][j]!=0) b[++b[0]] = vis[i-1][j];
				if (j-1>=0 && vis[i][j-1]!=0) b[++b[0]] = vis[i][j-1];
				if (i+1<n  && vis[i+1][j]!=0)  b[++b[0]] = vis[i+1][j];
				if (j+1<m  && vis[i][j+1]!=0)  b[++b[0]] = vis[i][j+1];
				sort(b+1,b+1+b[0]);
				int Res = 0;
				for (int k=1;k<=b[0];k++)
					if (k == 1 || b[k]!=b[k-1])
						Res += cnt[b[k]];
				printf("%d",(Res+1) % 10);
			}
		}
		puts("");
	}
	return 0;
}
