#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 205000;
struct Point{
	LL x,y;
	bool operator < (const Point &r)const{
		return x < r.x || x == r.x && y < r.y;
	}
	
}a[maxn];
map<LL,LL> Mapx,Mapy;
map<Point,LL> Mapxy;
LL n,Ans;
int main(){
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
		Mapx[a[i].x]++;
		Mapy[a[i].y]++;
		Mapxy[a[i]] ++;
	}
	for (int i=1;i<=n;i++){
		Ans = Ans + (Mapx[a[i].x] * (Mapx[a[i].x]-1)) / 2;
		Mapx[a[i].x] = 0;
		Ans = Ans + (Mapy[a[i].y] * (Mapy[a[i].y]-1)) / 2;
		Mapy[a[i].y] = 0;
		Ans = Ans - (Mapxy[a[i]] * (Mapxy[a[i]]-1)) / 2;
		Mapxy[a[i]] = 0;
	}
	printf("%I64d\n",Ans);
	return 0;
}
