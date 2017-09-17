/*
ID:cqz15311
LANG:C++
PROG:starry 
*/
#include<bits/stdc++.h>
const int maxn = 105;
using namespace std;
const int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
const int dy[8] = {-1, 0, 1,-1,1,-1,0,1}; 
struct Q{
	int x,y;
	Q(int _x = 0,int _y = 0){
		x = _x;
		y = _y;
	}
}q[maxn*maxn];
char a[maxn][maxn];
bool vis[maxn][maxn];
int Ans[maxn][maxn];
int front,rear;
int W,H;
void floodfill(int sx,int sy){
	int x,y,_x,_y;
//	puts("");
	front = rear = 0;
	q[rear++] = Q(sx,sy);
	Ans[sx][sy] = -1;
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		front++;
		for (int d=0;d<8;d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((_x < 0) || (_y < 0) || (_x >= H) || (_y >= W) || (a[_x][_y] == 0) || Ans[_x][_y] == -1) continue;
			Ans[_x][_y] = -1;
			q[rear++] = Q(_x,_y);
		}
	}
}

const int P[5][5] = 
{{659 ,2017,4049,2017,659 },
 {2017,3169,3359,3169,2017},
 {4049,3359,1   ,3359,4049},
 {2017,3169,3359,3169,2017},
 {659 ,2017,4049,2017,659 }};
int Val(int x,int y){
	int ans = 0;
	for (int i=-2;i<=2;i++){
		for (int j=-2;j<=2;j++){
			if ((x + i < 0) || (x + i >= H) || (y + j < 0) || (y + j >= W))continue;
			if (Ans[x+i][y+j] == -1){
				ans = ans + P[i+2][j+2];
			}
		}
	}
	return ans;
}
int get_hash(int sx,int sy){
	int x,y,_x,_y;
	int rec = 0;
	front = rear = 0;
	q[rear++] = Q(sx,sy);
	vis[sx][sy] = true;
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		rec = rec + Val(x,y);
		front++;
		for (int d=0;d<8;d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((_x < 0) || (_y < 0) || (_x >= H) || (_y >= W)) continue;
			if (Ans[_x][_y] == -1 && !vis[_x][_y]){
				vis[_x][_y] = true;
				q[rear++] = Q(_x,_y);
			}
		}
	}
	return rec;
}
void Filled(int sx,int sy,int Addval){
	int x,y,_x,_y;
//	puts("");
	front = rear = 0;
	Ans[sx][sy] = Addval;
	q[rear++] = Q(sx,sy);
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		front++;
		for (int d=0;d<8;d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((_x < 0) || (_y < 0) || (_x >= H) || (_y >= W) || Ans[_x][_y] != -1) continue;
			Ans[_x][_y] = Addval;
			q[rear++] = Q(_x,_y);
		}
	}	
}
int Hash[28];
int find(int x){
	for (int i=1;i<=Hash[0];i++){
		if (x == Hash[i]) return i + 'a' - 1;
	}
	Hash[++Hash[0]] = x;
	return Hash[0] + 'a' - 1;
}

int main(){
	freopen("starry.in","r",stdin);
	freopen("starry.out","w",stdout);
	scanf("%d%d",&W,&H);
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			a[i][j] = getchar();
			while ((a[i][j] != '0') && (a[i][j]!='1')) a[i][j] = getchar();
			a[i][j] -= '0';
		}
	}
	memset(Hash,0,sizeof(Hash));
	memset(vis,false,sizeof(vis));
	memset(Ans,0,sizeof(Ans));
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (Ans[i][j] != 0 || a[i][j] == 0) continue;
			floodfill(i,j); //把当前联通块全部求出来，标记为-1
//			printf("[%d,%d\n",i,j);
			int Tmp = find(get_hash(i,j)); 
//			printf("%d\n",Tmp);
			Filled(i,j,Tmp);
//	printf("-----%d-----%d-----\n",H,W);
		}
	}
	
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (Ans[i][j] == 0) putchar('0'); else
							    printf("%c",Ans[i][j]);
		}
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
