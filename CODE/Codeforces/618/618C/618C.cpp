/*
给定n个点(xi,yi)。求一个三角形abc。
满足其他的点都在三角形以外。
输出任意一个三角形三个点的下标。
可以证明一定存在解。
n<=100000
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
const int maxn = 100009;
struct Point{
	int x,y,id;
	bool operator < (const Point &t) const{
		return (x < t.x) || (x == t.x) && (y<t.y);
	}
}p[maxn];

LL Cross(Point a,Point b,Point c){
	return 1LL * (a.x - c.x) * (b.y - c.y) - 1LL * (b.x - c.x) * (a.y - c.y);
}
bool on_line(Point a,Point b,Point c){
	if((Cross(a,b,c) == 0) ||
	   (Cross(b,a,c) == 0) ||
	   (Cross(a,c,b) == 0)) return true;
	return false;
}
int n;
int main(){
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
	}
	sort(p+1,p+1+n);
	int i = 3;
	while (on_line(p[1],p[2],p[i])) i++;
	printf("%d %d %d\n",p[1].id,p[2].id,p[i].id);
	return 0;
}
