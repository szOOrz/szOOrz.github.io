#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
bool vis[maxn][maxn];
int qx[maxn*maxn],qy[maxn*maxn],front,rear;
int vx[maxn*maxn],vy[maxn*maxn],Ans[maxn][maxn];
char a[maxn][maxn];
int n,m,K;
 
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j] = getchar();
			while (a[i][j]!='*' && a[i][j]!='.') a[i][j] = getchar();
		}
	}
	memset(Ans,-1,sizeof(Ans));
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j] == '*' || Ans[i][j]!=-1) continue;
			
			int Rec = 0;
			vx[0] = 0;
			front = rear = 0;
			qx[rear] = i;qy[rear] = j;rear++;
			vx[++vx[0]] = i;vy[vx[0]] = j;
			vis[i][j] = true;

			int x,y,_x,_y;
			while (front < rear){
				x = qx[front];y = qy[front];front++;
				for (int d = 0;d<4;d++){
					_x = x + dx[d];
					_y = y + dy[d];
					//if (_x<=0 || _y<=0 || _x>=n || _y>=m)
					if (a[_x][_y] == '*'){
						Rec++;
					} else{
						if (!vis[_x][_y]){
							qx[rear] = _x;
							qy[rear] = _y;
							rear++;
							vx[++vx[0]] = _x;
							vy[vx[0]] = _y;
							vis[_x][_y] = true;
						}
					}
				}
			}
			for (int k=1;k<=vx[0];k++){
//				printf("(%d,%d):",vx[k],vy[k]);
				Ans[vx[k]][vy[k]] = Rec;
			}
//			puts("");
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++){
//			printf("%5d",Ans[i][j]);
//		} 
//		puts("");
//	}
	while (K--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",Ans[a][b]);
	}
	return 0;

}
/*
5 6 3
******
*..*.*
***.**
*....*
******
*/
