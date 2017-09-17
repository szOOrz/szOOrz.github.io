/*
ID:cqz15311
LANG:C++
PROG:camelot
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct P{
	int x,y;
}king,knight[32*32],q[32*32*2];

const int dx[8] = { 1, 2, 1, 2,-1,-2,-1,-2};
const int dy[8] = { 2, 1,-2,-1, 2, 1,-2,-1};
const int kwx[17] = {-2,-1,0,1,2,0,0, 0, 0,1,1,-1,-1,-2,-2,2, 2};
const int kwy[17] = { 0, 0,0,0,0,1,2,-1,-2,-1,1,-1,1, 2,-2,2,-2};
int dist[32][32][32][32];

int R,C,n;
int _x,_y,_xx,_yy;
int Ans;

using namespace std;
int main(){
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	scanf("%d%d",&C,&R);//这里不要看，一开始把R和C弄反了，为了方便就不改了 
	getchar();
	scanf("%c%d",&king.x,&king.y);
	king.x -= ('A'-1);
	n = 1;
	getchar();
	while (~scanf("%c%d",&knight[n].x,&knight[n].y)){
		knight[n].x-=('A'-1);
		++n;
		getchar();
	}
	--n;
	memset(dist,-1,sizeof(dist));
	for (int x=1;x<=R;x++){
		for (int y=1;y<=C;y++){
			int front,rear;
			front = rear = 0; 
			q[rear] . x = x;
			q[rear] . y = y;
			rear++;
			dist[x][y][x][y] = 0;
			while (front < rear){
				_x = q[front] . x;
				_y = q[front] . y;
				front ++;
				for (int d=0;d<8;d++){
					_xx = _x + dx[d];
					_yy = _y + dy[d];
					if ((_xx >= 1) && (_yy >= 1) && (_xx <= R) && (_yy <= C)){
						if (dist[x][y][_xx][_yy] == -1) {
							dist[x][y][_xx][_yy] = dist[x][y][_x][_y] + 1;
							q[rear] . x = _xx;
							q[rear] . y = _yy;
							rear++;
//							printf("(%d,%d,%d,%d):%d\n",x,y,_xx,_yy,dist[x][y][_xx][_yy]);
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=R;i++){
		for (int j=1;j<=C;j++){
			for (int k=1;k<=R;k++){
				for (int l=1;l<=C;l++){
					if (dist[i][j][k][l] == -1)
						dist[i][j][k][l] = 0x3fffff;
				}
			}
		}
	}
//被这个数据坑了：
/*
2 26
A 1
Y 1
不是所有位置都能到达. 
*/ 
	Ans = 0x3fffffff;
	for (int d = 0;d<17;d++){
		//枚举国王可能先走的位置 
		_x = king.x + kwx[d];
		_y = king.y + kwy[d];
		if ((_x >= 1) && (_y >= 1) && (_x <= R) && (_y <= C)){
			for (int tx = 1;tx <= R;tx ++){
				for (int ty = 1;ty <= C;ty++){
					//枚举终点 
					int Tot = 0; 
					for (int i = 1;i<=n;i++){
						Tot += dist[knight[i].x][knight[i].y][tx][ty];
					}
					int Rec = Tot + max(abs(king.x - tx) , abs(king.y - ty));
					//可能国王自己走 
					for (int i=1;i<=n;i++){
						Rec = min(Rec,Tot - dist[knight[i].x][knight[i].y][tx][ty] +
										  	dist[knight[i].x][knight[i].y][_x][_y] +
										  	(max(abs(kwx[d]) , abs(kwy[d])))			   +
										    dist[_x][_y][tx][ty]);
					}
					
					Ans = min(Ans,Rec);
				}
			}
		}
	}
	printf("%d\n",Ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
USER: Jack Chen [cqz15311]
TASK: camelot
LANG: C++

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 8300 KB]
   Test 2: TEST OK [0.000 secs, 8300 KB]
   Test 3: TEST OK [0.000 secs, 8300 KB]
   Test 4: TEST OK [0.014 secs, 8300 KB]
   Test 5: TEST OK [0.070 secs, 8300 KB]
   Test 6: TEST OK [0.112 secs, 8300 KB]
   Test 7: TEST OK [0.000 secs, 8300 KB]
   Test 8: TEST OK [0.000 secs, 8300 KB]
   Test 9: TEST OK [0.042 secs, 8300 KB]
   Test 10: TEST OK [0.196 secs, 8300 KB]
   Test 11: TEST OK [0.000 secs, 8300 KB]
   Test 12: TEST OK [0.000 secs, 8300 KB]
   Test 13: TEST OK [0.000 secs, 8300 KB]
   Test 14: TEST OK [0.000 secs, 8300 KB]
   Test 15: TEST OK [0.000 secs, 8300 KB]
   Test 16: TEST OK [0.000 secs, 8300 KB]
   Test 17: TEST OK [0.000 secs, 8300 KB]
   Test 18: TEST OK [0.000 secs, 8300 KB]
   Test 19: TEST OK [0.000 secs, 8300 KB]
   Test 20: TEST OK [0.000 secs, 8300 KB]

All tests OK.
*/ 
