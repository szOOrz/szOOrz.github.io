#include<bits/stdc++.h>
double pi = acos(-1.0); 
using namespace std;
const int maxn = 1050000;
struct Point{
	double x,y;
}p[maxn];
double Cross(Point a,Point b){
	return a.x * b.y - b.x * a.y;
}
double dis(Point a,Point b){
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*((a.y-b.y)*(a.y-b.y)));
}
double dot(Point a,Point b,Point c){
	return (a.x-c.x)*(b.x-c.x)+(a.y-c.y)*(b.y-c.y);
}

bool check(Point a,Point b){
//	if (dot(a,b,p[0]) < 0) return false;
	if (dot(a,p[0],b) < 0) return false;
	if (dot(b,p[0],a) < 0) return false;
	return true;
}

int n;
double px,py;
double Min,Max; 
int main(){
	scanf("%d%lf%lf",&n,&px,&py);
	p[0].x = p[0].y = 0;
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].x-=px;
		p[i].y-=py;
	}
	Min = 1e80;
	Max =-1e80;
	for (int i=1;i<=n;i++){
		Min = min(Min,dis(p[0],p[i]));
		Max = max(Max,dis(p[0],p[i]));
	}
	for (int i=1;i<=n-1;i++){
		if (check(p[i],p[i+1])){
			Min = min(Min,fabs(1.0 * Cross(p[i],p[i+1]) / dis(p[i],p[i+1])));
		}
	}
	if (check(p[n],p[1])){
		Min = min(Min,fabs(1.0 * Cross(p[n],p[1]) / dis(p[n],p[1])));
	}
	printf("%.10lf\n",pi*(Max*Max-Min*Min));
}
/*
3 0 0
-1 1
0 3
1 1
*/
