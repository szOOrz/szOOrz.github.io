#include<bits/stdc++.h> 
const int maxn = 111111;
double eps = 1e-8;
using namespace std;
typedef long long LL;
struct Point{
	int x,y;
	bool operator <(const Point &a) const{
		return x < a.x || x == a.x && y > a.y;
	}
}p1[maxn],p[maxn];
LL Cross(Point a,Point b,Point c){
	return (LL)(a.x - c.x) * (b.y - c.y) - (LL)(b.x - c.x) * (a.y - c.y);
}
int n,m;
int A,B;
void Tubao(){
	sort(p1+1,p1+1+n);
	m = 2;
	p[1] = p1[1];
	for (int i=2;i<=n;i++){
		while ((m >= 2) && (Cross(p1[i],p[m],p[m-1]) <= 0)) m--;
		p[++m] = p1[i];
	}
}
/*
6 1000000 999999
999999 1
999995 999994
999996 999996
999997 999995
999998 999997
1 999998

3 20 20
6 2
1 3
2 6
*/


bool check1(Point a,double Time,int A,int B){
	if ((a.x * Time - A >= -eps) && (a.y * Time - B >= -eps)) return true; else return false;
}
bool check2(Point a,Point b,double Time,int A,int B){
	if (Time * a.y - B < -eps) return false;
	if (Time * b.x - A < -eps) return false;
	double timeb = (1.0 * A - a.x * Time) / (b.x - a.x);
	double timea = Time - timeb;
	if ((timea < -eps) || (timeb < -eps)) return false;
	if (a.y * timea + b.y * timeb - B >= -eps) return true; else return false;
}
bool check(double Time){
	for (int i=1;i<=m;i++) if (check1(p[i],Time,A,B)) return true;
	for (int i=2;i<=m;i++) if (check2(p[i-1],p[i],Time,A,B)) return true;
	return false;
}
void solve(){
	double L,R;
	L = 0,R = A+B+10;
	while (R-L > 1e-10){
		double Mid = (L+R) / 2;
		if (check(Mid)){
			R = Mid;
		} else
			L = Mid;
	}
	printf("%.10lf\n",L);
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&p1[i].x,&p1[i].y);
	}
	Tubao();
	solve();
}
