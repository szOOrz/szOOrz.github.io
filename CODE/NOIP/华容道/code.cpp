#include<bits/stdc++.h> 
#define up 0 
#define down 1
#define left 2  
#define right 3  
#define maxn 35
#define inf 0x3f3f3f3f  
struct node{
	int x,y,k;
	void node(int x=0,int y=0,int k=0){
		this -> x = x;
		this -> y = y;
		this -> k = k;
	}
}t1,t2;

node go(node n, int k)  
{  
    node t=n;  
    if(k == up)t.x--;  
    if(k == down)t.x++;  
    if(k == left)t.y--;  
    if(k == right)t.y++;  
    return t;  
}  

using namespace std;

node q[maxn * maxn];
int bfs(node s, node t){
	if(a[s.x][s.y]==0 || a[s.x][s.y]==0)return inf;
	memset(dist,0x3f,sizeof(dist));
	dist[s.x][s.y] = 0;
	front = rear = 0;
	q[rear] . x = s.x;
	q[rear] . y = s.y;
	rear++;
	while (front < rear){
		x = q[front].x;
		y = q[front].y;
		front++;
		for (int d=0;d<4;d++) {
			_x = x + dx[d];
			_y = y + dy[d];
			if ((a[_x][_y] != 0) && (dist[_x][_y]>m*n)){
				dist[_x][_y] = dist[x][y] + 1;
				q[rear] . x = _x;
				q[rear] . y = _y;
				rear++;
			}
		}
	}
	return dist[t.x][t.y];
}  

void init(){
	for(i=1;i<=n;i++)  
		for(j=1;j<=m;j++){  
			if(a[i][j]==0)continue;  
			a[i][j]=0;   
			for(k=0;k<=3;k++){  
				for(h=0;h<=3;h++){
					if(h<k){
						move[i][j][k][h]=move[i][j][h][k];  
						continue;  
                    }  
					t1=go((node){i,j},k);  
					t2=go((node){i,j},h);  
					if(pan[t1.x][t1.y]==0 || pan[t2.x][t2.y]==0)continue;  
					move[i][j][k][h]=bfs(t1,t2)+1;
				}
			}
            a[i][j]=1;  
        }  
}
int solve(){
	//考虑首先把空格移动到应该移动到的位置
	memset(dist,0x3f,sizeof(dist));
	front = rear = 0;
	q[rear] .x = ex;
	q[rear] .y = ey;
	rear++;
	dist[ex][ey] = 0;
	a[ex][ey] = 0; 
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		front++;
		for (int d = 0;d < 4; d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((a[_x][_y]) && (dist[_x][_y] > n*m)){
				dist[_x][_y] = dist[x][y] + 1;
				q[rear] . x = x;
				q[rear] . y = y;
				rear++;
			}
		}
	}
	a[ex][ey] = 1;
	//先移动
	memset(Dis,0x3f,sizeof(Dis));
	front = rear = 0;
	for (int d=0;d<4;d++){
		if (a[sx + dx[d]][sy + dy[d]] == 0) continue;
		Dis[sx][sy][up] = dist[sx + dx[d]][sy + dy[d]];
		q[rear] . x = sx;
		q[rear] . y = sy;
		q[rear] . k = d;
		rear++;
	}
	//加入初始状态 
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		k = q[front] . k;
		//可以把空格和当前位置交换 
		_x = x + dx[k];
		_y = y + dy[k];
		_k = k ^ 1;
		if (Dis[_x][_y][_k] > n*m){
			Dis[_x][_y][_k] = Dis[x][y][k]+1;
			q[rear] . x = _x;
			q[rear] . y = _y;
			q[rear] . k = _k;
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	init();
	for (int i=1;i<=q;i++){
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
	}
}
