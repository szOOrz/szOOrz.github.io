#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int maxn = 1e5+5;
const LL inf = 1e15;
LL n;
LL sqr(LL x){
	return x*x;
}
struct Point{
	LL x,y;
	bool operator < (const Point &t)const{
		return x < t.x || x == t.x && y < t.y;
	}
	Point(LL _x = 0,LL _y = 0){
		x = _x;
		y = _y;
	}
}U,D,L,R,p[maxn];
LL pre[maxn],suf[maxn];
LL Dis2(Point a,Point b){
	return sqr(a.x-b.x) + sqr(a.y-b.y);
}
LL Lmin[maxn],Lmax[maxn],Rmin[maxn],Rmax[maxn];
bool check(LL mid){
	LL l = 0,r = 1;
	while (++l <= n) {
		while (r+1 <= n && abs(p[r+1].x) <= abs(p[l].x) && sqr(p[r+1].x - p[l].x) <= mid) r++;
		while ((abs(p[r].x) > abs(p[l].x))) r--;
	//	printf("(%d,%d\n",l,r);
	//	printf("NEED1 = %I64d\n",sqr(p[l].x) + sqr(max(pre[l-1],suf[r+1])));
		if (sqr(p[l].x) + sqr(max(pre[l-1],suf[r+1])) > mid) continue;
	//	printf("NEED2 = %I64d\n",sqr(max(Lmax[l-1],Rmax[r+1]) - min(Lmin[l-1],Rmin[r+1])));
		if (sqr(max(Lmax[l-1],Rmax[r+1]) - min(Lmin[l-1],Rmin[r+1])) > mid) continue;
		return true;
	}
	l = n,r = n+1;
	while (--r >= 1){
		while (1 <= l-1 && abs(p[l-1].x) <= abs(p[r].x) && sqr(p[r].x - p[l-1].x) <= mid) l--; 
		while ((abs(p[r].x) < abs(p[l].x))) l++;
	//	printf("(%d,%d\n",l,r);
		if (sqr(p[r].x) + sqr(max(pre[l-1],suf[r+1])) > mid) continue;
		if (sqr(max(Lmax[l-1], Rmax[r+1]) - min(Lmin[l-1], Rmin[r+1])) > mid) continue;
		return true;
	}
	return false;
}
LL xmin,xmax,ymin,ymax;
int main(){
	scanf("%I64d",&n);
	xmin = ymin = inf;
	xmax = ymax = -inf;
	for (int i=1;i<=n;i++){
		LL a,b;
		scanf("%I64d%I64d",&a,&b);
		p[i].x = a;
		p[i].y = b;
		xmin = min(xmin,a);
		xmax = max(xmax,a);
		ymin = min(ymin,b);
		ymax = max(ymax,b);
	}
	sort(p+1,p+1+n);
	Lmin[0] = inf;
	Lmax[0] = -inf;
	for (int i=1;i<=n;i++){
		Lmin[i] = min(Lmin[i-1],p[i].y);
		Lmax[i] = max(Lmax[i-1],p[i].y);
		pre[i] = max(abs(Lmin[i]),abs(Lmax[i]));
	}
	Rmin[n+1] = inf;
	Rmax[n+1] = -inf;
	for (int i=n;i>=1;i--){
		Rmin[i] = min(Rmin[i+1],p[i].y);
		Rmax[i] = max(Rmax[i+1],p[i].y);
		suf[i] = max(abs(Rmin[i]),abs(Rmax[i]));
	}
	LL L,R;
	L = -1,R = max(sqr(xmax - xmin),sqr(ymax - ymin));
	while (L<R){
		LL mid=(L+R) >> 1;
	//	printf("%I64d  %I64d\n",L,R);
		if (check(mid)){
			R = mid;
		} else 
			L = mid+1;
	}
	printf("%I64d\n",min(L,min(sqr(xmax-xmin),sqr(ymax-ymin))));
}
