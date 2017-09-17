#include<bits/stdc++.h>
#define lowbit(x) ((x & (-x)))
using namespace std;
const int maxn = 100010;
struct Point{
	int x,y,id;
	Point(int _x = 0,int _y = 0,int _id = 0){
		x = _x;
		y = _y;
		id= _id;
	}
	bool operator < (const Point &a) const{
		return y < a.y || y == a.y && id < a.id;
	}
};
map<int,int> mat;
set<Point> tree[maxn * 2];
int n,m;
vector<int> query(int x,int y){
	vector<int> tmp;
	tmp.clear();
	for (;x>0;x-=lowbit(x)){
		set<Point>::iterator last = tree[x].upper_bound(Point(0,y,maxn));
//		printf("tree[%d].upper_bound(%d,%d,%d) = [%d]\n",x,0,y,0,last);
		set<Point>::iterator iter;
		for (iter=tree[x].begin();iter!=last;iter++){
			tmp.push_back(iter -> id);
//			printf("ITER = %d ",iter);
//			printf("(%d___%d\n",iter -> y,iter -> id);
		}
		tree[x] . erase(tree[x].begin(),last);
	}
	return tmp;
}
void Add(int x,Point val){
	for (;x<=m;x+=lowbit(x)){
//		printf("tree[%d].insert[%d,%d]\n",x,val.y,val.id);
		tree[x].insert(val);
	}
}
int dist[maxn],fa[maxn];
int a[maxn],b[maxn],c[maxn],d[maxn];
bool vis[maxn * 2];
void bfs(){
	memset(fa,-1,sizeof(fa));
	memset(dist,-1,sizeof(dist));
	memset(vis,false,sizeof(vis));
	int q[maxn],front,rear;
	front = rear = 0;
	
	vector<int> u = query(mat[0],0);
	for (int i=0;i<(int)u.size();i++){
//		printf("Add %d\n",u[i]);
		q[rear++] = u[i];
		vis[u[i]] = true;
		dist[u[i]] = 1;
	}
	while (front < rear){
		int id = q[front++];
//		printf("%d\n",id);
		vector<int> v = query(mat[c[id]],d[id]);
		for (int i=0;i<(int)v.size();i++){
			if (vis[v[i]]) continue;
//			printf("----%d\n",v[i]);
			vis[v[i]] = true;
			dist[v[i]] = dist[id] + 1;
			fa[v[i]] = id;
			q[rear++] = v[i];
		}
	}
}
void write(int u){
	if (u == -1) return;
	write(fa[u]);
	printf("%d ",u+1);
}
vector<int> vx;
int main(){
	scanf("%d",&n);
	vx.clear();
	for (int i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		vx.push_back(a[i]);
		vx.push_back(c[i]);
		//°ÑxÀëÉ¢»¯ 
	}
	sort(vx.begin(),vx.end());
	m = 0;
	for (int i=0;i<(int)vx.size();i++){
		if ((i == 0) || (vx[i]!=vx[i-1])){
			mat[vx[i]] = ++m;
		}
	}
	for (int i=1;i<=m;i++) tree[i].clear();
	for (int i=0;i<n;i++) Add(mat[a[i]],Point(a[i],b[i],i));
	bfs();
	printf("%d\n",dist[n-1]);
	if (dist[n-1] == -1) return 0;
	write(n-1);
	puts("");
	return 0;
} 
