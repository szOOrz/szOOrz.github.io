#include<bits/stdc++.h>
using namespace std;
struct Point{
	int x,y,d;
	Point(int _x = 0,int _y = 0,int _d = 0){
		x = _x;
		y = _y;
		d = _d; 
	}
	bool operator <(const Point &x)const{
		return d > x.d;
	}
};
priority_queue<Point> q;
int front,rear;
int dist[4][1005][1005];
int Ans,n,m;
int a[1005][1005];
const int tx[4] = {0,0,1,-1};
const int ty[4] = {1,-1,0,0};
void Get(int c){
	int x,y,_x,_y,d,_d;
	memset(dist[c-'0'],-1,sizeof(dist[c - '0']));
	front = rear = 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j] == c){
				dist[c-'0'][i][j] = 0;
				q.push(Point(i,j,0));
			}
		}
	}
	while (!q.empty()){
		x = q.top().x;
		y = q.top().y;
		d = dist[c-'0'][x][y];
		q.pop();
		for (int t=0;t<4;t++){
			_x = x + tx[t];
			_y = y + ty[t];
			if (a[_x][_y] == '#') continue;   else
			if (a[_x][_y] == '.') _d = d + 1; else
								  _d = d + 0;
			if (dist[c-'0'][_x][_y] == -1){
				dist[c-'0'][_x][_y] = _d;
				q.push(Point(_x,_y,_d));
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) a[i][0] = a[i][m+1] = '#';
	for (int i=1;i<=m;i++) a[0][i] = a[n+1][i] = '#';
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j] = getchar();
			while((a[i][j]!='1')&&(a[i][j]!='2')&&(a[i][j]!='3')&&(a[i][j]!='.') && (a[i][j]!='#'))
				a[i][j] = getchar();
		}
	}
	Get('1');
	Get('2');
	Get('3');
	Ans = -1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (dist[1][i][j] == -1) continue;
			if (dist[2][i][j] == -1) continue;
			if (dist[3][i][j] == -1) continue;
			int Rec = dist[1][i][j] + dist[2][i][j] + dist[3][i][j];
			if (a[i][j] == '.') Rec-=2;
			if (Ans == -1 || Ans > Rec){
				Ans = Rec;
			}
		}
	}
	printf("%d\n",Ans);
}
